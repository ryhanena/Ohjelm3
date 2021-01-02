#include <QString>
#include <QtTest>
#include "core/worldgenerator.h"
#include "core/worldgenerator.h"
#include "tiles/tilebase.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "igameeventhandler.h"
#include "iobjectmanager.h"

#include "mapwindow.hh"
#include "gamescene.hh"
#include "mapitem.hh"
#include "objectmanager.hh"
#include "gameeventhandler.hh"
#include "gameeventhandler.hh"
#include "objectmanager.hh"

class ObjectManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjectManagerTest();
private:

    std::shared_ptr<student::GameEventHandler> geHandlerTest;
    std::shared_ptr<student::GameScene> sceneTest;
    std::shared_ptr<student::ObjectManager> ObjManTest;

private Q_SLOTS:

    void init();

    void testCase1();

    void testSetScale();

    void testGetNeighbours();

    void getTileTest();

    void addTilesTest();

    void createPlayerTest();

    void checkTile();
};

ObjectManagerTest::ObjectManagerTest()
{

    //sceneTest->setScale(50);
    //geHandlerTest = std::make_shared<student::GameEventHandler>();
    //ObjManTest = std::make_shared<student::ObjectManager>(sceneTest, geHandlerTest);


}

void ObjectManagerTest::init()
{
    /*
    geHandlerTest.reset();
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    sceneTest.reset();
    sceneTest = std::make_shared<student::GameScene>();

    ObjManTest.reset();
    ObjManTest = std::make_shared<student::ObjectManager>(sceneTest, geHandlerTest);
    */
}

void ObjectManagerTest::addTilesTest()
{
    /*std::vector<std::shared_ptr<Course::TileBase>> tiles;

    std::shared_ptr<Course::TileBase> tile;
    tile = std::make_shared<Course::TileBase>(Course::Coordinate(1,1),
                                              geHandlerTest,
                                              ObjManTest);
    tiles.push_back(tile);
    ObjManTest->addTiles(tiles);
    std::shared_ptr<Course::TileBase> tile1 =
            ObjManTest->getTile(Course::Coordinate(1,1));
    QVERIFY(tile == tile1);*/
    //geHandler_ = std::make_shared<student::GameEventHandler>(nullptr);
    //mgrTest_ = std::make_shared<student::ObjectManager>(nullptr);

    /*mgrTest_->setScale(50);

    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    for (int x = 0; x < 2; ++x){
        for (int y = 0; y < 2; ++y){
            std::shared_ptr<Course::TileBase> tile;
            tile = std::make_shared<Course::TileBase>(Course::Coordinate(x,y), nullptr, nullptr);
            tiles.push_back(tile);
        }
    }
    mgrTest_->addTiles(tiles);*/
}

void ObjectManagerTest::createPlayerTest()
{

}

void ObjectManagerTest::checkTile()
{

}

void ObjectManagerTest::testCase1()
{
    //geHandlerTest = std::make_shared<student::GameEventHandler>();
    //sceneTest = std::make_shared<student::GameScene>(nullptr, 10, 10, 50);
    //ObjManTest = std::make_shared<student::ObjectManager>(sceneTest, geHandlerTest);

    //Course::WorldGenerator::getInstance().addConstructor<Course::TileBase>(10);
    //Course::WorldGenerator::getInstance().generateMap(10,10,1, ObjManTest, geHandlerTest);

    QVERIFY2(true, "Failure");
}

void ObjectManagerTest::testSetScale()
{

}

void ObjectManagerTest::testGetNeighbours()
{


}

void ObjectManagerTest::getTileTest()
{
    /*
    mgrTest_ = std::make_shared<student::ObjectManager>(scene_, geHandler_);

    geHandler_ = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<Course::TileBase> tile;

    tile = std::make_shared<Course::TileBase>(Course::Coordinate(1,1), mgrTest_, geHandler_);

    QVERIFY(tile == mgrTest_->getTile(Course::Coordinate(1,1)));
    */
}


QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
