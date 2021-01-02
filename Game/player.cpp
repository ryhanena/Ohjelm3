#include "player.hh"

namespace student {

Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects,
               int money,
               int food,
               int wood,
               int stone,
               int ore
               ):
    Course::PlayerBase(name,
                       objects)

{
    addStartResources(money, food, wood, stone, ore);
    HQ_ = true;
}

void Player::addStartResources(int money, int food, int wood, int stone, int ore)
{
    money_ = money;
    food_ = food;
    wood_ = wood;
    stone_ = stone;
    ore_ = ore;
}

void Player::addResources(int type, int count)
{
    if (type == 1){
        money_ += count;
    }
    else if (type == 2){
        food_ += count;
    }
    else if (type == 3){
        wood_ += count;
    }
    else if (type == 4){
        stone_ += count;
    }
    else if (type == 5){
        ore_ += count;
    }
}

void Player::deleteResources(int type, int count)
{
    if (type == 1){
        money_ -= count;
    }
    else if (type == 2){
        food_ -= count;
    }
    else if (type == 3){
        wood_ -= count;
    }
    else if (type == 4){
        stone_ -= count;
    }
    else if (type == 5){
        ore_ -= count;
    }
}

void Player::emptyResources()
{
    money_ = 0;
    food_ = 0;
    wood_ = 0;
    stone_ = 0;
    ore_ = 0;
}

bool Player::isBuildable(int type, int count)
{
    if (type == 1){
        if (money_ - count < 0){
            return false;
        }
    }
    else if (type == 2){
        if (food_ - count < 0){
            return false;
        }
    }
    else if (type == 3){
        if (wood_ - count < 0){
            return false;
        }
    }
    else if (type == 4){
        if (stone_ - count < 0){
            return false;
        }
    }
    else if (type == 5){
        if (ore_ - count < 0){
            return false;
        }
    }
    return true;
}

int Player::getMoneyResource()
{
    return money_;
}

int Player::getFoodResource()
{
    return food_;
}

int Player::getWoodResource()
{
    return wood_;
}

int Player::getStoneResource()
{
    return stone_;
}

int Player::getOreResources()
{
    return ore_;
}

void Player::HQDestroied()
{
    HQ_ = false;
}

bool Player::returnHQsituation()
{
    return HQ_;
}

} //namespace
