#include <QDebug>
#include <QPainter>

#include "mapitem.hh"
#include "imagefactory.hh"


namespace student {

std::map <std::string, QColor> MapItem::mapcolors_ = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size):
    gameobject_(obj), scenelocation_(gameobject_->getCoordinatePtr()->asQpoint()), size_(size)
{
    addNewColor(gameobject_->getType());
    numb_ = 0;
    type_ = "";
    owner_ = "";
}

QRectF MapItem::boundingRect() const
{
    return QRectF(scenelocation_ * size_, scenelocation_ * size_ + QPoint(size_, size_));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->setBrush(QBrush(mapcolors_.at(gameobject_->getType())));

    if ( gameobject_->getType() == "Forest" ){
        painter->drawRect(boundingRect());
    }
    if ( gameobject_->getType() == "Grassland"){
        painter->drawRect(boundingRect());
    }
    if (gameobject_->getType() == "Desert"){
        painter->drawRect(boundingRect());
    }
    if (gameobject_->getType() == "Lake"){
        painter->drawRect(boundingRect());
    }
    if (gameobject_->getType() == "Hill"){
        painter->drawRect(boundingRect());
    }

    if (imageName_ != ""){
        paintActor(painter);
    }
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return gameobject_;
}

void MapItem::updateLoc()
{
    if ( !gameobject_ ){
        delete this;
    } else {
        update(boundingRect());
        scenelocation_ = gameobject_->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    if(obj == gameobject_){
        return true;
    }
    else{
        return false;
    }
}

int MapItem::getSize() const
{
    return size_;
}

void MapItem::addImageName()
{
    imageName_ = this->getBoundObject()->getType();
    update();
}

void MapItem::addImageName(std::string name)
{
    imageName_ = name;
}

void MapItem::addImagePixmap(QPixmap pix)
{
    imagePixmap_ = pix;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        size_ = size;
    }

}

void MapItem::setNewCoordinate(Course::Coordinate coord)
{
    gameobject_->setCoordinate(coord);
    scenelocation_ = gameobject_->getCoordinatePtr()->asQpoint();
    update();

}

void MapItem::getNumb(unsigned int numb)
{
    numb_ = numb;
}

void MapItem::getType(std::string type)
{
    type_ = type;
}

void MapItem::setOwner()
{
    owner_ = gameobject_->getOwner()->getName();
    addImageName(owner_);
    addImagePixmap(imageFactory::getInstance().getImage(imageName_));
}

void MapItem::deleteOwner()
{
    owner_ = "";
    addImageName(owner_);
}



void MapItem::paintActor(QPainter *painter)
{

    if (type_ == "Building"){
        if (numb_ == 1){
            painter->drawPixmap(scenelocation_.x()*size_/*+size_/4*/,scenelocation_.y()*size_/*+size_/4*/,
                                size_/2.2, size_/2.2,
                                imagePixmap_);
        }
        else if (numb_ == 2){
            painter->drawPixmap(scenelocation_.x()*size_+size_/4,scenelocation_.y()*size_,
                                size_/2, size_/2,
                                imagePixmap_);
        }
        else if (numb_ == 3){
            painter->drawPixmap(scenelocation_.x()*size_+size_/2,scenelocation_.y()*size_,
                                size_/2, size_/2,
                                imagePixmap_);
        }
    }
    else if (type_ == "Worker"){
        if (numb_ == 1){
            painter->drawPixmap(scenelocation_.x()*size_/*+size_/4*/,scenelocation_.y()*size_+size_/2,
                                size_/2, size_/2,
                                imagePixmap_);
        }
        else if (numb_ == 2){
            painter->drawPixmap(scenelocation_.x()*size_+size_/4,scenelocation_.y()*size_+size_/2,
                                size_/2, size_/2,
                                imagePixmap_);
        }
        else if (numb_ == 3){
            painter->drawPixmap(scenelocation_.x()*size_+size_/2,scenelocation_.y()*size_+size_/2,
                                size_/2, size_/2,
                                imagePixmap_);
        }
    }
    else{
        if(owner_ != ""){
            painter->drawPixmap(scenelocation_.x()*size_+size_/4,scenelocation_.y()*size_+size_/4,
                                size_/2.5, size_/2.5,
                                imagePixmap_);
        }
        else{
            painter->drawPixmap(scenelocation_.x()*size_+size_/4,scenelocation_.y()*size_+size_/4,
                                size_/1.5, size_/1.5,
                                imagePixmap_);
        }
    }
}


void MapItem::addNewColor(std::string type)
{


    if (type == "Grassland"){
        if ( mapcolors_.find(type) == mapcolors_.end()){
             mapcolors_[type] = QColor(0,255,0);
    }

    }
    else if (type == "Forest"){
        if ( mapcolors_.find(type) == mapcolors_.end() ){
            mapcolors_[type]= QColor(0,150,0);
        }

    }
    else if (type == "Desert"){
        if ( mapcolors_.find(type) == mapcolors_.end() ){
            mapcolors_[type]= QColor(255,165,0);
        }

    }
    else if (type == "Lake"){
        if ( mapcolors_.find(type) == mapcolors_.end() ){
            mapcolors_[type]= QColor(0,165,255);
        }

    }
    else if (type == "Hill"){
        if ( mapcolors_.find(type) == mapcolors_.end() ){
            mapcolors_[type]= QColor(100,100,100);
        }
    }
    else {
        if ( mapcolors_.find(type) == mapcolors_.end() ){
             mapcolors_[type] = QColor(128,128,128);
        }
    }
}
}
