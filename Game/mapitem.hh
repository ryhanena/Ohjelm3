#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>
#include <memory>
#include <map>

#include "core/gameobject.h"

namespace student {

/**
 * @brief The MapItem class represents mapitems shown in the map
 *
 * Includes allways gameobject
 */
class MapItem : public QGraphicsItem
{
public:
    /**
     * @brief MapItem constructor
     * @param obj gameobject wanted to be shown
     * @param size of item
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    ~MapItem() = default;

    /**
     * @brief boundingRect
     * @returns the boundingrect of item
     */
    QRectF boundingRect() const override;

    /**
     * @brief paint is called when game needs to be updatet
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    /**
     * @brief getBoundObject
     * @returns the gameobjet of This
     */
    const std::shared_ptr<Course::GameObject> &getBoundObject();

    /**
     * @brief updateLoc used for updating
     */
    void updateLoc();

    /**
     * @brief isSameObj checks if this's gameobject is same as param
     * @param obj other gameobject
     * @return boolean
     */
    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief getSize
     * @return size of object
     */
    int getSize() const;

    /**
     * @brief addImageName add image name using boundobject
     */
    void addImageName();

    /**
     * @brief addImageName add imagename using wanted name
     * @param name
     */
    void addImageName(std::string name);

    /**
     * @brief addImagePixmap add picture to item
     */
    void addImagePixmap(QPixmap);

    /**
     * @brief setSize set size of item
     * @param size
     */
    void setSize(int size);

    /**
     * @brief setNewCoordinate set new coordinate of item
     * Used for moving items in map
     * @param coord
     */
    void setNewCoordinate (Course::Coordinate coord);

    /**
     * @brief getNumb get number of buildings in tile under this
     * @param numb
     */
    void getNumb(unsigned int numb);

    /**
     * @brief getType get string type of item
     * @param type (building, worker, etc)
     */
    void getType(std::string type);

    /**
     * @brief setOwner of item
     */
    void setOwner();

    /**
     * @brief deleteOwner of item
     */
    void deleteOwner();


private:

    /**
     * @brief paintActor paints the image of item called by painter
     * got multiple options of size and location
     * usin size, numb and type
     */
    void paintActor(QPainter*);

    std::string owner_;
    const std::shared_ptr<Course::GameObject> gameobject_;
    QPoint scenelocation_;
    int size_;
    unsigned int numb_;
    std::string type_;
    static std::map<std::string, QColor> mapcolors_;
    static void addNewColor (std::string type);
    std::string imageName_;
    QPixmap imagePixmap_;


};
}
#endif // MAPITEM_HH
