#include <string>
#include <QDebug>

#include "core/gameobject.h"
#include "gameeventhandler.hh"
#include "objectmanager.hh"
#include "player.hh"

namespace student {


GameEventHandler::GameEventHandler()
{
    turn_ = 1;
    round_ = 1;
}

GameEventHandler::~GameEventHandler()
{

}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    std::shared_ptr<Player> realPlayer = std::static_pointer_cast<Player>(player);
    for (auto iter : resources){
        realPlayer->addResources(iter.first, iter.second);
    }
}

void GameEventHandler::setNewPlayer(std::shared_ptr<Player> player, MapItem* Flag)
{
    if (playerInTurn_ == nullptr){
            playerInTurn_ = player;
    }
    playerMap_[player] = Flag;
}

void GameEventHandler::setMaxPLayerCount(int count)
{
    maxPlayerCount_ = count;
}

int GameEventHandler::getMaxPlayerCount()
{
    return maxPlayerCount_;
}

int GameEventHandler::getPlayerCount()
{
    return playerMap_.size();
}

void GameEventHandler::switchTurn()
{

    if (turn_ == maxPlayerCount_){
        turn_ = 1;
        round_ +=1;
    }
    else{
        turn_ += 1;
    }

    for (auto& iter:playerMap_){
        if (iter.first->getName() == std::to_string(turn_)){
            std::shared_ptr<Player> player = playerInTurn_;
            playerInTurn_ = iter.first;

            if (player->returnHQsituation() == false){
                deletePlayer(player);
            }
        }
    }
    for (int i : deads_){
        if (i == turn_){
            switchTurn();
        }
    }

    std::vector<std::shared_ptr<Course::GameObject>> objects = playerInTurn_->getObjects();
    for (std::shared_ptr<Course::GameObject> obj : objects){
        std::shared_ptr<Course::TileBase> tile = std::static_pointer_cast<Course::TileBase>(obj);
        tile->generateResources();
    }
}

int GameEventHandler::getPlayerTurn()
{
    return turn_;
}

void GameEventHandler::movePlayer(Course::Coordinate coord)
{
    MapItem* Flag = playerMap_.at(playerInTurn_);
    Course::Coordinate coord_now = Flag->getBoundObject()->getCoordinate();
    Flag->setNewCoordinate(coord);
}

int GameEventHandler::getRound()
{
    return round_;
}

void GameEventHandler::addBomb(std::shared_ptr<Bomb> bomb)
{
    bombVector_.push_back(bomb);
}

std::shared_ptr<student::Bomb> GameEventHandler::getBomb(int i)
{
    return bombVector_.at(i);
}

int GameEventHandler::getBombCount()
{
    return bombVector_.size();
}

void GameEventHandler::deleteBomb(std::shared_ptr<Bomb> bomb)
{
    for ( auto it = bombVector_.begin(); it != bombVector_.end(); ++it){
        if (*it == bomb){
            bombVector_.erase(it);
            return;
        }
    }
}

std::shared_ptr<Bomb> GameEventHandler::checkExpolsions()
{
    for (std::shared_ptr<Bomb> bomb : bombVector_){
        if (bomb->Explode(round_) == true){
            bomb->setTimer(0);
            return bomb;
        }
    }
    return nullptr;
}

Course::Coordinate GameEventHandler::getPlayerCoordinate()
{
    MapItem* Flag = playerMap_.at(playerInTurn_);
    Course::Coordinate coord_now = Flag->getBoundObject()->getCoordinate();
    return coord_now;
}

std::shared_ptr<Player> GameEventHandler::getPlayerInTurn()
{
    return playerInTurn_;
}

std::shared_ptr<Player> GameEventHandler::getPlayer(int i)
{
    for (auto iter : playerMap_){
        if(iter.first->getName() == std::to_string(i+1)){
            return iter.first;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Player> > GameEventHandler::getPlayers()
{
    std::vector<std::shared_ptr<Player>> players;
    for (auto iter : playerMap_){
        players.push_back(iter.first);
    }
    return players;
}

void GameEventHandler::deletePlayer(std::shared_ptr<Player> player)
{
    for (auto iter : playerMap_){
        if (iter.first == player){
            MapItem* flag = iter.second;
            delete flag;
            int i = std::stoi(player->getName());
            player->emptyResources();
            deads_.push_back(i);
            playerMap_.erase(iter.first);


        }
    }
}

std::shared_ptr<Player> GameEventHandler::checkIfEnd()
{
    if (playerMap_.size() == 1){
        std::map<std::shared_ptr<Player>, MapItem*>::iterator iter = playerMap_.begin();
        std::shared_ptr<Player> winner = iter->first;
        return winner;
    }
    else{
        return nullptr;
    }
}
}
