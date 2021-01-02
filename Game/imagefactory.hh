#ifndef IMAGEFACTORY_HH
#define IMAGEFACTORY_HH

#include <QPixmap>
#include <map>

#include "gamescene.hh"

namespace student {

/**
 * @brief The imageFactory class handles images used in game
 *
 * Images are found from resources-folder
 * Uses config-file to set names to imagepaths
 */
class imageFactory
{
public:

    /**
     * @brief imageFactory constructor
     */
    imageFactory();

    /**
     * @brief getInstance
     * @returns imagefactory for use
     */
    static imageFactory &getInstance();

    /**
     * @brief initalizePixmaps add names and images to imageMap_
     */
    void initalizePixmaps();

    /**
     * @brief getImage
     * @param type is name of image
     * @returns the wanted image
     */
    QPixmap getImage(std::string type);

private:

    std::map<std::string, QPixmap> imageMap_;

};
}
#endif // IMAGEFACTORY_HH
