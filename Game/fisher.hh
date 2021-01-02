#ifndef FISHER_HH
#define FISHER_HH

#include "workers/workerbase.h"
#include "core/resourcemaps.h"
#include "resourcemaps.hh"

namespace student {

/**
 * @brief The Fisher class represents fisher in the game
 *
 * Can only be placed on Lake, gives alot of food.
 */
class Fisher : public Course::WorkerBase
{
public:
    Fisher() =  delete;

    /**
     * @brief Fisher constructor
     * @param eventhandler
     * @param objectmanager
     * @param owner
     * @param tilespaces
     * @param cost
     * @param efficiency
     */
    Fisher(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
             const std::shared_ptr<Course::iObjectManager>& objectmanager,
             const std::shared_ptr<Course::PlayerBase>& owner,
             const int& tilespaces = 1,
             const Course::ResourceMap& cost =
                 ConstResourceMaps::FISHER_RECRUITMENT_COST,
             const Course::ResourceMapDouble& efficiency =
                 ConstResourceMaps::FISHER_EFFICIENCY);

    /**
     * @brief getType of worker
     * @return "Fisher"
     */
    virtual std::string getType() const override;

    /**
     * @brief canBePlacedOnTile
     * @param target
     * @return boolean
     */
    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @brief doSpecialAction
     */
    virtual void doSpecialAction() override;

    /**
     * @brief tileWorkAction
     * @return ResourceMapDouble
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;

};
}
#endif // FISHER_HH
