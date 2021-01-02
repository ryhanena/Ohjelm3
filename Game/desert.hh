#ifndef Desert_HH
#define Desert_HH

#include "tiles/tilebase.h"
#include "resourcemaps.hh"


namespace student {

/**
 * @brief The Desert class represents Desert tile
 *
 * Can hold only one building, the Bomb
 * Can't be worked
 * Production is only 1 stone per turn
 */

class Desert : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;

    Desert() = delete;

    /**
     * @brief Desert constructor
     * @param location of tile
     * @param eventhandler points to GeHandler in use
     * @param objectmanager points to ObjManager in use
     * @param max_build
     * @param max_work
     */
    Desert(const Course::Coordinate& location,
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const unsigned int& max_build = 1,
            const unsigned int& max_work = 0,
            const Course::ResourceMap& production = ConstResourceMaps::DESERT_BP);


    virtual ~Desert() = default;

    /**
     * @brief getType
     * @return type of tile "Desert"
     */

    virtual std::string getType() const override;


};

}
#endif // Desert_HH
