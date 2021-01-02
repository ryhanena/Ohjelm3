#ifndef GAMESCENE_HH
#define GAMESCENE_HH

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <memory>
#include <map>

#include "core/gameobject.h"
#include "buildings/buildingbase.h"
#include "tiles/tilebase.h"
#include "gameeventhandler.hh"
#include "mapitem.hh"

namespace student {

//Maplimits
const std::pair<int, int> LIMITS_WIDTH = {1,50};
const std::pair<int, int> LIMITS_HEIGHT = {1,50};
const std::pair<int, int> LIMITS_SCALE = {30,400};

/**
 * @brief The GameScene class handles the scene of game
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
     * @brief GameScene constructor
     * @param qt_parent
     * @param width
     * @param height
     * @param scale
     */
    GameScene(QWidget* qt_parent = nullptr,
              int width = 10,
              int height = 10,
              int scale = 50);
    ~GameScene() = default;

    /**
     * @brief setSize sets size of scene
     * @param width
     * @param height
     */
    void setSize(int width, int height);

    /**
     * @brief setScale sets scale
     * @param scale
     */
    void setScale(int scale);

    /**
     * @brief resize the map
     */
    void resize();

    /**
     * @brief getScale
     * @return the scale
     */
    int getScale() const;

    /**
     * @brief getSize
     * @return size of scene
     */
    std::pair<int, int> getSize() const;

    /**
     * @brief drawTile draws the QGraphigs object (MapItem) to scene
     * @param obj
     * adds tile to tileItemVector (itemMap_)
     */
    void drawTile( MapItem* obj);

    /**
     * @brief addTileOwner set ownership of tile
     * @param coordinate of tile
     */
    void addTileOwner(Course::Coordinate coord);

    /**
     * @brief resetTile deletes owner of tile
     * @param tile
     */
    void resetTile(std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief drawItem draws items to map like buildings
     * and workers
     * @param obj
     */
    void drawItem( MapItem* obj);

    /**
     * @brief removeItem from scene
     * @param obj
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief updateItem in scene
     * @param obj
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief event catches the clickevent inside the scene
     * @param event
     * @return
     */
    virtual bool event(QEvent *event) override;

signals:

    /**
     * @brief sendCoordinate
     * @param coord clicked
     */
    void sendCoordinate(Course::Coordinate coord);

private:


    QGraphicsItem* mapBoundRect_;
    std::map<Course::Coordinate, std::shared_ptr<MapItem>> itemMap_;
    std::shared_ptr<GameEventHandler> geHandler_;
    int width_;
    int height_;
    int scale_;
};
}
#endif // GAMESCENE_HH
