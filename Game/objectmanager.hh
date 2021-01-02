#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH

#include <map>
#include <memory>
#include <QObject>

#include "interfaces/iobjectmanager.h"
#include "core/gameobject.h"
#include "tiles/tilebase.h"
#include "workers/workerbase.h"

#include "mapitem.hh"
#include "gamescene.hh"
#include "gameeventhandler.hh"

namespace student {

//Enable_shared_from_this mahdollistaa tehdä luokasta suoraan shared pointerin
/**
 * @brief The ObjectManager class manages the objects used in game
 *
 */
class ObjectManager: public QObject, public Course::iObjectManager, public std::enable_shared_from_this<ObjectManager>
{
    Q_OBJECT

public:
    /**
     * @brief ObjectManager constructor
     * @param scene pointer
     * @param geHandler pointer
     */
    ObjectManager(std::shared_ptr<GameScene> scene = nullptr,
                  std::shared_ptr<GameEventHandler> geHandler = nullptr);

    virtual ~ObjectManager();

    /**
     * @brief f used when wanted to return shared this
     * @return shared_ptr this
     */
    std::shared_ptr<ObjectManager> f(){
        return shared_from_this();
    }

    /**
     * @brief setScale manually
     * @param scale
     */
    void setScale(int scale);

    /**
     * @brief addTiles adds empty tiles to gameScene
     * @param tiles from Course::worldGenerator
     */
    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles);

    /**
     * @brief buildingMaker used when making buildings to map
     * @param name
     * @param buildingInTile
     * @param tile
     * @return true if able to build it
     */
    bool buildingMaker(std::string name,
                       unsigned int buildingInTile, std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief setHQ sets the HeadQuarter at the beginning of the game
     * @param coord
     * @param player
     */
    void setHQ(Course::Coordinate coord, std::shared_ptr<Player> player);

    /**
     * @brief checkIfHQ checks if building is HQ
     * @param building
     */
    void checkIfHQ(std::shared_ptr<Course::BuildingBase> building);

    /**
     * @brief addWorker to tile
     * @param name
     * @param tile
     * @return true if able to add it
     */
    bool addWorker(std::string name, std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief setBomb and the timer
     * @param tile
     * @return true if able to set it
     */
    bool setBomb(std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief checkIfOutpost if there is other players outpost,
     * player can't move or build there
     * @param coord
     * @return true if there's outpost
     */
    bool checkIfOutpost(Course::Coordinate coord);

    /**
     * @brief createNewPlayer to game
     * @param playerNumb is number and the name of new player
     * @param mapsize
     */
    void createNewPlayer(int playerNumb, int mapsize);

    /**
     * @brief addImage to the MapItem
     * @param item wanted
     */
    void addImage(MapItem* item);

    /**
     * @brief clearTileBuilds clears buildings from tile
     * @param coord
     */
    void clearTileBuilds(Course::Coordinate coord);

    /**
     * @brief clearTileWorkers clears workers from tile
     * @param coord
     */
    void clearTileWorkers(Course::Coordinate coord);

    /**
     * @brief getTile
     * @param coordinate shared pointer
     * @return tile in coordinate
     */
    std::shared_ptr<Course::TileBase> getTile(const std::shared_ptr<Course::Coordinate> coordinate);

    /**
     * @brief getTile
     * @param coordinate raw pointer
     * @return tile in coordinate
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate);

    /**
     * @brief getTile
     * @param id of object
     * @return tile in coordinate
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id);

    /**
     * @brief getTiles
     * @param coordinates vector
     * @return vector of tiles in coordinates
     */
    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates);

    /**
     * @brief getNeigbours of tile
     * @param coordinate of tile
     * @return vector of tiles
     */
    std::vector<std::shared_ptr<Course::TileBase> > getNeigbours(const Course::Coordinate coordinate);

    /**
     * @brief checkIfPlaceableTile
     * @param coordinate
     * @return true if tile is placeable
     */
    bool checkIfPlaceableTile(const Course::Coordinate &coordinate);


private:
    int scale_;
    std::shared_ptr<GameEventHandler> geHandler_;
    std::vector<std::shared_ptr<Course::TileBase>> tiles_;
    std::vector<std::shared_ptr<Course::BuildingBase>> buildings_;
    std::vector<std::shared_ptr<Course::WorkerBase>> workers_;
    std::vector<MapItem*> items_;
    std::shared_ptr<GameScene> scene_;

};
}
#endif // OBJECTMANAGER_HH
