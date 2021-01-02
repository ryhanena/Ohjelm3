#ifndef HILL_HH
#define HILL_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"

namespace student {

/**
 * @brief The Hill class represents hill- tile on the map
 *
 * generates ore and stone faster than other tiles
 * Holds two building and workers
 */
class Hill : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;
    Hill() = delete;

    /**
     * @brief Hill constructor
     * @param location
     * @param eventhandler
     * @param objectmanager
     * @param max_build
     * @param max_work
     * @param production
     */
    Hill(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 2,
         const unsigned int& max_work = 2,
         const Course::ResourceMap& production = ConstResourceMaps::HILL_BP);
    virtual ~Hill() = default;

    /**
     * @brief getType of this tile
     * @return "Hill"
     */
    virtual std::string getType() const override;
};
}
#endif // HILL_HH
