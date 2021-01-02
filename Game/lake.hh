#ifndef LAKE_HH
#define LAKE_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace student {

/**
 * @brief The Lake class is only watertile on game
 *
 * can't include buildings, except bomb.
 * Can only be worked by fishers
 */
class Lake : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;

    Lake() = delete;

    /**
     * @brief Lake constructor
     * @param location
     * @param eventhandler
     * @param objectmanager
     * @param max_build
     * @param max_work
     * @param production
     */
    Lake(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 1,
         const unsigned int& max_work = 3,
         const Course::ResourceMap& production = ConstResourceMaps::LAKE_BP);

    virtual ~Lake() = default;

    /**
     * @brief getType of this tile
     * @return "Lake"
     */
    virtual std::string getType() const override;
};
}
#endif // LAKE_HH
