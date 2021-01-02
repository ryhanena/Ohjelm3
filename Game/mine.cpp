#include "mine.hh"

namespace student {


Mine::Mine(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces):
    BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces)
{
}

std::string Mine::getType() const
{
    return "Mine";
}
}
