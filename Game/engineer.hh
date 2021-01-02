#ifndef ENGINEER_HH
#define ENGINEER_HH

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace student {

/**
 * @brief The Engineer class represents engineer int the game.
 *
 * Engineer is better than regular worker but costs more,
 * can't be plased on water or desert. Typical engineer...
 */
class Engineer : public Course::WorkerBase
{
public:
    Engineer() = delete;

    /**
     * @brief Engineer constructor
     * @param eventhandler
     * @param objectmanager
     * @param owner
     * @param tilespaces
     * @param cost of engineer
     * @param efficiency of engineer
     */
    Engineer(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
             const std::shared_ptr<Course::iObjectManager>& objectmanager,
             const std::shared_ptr<Course::PlayerBase>& owner,
             const int& tilespaces = 1,
             const Course::ResourceMap& cost =
                 ConstResourceMaps::ENG_RECRUITMENT_COST,
             const Course::ResourceMapDouble& efficiency =
                 ConstResourceMaps::ENG_WORKER_EFFICIENCY);

    virtual ~Engineer() =  default;

    /**
     * @brief getType return name of this
     * @return "Engineer"
     */
    virtual std::string getType() const override;

    /**
     * @brief canBePlacedOnTile check if placeable
     * @param target
     * @return boolean
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    /**
     * @brief tileWorkAction handles the
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;
};
}
#endif // ENGINEER_HH
