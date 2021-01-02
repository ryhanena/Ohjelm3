#ifndef MINE_HH
#define MINE_HH

#include "buildings/buildingbase.h"

namespace student {
/**
 * @brief The Mine class is unique building
 * Mihin voi asettaa? Mitä tuottaa? Paljon maksaa?
 */
class Mine : public Course::BuildingBase
{
public:

    Mine() = delete;

    /**
     * @brief Mine constructor
     * @param eventhandler points to GeHandler
     * @param objectmanager point to ObjManager
     * @param owner
     * @param tilespaces
     */
    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1
            );

    virtual ~Mine() = default;

    /**
     * @brief getType
     * @returns type of building "Mine"
     */
    virtual std::string getType() const override;

}; //class

} //namespace
#endif // MINE_HH
