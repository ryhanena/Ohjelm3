#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>

#include "gameeventhandler.hh"
#include "igameeventhandler.h"
#include "objectmanager.hh"
#include "gamescene.hh"
#include "bomb.hh"

#include <map>

class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();

private:
    std::shared_ptr<student::GameEventHandler> geHandlerTest;
    std::shared_ptr<student::ObjectManager> ObjManTest;
    std::shared_ptr<student::GameScene> sceneTest;

private Q_SLOTS:



    //toimii
    void getPlayerCountTest();

    //toimii
    void setNewPlayerTest();

    //toimii
    void getPlayerTest();

    //toimii
    void getPlayerTurnTest();

    //toimii
    void getPlayerInTurnTest();

    //toimii
    void switchTurnTest();

    //toimii
    void getRoundTest();

    //EI TOIMI
    void getPlayerCoordinateTest();

    //EI TOIMI
    void movePlayerTest();

    //EI TOIMI
    void deletePlayerTest();

    //EI TOIMI
    void addBombTest();

    //EI TOIMI
    void getBombTest();

    //EI TOIMI
    void deleteBombTest();

    //EI TOIMI
    void checkExpolsionsTest();


};

GameEventHandlerTest::GameEventHandlerTest()
{   
}

void GameEventHandlerTest::getPlayerCountTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    geHandlerTest->setMaxPLayerCount(10);
    int test = geHandlerTest->getMaxPlayerCount();
    QCOMPARE(test, 10);
}

void GameEventHandlerTest::setNewPlayerTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    //Testaa onko pelaajamapissa lisätyt pelaajat
    QCOMPARE(geHandlerTest->getPlayerCount(), 3);
}

void GameEventHandlerTest::getPlayerTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    //Testaa onko pelaajamapissa lisätyt pelaajat
    QVERIFY(geHandlerTest->getPlayer(0) == Antti1);
    QVERIFY(geHandlerTest->getPlayer(1) == Antti2);
    QVERIFY(geHandlerTest->getPlayer(2) == Konsta);
}

void GameEventHandlerTest::getPlayerTurnTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();
    //Tarkistaa onko aloitusvuoro pelaaja1
    QCOMPARE(geHandlerTest->getPlayerTurn(), 1);
}

void GameEventHandlerTest::getPlayerInTurnTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    QVERIFY(geHandlerTest->getPlayerInTurn() == Antti1);
}

void GameEventHandlerTest::switchTurnTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    QVERIFY(geHandlerTest->getPlayerInTurn() == Antti1);
    QCOMPARE(geHandlerTest->getPlayerTurn(), 1);

    geHandlerTest->switchTurn();

    QCOMPARE(geHandlerTest->getPlayerTurn(), 2);

}

void GameEventHandlerTest::getRoundTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();
    //Tarkistaa onko kierros 1
    QCOMPARE(geHandlerTest->getRound(), 1);
}

void GameEventHandlerTest::getPlayerCoordinateTest()
{
    /*
    geHandlerTest = std::make_shared<student::GameEventHandler>();
    //sceneTest = std::make_shared<student::GameScene>();

    ObjManTest = std::make_shared<student::ObjectManager>(nullptr, geHandlerTest);


    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");

    std::shared_ptr<Course::GameObject> Flag;

    Course::Coordinate coord = Course::Coordinate(0, 0);

    Flag = std::make_shared<Course::GameObject>(coord,
                                                Antti1,
                                                geHandlerTest,
                                                ObjManTest);

    student::MapItem* itemFlag = new student::MapItem(Flag, 50);

    geHandlerTest->setNewPlayer(Antti1, itemFlag);

    Course::Coordinate test = geHandlerTest->getPlayerCoordinate();

    QVERIFY(test == coord);
    */

}

void GameEventHandlerTest::movePlayerTest()
{
    /*
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    geHandlerTest->movePlayer(2,3);
    */
}
void GameEventHandlerTest::deletePlayerTest()
{
    /*
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    QVERIFY(geHandlerTest->getPlayerInTurn() == Antti1);

    geHandlerTest->deletePlayer(Antti2);

    QCOMPARE(geHandlerTest->getPlayerCount(), 2);
    */
}

void GameEventHandlerTest::addBombTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    std::shared_ptr<student::Bomb> testBomb;
    testBomb = std::make_shared<student::Bomb>(geHandlerTest, nullptr, Antti1);

    geHandlerTest->addBomb(testBomb);
    QCOMPARE(geHandlerTest->getBombCount(), 1);

}

void GameEventHandlerTest::getBombTest()
{

    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    std::shared_ptr<student::Bomb> testBomb;
    testBomb = std::make_shared<student::Bomb>(geHandlerTest, nullptr, Antti1);

    geHandlerTest->addBomb(testBomb);

    std::shared_ptr<student::Bomb> testi;
    testi = geHandlerTest->getBomb(0);

    QVERIFY(testi == testBomb);

}

void GameEventHandlerTest::deleteBombTest()
{
    geHandlerTest = std::make_shared<student::GameEventHandler>();

    std::shared_ptr<student::Player> Antti1;
    Antti1 = std::make_shared<student::Player>("1");
    std::shared_ptr<student::Player> Antti2;
    Antti2 = std::make_shared<student::Player>("2");
    std::shared_ptr<student::Player> Konsta;
    Konsta = std::make_shared<student::Player>("3");
    student::MapItem* Flag;

    geHandlerTest->setNewPlayer(Antti1, Flag);
    geHandlerTest->setNewPlayer(Antti2, Flag);
    geHandlerTest->setNewPlayer(Konsta, Flag);

    std::shared_ptr<student::Bomb> testBomb;
    testBomb = std::make_shared<student::Bomb>(geHandlerTest, nullptr, Antti1);
    std::shared_ptr<student::Bomb> testBomb2;
    testBomb2 = std::make_shared<student::Bomb>(geHandlerTest, nullptr, Antti2);

    geHandlerTest->addBomb(testBomb);
    geHandlerTest->addBomb(testBomb2);
    QCOMPARE(geHandlerTest->getBombCount(), 2);

    geHandlerTest->deleteBomb(testBomb2);

    QCOMPARE(geHandlerTest->getBombCount(), 1);

    std::shared_ptr<student::Bomb> testi3;

    testi3 = geHandlerTest->getBomb(0);

    QVERIFY(testi3 == testBomb);
}

void GameEventHandlerTest::checkExpolsionsTest()
{

}

QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
