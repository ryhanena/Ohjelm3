#include "desert.hh"

namespace student {


Desert::Desert(const Course::Coordinate& location,
                 const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                 const std::shared_ptr<Course::iObjectManager>& objectmanager,
                 const unsigned int& max_build,
                 const unsigned int& max_work,
                 const Course::ResourceMap& production):
    Course::TileBase(location,
                     eventhandler,
                     objectmanager,
                     max_build,
                     max_work,
                     production)
//production)
//const Course::ResourceMap& production):

{
}

std::string Desert::getType() const
{
    return "Desert";
}

} //namespace Student
