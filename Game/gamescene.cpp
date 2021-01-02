#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMainWindow>
#include <math.h>

#include "gamescene.hh"

namespace student {

GameScene::GameScene(QWidget *parent, int width, int height, int scale):
    QGraphicsScene(parent),
    mapBoundRect_(nullptr)

{
    setSize(width, height);
    setScale(scale);
}


void GameScene::setSize(int width, int height)
{
    if ( width >= LIMITS_WIDTH.first && width <= LIMITS_WIDTH.second )
    {
        width_ = width;
    }
    if ( height >= LIMITS_HEIGHT.first && height <= LIMITS_HEIGHT.second )
    {
        height_ = height;
    }
    resize();
}

void GameScene::setScale(int scale)
{
    if ( scale >= LIMITS_SCALE.first && scale <= LIMITS_SCALE.second )
    {
        scale_ = scale;
    }
    resize();
}

void GameScene::resize()
{
    if ( mapBoundRect_ != nullptr ){
        QGraphicsScene::removeItem(mapBoundRect_);
    }

    // Sets TopLeft corner as x = 0, y = 0
    // Calculates rect width (w*s) and height (h*s)
    QRect rect = QRect(0, 0, width_ * scale_ ,height_ * scale_);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);
    mapBoundRect_ = itemAt(rect.topLeft(), QTransform());
    mapBoundRect_->setZValue(-1);

}

int GameScene::getScale() const
{
    return scale_;
}

std::pair<int, int> GameScene::getSize() const
{
    return {width_, height_};
}

void GameScene::drawTile(MapItem* obj)
{
    Course::Coordinate coord = obj->getBoundObject()->getCoordinate();
    std::shared_ptr<MapItem> itemPtr (obj);
    itemMap_[coord] = itemPtr;
    addItem(obj);
}


void GameScene::addTileOwner(Course::Coordinate coord)
{
    for (auto iter : itemMap_){
        if (iter.first == coord){
            std::shared_ptr<MapItem> item = iter.second;
            item->setOwner();
        }
    }
}

void GameScene::resetTile(std::shared_ptr<Course::TileBase> tile)
{
    Course::Coordinate coord = tile->getCoordinate();
    for (auto iter : itemMap_){
        if (iter.first == coord){
            std::shared_ptr<MapItem> item = iter.second;
            item->deleteOwner();
        }
    }
}

void GameScene::drawItem(MapItem* obj)
{
    Course::Coordinate coord = obj->getBoundObject()->getCoordinate();
    addTileOwner(coord);
    addItem(obj);
}

void GameScene::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items(obj->getCoordinate().asQpoint());
    if ( items_list.size() == 1 ){
    } else {
        for ( auto item : items_list ){
            MapItem* mapitem = static_cast<MapItem*>(item);
            qDebug() << mapitem->getBoundObject()->ID;
            if ( mapitem->isSameObj(obj) ){

                delete mapitem;
            }
        }
    }

}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() == 1 ){
    } else {
        for ( auto item : items_list ){
            MapItem* mapItem = static_cast<MapItem*>(item);
            if (mapItem->isSameObj(obj)){
                mapItem->updateLoc();
            }
        }
    }
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / scale_;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * scale_, QTransform());

            if ( pressed == mapBoundRect_ ){
                qDebug() << "Click on map area.";
            }else{
                Course::Coordinate coord = static_cast<MapItem*>(pressed)->getBoundObject()->getCoordinate();
                emit sendCoordinate(coord);

                return true;
            }
        }
    }
    return QGraphicsScene::event(event);
}
}

