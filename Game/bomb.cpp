#include "bomb.hh"


namespace student {


Bomb::Bomb(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces
        ):
    BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces)

{
}

std::string Bomb::getType() const
{
    return "Bomb";
}

bool Bomb::Explode(int turn)
{
    if (explosionTurn_ == turn){
        return true;
    }
    else{
        return false;
    }
}

void Bomb::setTimer(int turn)
{
    if (turn != 0){
        explosionTurn_ = turn + 2;
    }
    else{
        explosionTurn_ = 0;
    }

}

} //namespace
