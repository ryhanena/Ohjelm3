#include <QDebug>
#include <memory>

#include "buildings/farm.h"
#include "buildings/headquarters.h"
#include "buildings/outpost.h"
#include "workers/basicworker.h"
#include "core/playerbase.h"
#include "core/coordinate.h"
#include "core/basicresources.h"
#include "core/resourcemaps.h"

#include "engineer.hh"
#include "fisher.hh"
#include "mine.hh"
#include "bomb.hh"
#include "imagefactory.hh"
#include "objectmanager.hh"
#include "player.hh"
#include "resourcemaps.hh"

namespace student {

ObjectManager::ObjectManager(std::shared_ptr<GameScene> scene, std::shared_ptr<GameEventHandler> geHandler)

{
    scene_ = scene;
    geHandler_ = geHandler;
    scale_ = scene_->getScale();
}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::setScale(int scale)
{
    scale_ = scale;
}


void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    for (std::shared_ptr<Course::TileBase> tile : tiles){
        tiles_.push_back(tile);
        MapItem* item = new MapItem(tile, scale_);
        scene_->drawTile(item);
    }
}


bool ObjectManager::buildingMaker(std::string name,
                                  unsigned int buildingsInTile, std::shared_ptr<Course::TileBase> tile)

{
    std::shared_ptr<Course::GameObject> obj = std::static_pointer_cast<Course::GameObject>(tile);
    std::shared_ptr<Player> player;
    if (!obj->getOwner()){
        player = geHandler_->getPlayerInTurn();
        obj->setOwner(player);
        player->addObject(obj);
    }
    else{
        player = std::static_pointer_cast<Player>(obj->getOwner());
    }

    if (name == "Farm"){
        Course::ResourceMap resources = Course::ConstResourceMaps::FARM_BUILD_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }

        std::shared_ptr<Course::Farm> Farm;
        Farm = std::make_shared<Course::Farm>(geHandler_,
                                               f(),
                                              player);
        buildings_.push_back(Farm);
        tile->addBuilding(Farm);

        MapItem* item = new MapItem(Farm, scale_);
        item->getType("Building");
        item->getNumb(buildingsInTile+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);

    }

    else if (name == "Outpost"){
        Course::ResourceMap resources = Course::ConstResourceMaps::OUTPOST_BUILD_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }
        std::shared_ptr<Course::Outpost> guard;
        guard = std::make_shared<Course::Outpost>(geHandler_,
                                                   f(),
                                                  player);
        buildings_.push_back(guard);
        tile->addBuilding(guard);

        MapItem* item = new MapItem(guard, scale_);
        item->getType("Building");
        item->getNumb(buildingsInTile+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);

    }
    else if (name == "Mine"){
        Course::ResourceMap resources = student::ConstResourceMaps::MINE_BUILD_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }
        std::shared_ptr<Mine> mine;
        mine = std::make_shared<Mine>(geHandler_,
                                           f(),
                                          player);
        buildings_.push_back(mine);
        tile->addBuilding(mine);

        MapItem* item = new MapItem(mine, scale_);
        item->getType("Building");
        item->getNumb(buildingsInTile+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);
    }
    return true;
}

void ObjectManager::setHQ(Course::Coordinate coord, std::shared_ptr<Player> player)
{

    std::shared_ptr<Course::TileBase> tile = getTile(coord);
    std::shared_ptr<Course::GameObject> obj = std::static_pointer_cast<Course::GameObject>(tile);

    std::shared_ptr<Course::HeadQuarters> HQ;
    HQ = std::make_shared<Course::HeadQuarters>(geHandler_,
                                                       f(),
                                                      player);
    buildings_.push_back(HQ);
    tile->addBuilding(HQ);

    MapItem* item = new MapItem(HQ, scale_);
    item->getType("Building");
    item->getNumb(1);
    addImage(item);

    obj->setOwner(player);
    player->addObject(obj);
    scene_->drawItem(item);
    items_.push_back(item);

}

void ObjectManager::checkIfHQ(std::shared_ptr<Course::BuildingBase> building)
{
    if (building->getType() == "HeadQuarters"){
        std::shared_ptr<Player> player = std::static_pointer_cast<Player>(building->getOwner());
        player->HQDestroied();
    }
}

bool ObjectManager::addWorker(std::string name, std::shared_ptr<Course::TileBase> tile)
{

    unsigned int workerCount = tile->getWorkerCount();
    std::shared_ptr<Course::GameObject> obj = std::static_pointer_cast<Course::GameObject>(tile);
    std::shared_ptr<Player> player;
    if (!obj->getOwner()){
        player = geHandler_->getPlayerInTurn();
        obj->setOwner(player);
        player->addObject(obj);
    }
    else{
        player = std::static_pointer_cast<Player>(obj->getOwner());
    }

    if (name == "BasicWorker"){
        Course::ResourceMap resources = Course::ConstResourceMaps::BW_RECRUITMENT_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }
        std::shared_ptr<Course::BasicWorker> worker;
        worker = std::make_shared<Course::BasicWorker>(geHandler_,
                                                       f(),
                                                       player);
        workers_.push_back(worker);
        tile->addWorker(worker);

        MapItem* item = new MapItem(worker, scale_);
        item->getType("Worker");
        item->getNumb(workerCount+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);

    }
    else if (name == "Engineer"){
        Course::ResourceMap resources = ConstResourceMaps::ENG_RECRUITMENT_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }
        std::shared_ptr<Engineer> worker;
        worker = std::make_shared<Engineer>(geHandler_,
                                                       f(),
                                                       player);
        workers_.push_back(worker);
        tile->addWorker(worker);

        MapItem* item = new MapItem(worker, scale_);
        item->getType("Worker");
        item->getNumb(workerCount+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);

    }
    else if (name == "Fisher"){
        Course::ResourceMap resources = ConstResourceMaps::FISHER_RECRUITMENT_COST;
        for (auto iter : resources){
            if(player->isBuildable(iter.first, iter.second)){

            }else{
                return false;
            }
        }
        for (auto iter : resources){
            player->deleteResources(iter.first, iter.second);
        }
        std::shared_ptr<Fisher> worker;
        worker = std::make_shared<Fisher>(geHandler_,
                                                       f(),
                                                       player);
        workers_.push_back(worker);
        tile->addWorker(worker);

        MapItem* item = new MapItem(worker, scale_);
        item->getType("Worker");
        item->getNumb(workerCount+1);
        addImage(item);
        scene_->drawItem(item);
        items_.push_back(item);
    }
    return true;
}

bool ObjectManager::setBomb(std::shared_ptr<Course::TileBase> tile)
{
    std::shared_ptr<Player> player = geHandler_->getPlayerInTurn();
    if (tile->getOwner()){
        return false;
    }

    std::shared_ptr<Course::GameObject> obj = std::static_pointer_cast<Course::GameObject>(tile);
    std::shared_ptr<Bomb> bomb;
    Course::ResourceMap resources = student::ConstResourceMaps::BOMB_BUILD_COST;
    for (auto iter : resources){
        if(player->isBuildable(iter.first, iter.second)){

        }else{
            return false;
        }
    }
    for (auto iter : resources){
        player->deleteResources(iter.first, iter.second);
    }
    bomb = std::make_shared<Bomb>(geHandler_,
                                               f(),
                                              player);
    buildings_.push_back(bomb);
    tile->addBuilding(bomb);

    bomb->setTimer(geHandler_->getRound());
    geHandler_->addBomb(bomb);

    MapItem* item = new MapItem(bomb, scale_);
    addImage(item);

    scene_->addItem(item);
    items_.push_back(item);
    player->addObject(obj);
    obj->setOwner(player);
    return true;
}

bool ObjectManager::checkIfOutpost(Course::Coordinate coord)
{
    for (auto building : buildings_){
        Course::Coordinate icoord = building->getCoordinate();
        if (icoord == coord){
            if (building->getType() == "Outpost"){
                if (building->getOwner()->getName() != geHandler_->getPlayerInTurn()->getName()){
                    return true;
                }
            }
        }
    }
    return false;
}

void ObjectManager::createNewPlayer(int playerNumb, int mapsize)
{
    std::shared_ptr<student::Player> Player;
    Player = std::make_shared<student::Player>(std::to_string(playerNumb+1));

    std::shared_ptr<Course::GameObject> Flag;
    Course::Coordinate coord = Course::Coordinate(mapsize, mapsize);


    if (playerNumb == 0){
        coord = Course::Coordinate(0,0);
        Flag = std::make_shared<Course::GameObject>(coord,
                                                    Player,
                                                    geHandler_,
                                                    f());
    }
    else if (playerNumb == 1){
        coord = Course::Coordinate(mapsize -1, mapsize-1);
        Flag = std::make_shared<Course::GameObject>(coord,
                                                    Player,
                                                    geHandler_,
                                                    f());
    }
    else if (playerNumb == 2){
        coord = Course::Coordinate(mapsize -1, 0);
        Flag = std::make_shared<Course::GameObject>(coord,
                                                    Player,
                                                    geHandler_,
                                                    f());
    }
    else if (playerNumb == 3){
        coord = Course::Coordinate(0, mapsize -1);
        Flag = std::make_shared<Course::GameObject>(coord,
                                                    Player,
                                                    geHandler_,
                                                    f());
    }
    else{return;}
    setHQ(coord, Player);

    MapItem *item = new MapItem(Flag, scale_);
    item->addImageName(std::to_string(playerNumb+1));
    item->addImagePixmap(imageFactory::getInstance().getImage(std::to_string(playerNumb+1)));
    scene_->addItem(item);
    geHandler_->setNewPlayer(Player, item);
}

void ObjectManager::addImage(MapItem *item)
{
    std::string imageName = item->getBoundObject()->getType();
    item->addImageName();
    item->addImagePixmap(imageFactory::getInstance().getImage(imageName));

}

void ObjectManager::clearTileBuilds(Course::Coordinate coord)
{
    std::shared_ptr<Course::TileBase> tile = getTile(coord);

    if (tile->getBuildingCount() > 0){
        for (std::shared_ptr<Course::BuildingBase> building : buildings_){
            Course::Coordinate icoord =
                    building->getCoordinate();
            if (icoord == coord){

                for (MapItem* item : items_){
                    std::shared_ptr<Course::GameObject> obj = item->getBoundObject();
                    if (obj->ID == building->ID){
                        for (auto it = items_.begin(); it != items_.end(); ++it){
                            if(*it == item){
                                items_.erase(it);
                                delete item;
                                break;
                            }
                        }
                        break;
                    }
                }
                for ( auto it = buildings_.begin(); it != buildings_.end(); ++it){
                    if (*it == building){
                        buildings_.erase(it);
                        tile->removeBuilding(building);
                        break;
                    }
                }
                checkIfHQ(building);
                return;
            }
    }
    }
}

void ObjectManager::clearTileWorkers(Course::Coordinate coord)
{
    std::shared_ptr<Course::TileBase> tile = getTile(coord);

    if (tile->getWorkerCount() > 0){
        for (std::shared_ptr<Course::WorkerBase> worker : workers_){
            Course::Coordinate icoord =
                    worker->getCoordinate();
            if (icoord == coord){

                for (MapItem* item : items_){
                    std::shared_ptr<Course::GameObject> obj = item->getBoundObject();
                    if (obj->getType() == worker->getType()){
                        for (auto it = items_.begin(); it != items_.end(); ++it){
                            if(*it == item){
                                items_.erase(it);
                                delete item;
                                break;
                            }
                        }
                        break;
                    }
                }
                for ( auto it = workers_.begin(); it != workers_.end(); ++it){
                    if (*it == worker){
                        workers_.erase(it);
                        tile->removeWorker(worker);
                        break;
                    }
                }
                return;
            }
    }
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const std::shared_ptr<Course::Coordinate> coordinate)
{
    for (std::shared_ptr<Course::TileBase> tile : tiles_){
        if (tile->getCoordinatePtr() == coordinate){
            return tile;
        }
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    for (std::shared_ptr<Course::TileBase> tile : tiles_){
        if (tile->getCoordinate() == coordinate){
            return tile;
        }
    }
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    for (std::shared_ptr<Course::TileBase> tile : tiles_){
        if (tile->ID == id){
            return tile;
        }
    }
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    std::pair<int, int> size = scene_->getSize();
    for (auto coordinate : coordinates){
        if (coordinate.x() >= 0 && coordinate.y() >= 0){
            if (coordinate.x() < size.first && coordinate.y() < size.second){
                tiles.push_back(getTile(coordinate));
            }
        }
    }
    return tiles;
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getNeigbours(const Course::Coordinate coordinate)
{
    std::vector<Course::Coordinate> neighbours = coordinate.neighbours();
    std::vector<std::shared_ptr<Course::TileBase>> placeableTiles = getTiles(neighbours);
    return placeableTiles;
}

bool ObjectManager::checkIfPlaceableTile(const Course::Coordinate &tried)
{

    std::vector<Course::Coordinate> neighbours = geHandler_->getPlayerCoordinate().neighbours();
    std::vector<std::shared_ptr<Course::TileBase>> placeableTiles = getTiles(neighbours);
    for (std::shared_ptr<Course::TileBase> tile : placeableTiles){
        if (tile == getTile(tried)){
            return true;
        }
    }
    return false;
}
}
