#include "imagefactory.hh"
#include "config.hh"


namespace student {


imageFactory::imageFactory()
{

}

imageFactory &imageFactory::getInstance()
{
    static imageFactory instance;
    return instance;
}

void imageFactory::initalizePixmaps()
{
    int i = 0;
    for (std::string path : imagePathVector){
        QPixmap pixmapitem(QString::fromStdString(path));
        imageMap_[picNameVector[i]] = pixmapitem;
        ++i;
    }
}

QPixmap imageFactory::getImage(std::string type)
{
    return imageMap_.at(type);
}
}
