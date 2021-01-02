#include <math.h>
#include <QDebug>
#include <string>

#include "tiles/forest.h"
#include "core/worldgenerator.h"
#include "tiles/grassland.h"
#include "tiles/tilebase.h"
#include "buildings/buildingbase.h"
#include "core/coordinate.h"
#include "core/placeablegameobject.h"
#include "core/basicresources.h"
#include "core/resourcemaps.h"

#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include "imagefactory.hh"
#include "desert.hh"
#include "lake.hh"
#include "hill.hh"
#include "config.hh"
#include "bomb.hh"
#include "player.hh"
#include "resourcelist.hh"

namespace student {

MapWindow::MapWindow(QWidget *parent
                     ):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(std::make_shared<GameEventHandler>()),
    myScene(new GameScene(this))
{

    QDialog* dialog = new gameDialog(this);
    connect(dialog, SIGNAL(sendData(int, int, int)), this, SLOT(receiveData(int, int, int)));
    connect(dialog, SIGNAL(setPlayerCount(int)), this, SLOT(receivePlayerCount(int)));
    dialog->exec();

    m_ui->setupUi(this);

    std::shared_ptr<ObjectManager> objectManager;
    objectManager = std::make_shared<ObjectManager>(myScene, m_GEHandler);
    m_ObjManager = objectManager;

    GameScene* sgs_rawptr = myScene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    m_ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setSize(mapSize_ , mapSize_);
    setScale(scale_);

    Course::WorldGenerator::getInstance().addConstructor<Hill>(3);
    Course::WorldGenerator::getInstance().addConstructor<Lake>(1);
    Course::WorldGenerator::getInstance().addConstructor<Desert>(1);
    Course::WorldGenerator::getInstance().addConstructor<Course::Forest>(8);
    Course::WorldGenerator::getInstance().addConstructor<Course::Grassland>(10);
    Course::WorldGenerator::getInstance().generateMap(mapSize_,mapSize_,1,m_ObjManager,m_GEHandler);

    imageFactory::getInstance().initalizePixmaps();

    connect(sgs_rawptr, &GameScene::sendCoordinate, this, &MapWindow::tilePressed);

    setPlayerCount();
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setSize(int width, int height)
{
    myScene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    myScene->setScale(scale);
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    myScene->updateItem(obj);
}


void MapWindow::tilePressed(Course::Coordinate coord)
{
    if (m_ObjManager->checkIfPlaceableTile(coord) == false){
        m_ui->errorLabel->setText(QString("Voit liikkua tai asettaa objektin vain lipun ympärillä oleviin ruutuihin"));
        return;
    }
    else if (m_ObjManager->checkIfOutpost(coord) == true){
        m_ui->errorLabel->setText(QString("Ruutu on vartioitu"));
        return;
    }
    else{
        std::shared_ptr<Course::TileBase> tile = m_ObjManager->getTile(coord);
        unsigned int buildingCount = tile->getBuildingCount();
        std::string type = tile->getType();
        std::string toiminto = checkButtons();

        if (toiminto == "Move" && type != "Lake"){
            m_GEHandler->movePlayer(coord);
        }
        else{

            if (toiminto == "Bomb"){
                bool setBomb = m_ObjManager->setBomb(tile);
                if (!setBomb){
                    m_ui->errorLabel->setText(QString("Pommia ei voitu asettaa"));
                    resetButtons();
                    return;
                }
            }
            else if (type == "Lake"){
                if (toiminto != "Fisher"){
                    m_ui->errorLabel->setText(QString("Et osaa uida"));
                    resetButtons();
                    return;
                }
                else{
                    bool addWork = m_ObjManager->addWorker(toiminto, tile);
                    if (!addWork){
                        m_ui->errorLabel->setText(QString("Resurssit eivät riitä"));
                        resetButtons();
                        return;
                    }
                }
            }
            else if (toiminto == "BasicWorker" || toiminto == "Engineer"){
                if (type == "Desert"){
                    m_ui->errorLabel->setText(QString("Ei mitään rakennettavaa"));
                    resetButtons();
                    return;
                }
                bool addWork = m_ObjManager->addWorker(toiminto, tile);
                if (!addWork){
                    m_ui->errorLabel->setText(QString("Resurssit eivät riitä"));
                    resetButtons();
                    return;
                }
            }
            else if (buildingCount > 2){
                m_ui->errorLabel->setText(QString("Rakennuksia on jo enimmäismäärä"));
                resetButtons();
                return;
            }
            else if (type == "Forest" && buildingCount > 1){
                m_ui->errorLabel->setText(QString("Rakennuksia on jo enimmäismäärä"));
                resetButtons();
                return;
            }
            else if (type == "Desert" && (toiminto != "Outpost" ||
                                           buildingCount > 0)){
                m_ui->errorLabel->setText(QString("Aavikolle ei voi rakentaa"));
                resetButtons();
                return;
            }
            else{
                bool build = m_ObjManager->buildingMaker(toiminto, buildingCount, tile);
                if (!build){
                    m_ui->errorLabel->setText(QString("Resurssit eivät riitä"));
                    resetButtons();
                    return;
                }
            }
        }
    }
    endTurn();
    update();
}

void MapWindow::setPlayerCount()
{
    setPlayerMenu();

    for (int i = 0; i < playerCount_; i++){

        m_ObjManager->createNewPlayer(i, mapSize_);

        QLabel* playerLabel = new QLabel;
        QLabel* flagLabel = new QLabel;
        QLabel* moneyLabel = new QLabel;
        QLabel* foodLabel = new QLabel;
        QLabel* woodLabel = new QLabel;
        QLabel* stoneLabel = new QLabel;
        QLabel* oreLabel = new QLabel;

        playerLabel->setText(QString("Player")+QString::number(i+1)+QString(":"));
        playerLabel->setStyleSheet(QString("background-color : ")+playerQColourVector[i]);
        playerLabel->setMargin(5);
        playerLabel->setFrameStyle(2);
        playerLabel->setAlignment(Qt::AlignCenter);

        flagLabelVector_.push_back(flagLabel);
        if(i == 0){
            flagLabel->setStyleSheet("image: url(:/Assets/Assets/blueFlag.png);");
        }else if (i == 1){
            flagLabel->setStyleSheet("image: url(:/Assets/Assets/redFlag.png);");
            flagLabel->setVisible(true);
        }else if (i ==2){
            flagLabel->setStyleSheet("image: url(:/Assets/Assets/greenFlag.png);");
            flagLabel->setVisible(true);
        }else if (i == 3){
            flagLabel->setStyleSheet("image: url(:/Assets/Assets/yellowFlag.png);");
            flagLabel->setVisible(true);
        }

        moneyLabelVector_.push_back(moneyLabel);
        moneyLabel->setFrameStyle(2);
        foodLabelVector_.push_back(foodLabel);
        foodLabel->setFrameStyle(2);
        woodLabelVector_.push_back(woodLabel);
        woodLabel->setFrameStyle(2);
        stoneLabelVector_.push_back(stoneLabel);
        stoneLabel->setFrameStyle(2);
        oreLabelVector_.push_back(oreLabel);
        oreLabel->setFrameStyle(2);

        m_ui->playerGrid->addWidget(playerLabel);
        m_ui->playerGrid->addWidget(flagLabel);
        m_ui->playerGrid->addWidget(moneyLabel);
        m_ui->playerGrid->addWidget(foodLabel);
        m_ui->playerGrid->addWidget(woodLabel);
        m_ui->playerGrid->addWidget(stoneLabel);
        m_ui->playerGrid->addWidget(oreLabel);
    }
}

void MapWindow::setPlayerMenu()
{
    QLabel* playerLabel1 = new QLabel;
    QLabel* flagLabel1 = new QLabel;
    QLabel* resourceLabel1 = new QLabel;
    QLabel* resourceLabel2 = new QLabel;
    QLabel* resourceLabel3 = new QLabel;
    QLabel* resourceLabel4 = new QLabel;
    QLabel* resourceLabel5 = new QLabel;

    playerLabel1->setText(QString("Pelaajat"));
    playerLabel1->setAlignment(Qt::AlignCenter);
    flagLabel1->setText(QString(""));
    resourceLabel1->setText(QString("M"));
    resourceLabel2->setText(QString("F"));
    resourceLabel3->setText(QString("W"));
    resourceLabel4->setText(QString("S"));
    resourceLabel5->setText(QString("O"));
    resourceLabel1->setAlignment(Qt::AlignCenter);
    resourceLabel2->setAlignment(Qt::AlignCenter);
    resourceLabel3->setAlignment(Qt::AlignCenter);
    resourceLabel4->setAlignment(Qt::AlignCenter);
    resourceLabel5->setAlignment(Qt::AlignCenter);

    m_ui->playerGrid->addWidget(playerLabel1);
    m_ui->playerGrid->addWidget(flagLabel1);
    m_ui->playerGrid->addWidget(resourceLabel1);
    m_ui->playerGrid->addWidget(resourceLabel2);
    m_ui->playerGrid->addWidget(resourceLabel3);
    m_ui->playerGrid->addWidget(resourceLabel4);
    m_ui->playerGrid->addWidget(resourceLabel5);

    m_ui->maxround->setText(QString::number(rounds_));
}

void MapWindow::receiveData(int size, int scale, int rounds)
{
    mapSize_ = size;
    scale_ = scale;
    rounds_ = rounds;
}

void MapWindow::receivePlayerCount(int count)
{
    playerCount_ = count;
    m_GEHandler->setMaxPLayerCount(count);
}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    myScene->removeItem(obj);
}

std::string MapWindow::checkButtons(){
    if (m_ui->farmButton->isChecked()){
        return "Farm";
    }
    else if(m_ui->mineButton->isChecked()){
        return "Mine";
    }
    else if(m_ui->outpostButton->isChecked()){
        return "Outpost";
    }
    else if(m_ui->bombButton->isChecked()){
        return "Bomb";
    }
    else if(m_ui->workerButton->isChecked()){
        return "BasicWorker";
    }
    else if(m_ui->engineerButton->isChecked()){
        return "Engineer";
    }
    else if(m_ui->fisherButton->isChecked()){
        return "Fisher";
    }else{
        return "Move";
    }
}

void MapWindow::resetButtons()
{
    m_ui->engineerButton->setChecked(false);
    m_ui->farmButton->setChecked(false);
    m_ui->mineButton->setChecked(false);
    m_ui->outpostButton->setChecked(false);
    m_ui->bombButton->setChecked(false);
    m_ui->workerButton->setChecked(false);
    m_ui->fisherButton->setChecked(false);

    m_ui->engineerButton->setDisabled(false);
    m_ui->farmButton->setDisabled(false);
    m_ui->mineButton->setDisabled(false);
    m_ui->outpostButton->setDisabled(false);
    m_ui->bombButton->setDisabled(false);
    m_ui->workerButton->setDisabled(false);
    m_ui->fisherButton->setDisabled(false);
}

void MapWindow::endTurn()
{

    std::shared_ptr<Bomb> bomb = m_GEHandler->checkExpolsions();
    if (bomb != nullptr){
        Course::Coordinate coord = bomb->getCoordinate();
        m_ObjManager->clearTileBuilds(coord);
        std::vector<std::shared_ptr<Course::TileBase>> placeableTiles = m_ObjManager->getNeigbours(coord);
        for (std::shared_ptr<Course::TileBase> tile : placeableTiles){
            int i = tile->getBuildingCount();
            while (i != 0){
                m_ObjManager->clearTileBuilds(tile->getCoordinate());
                update();
                i -= 1;
            }
            int a = tile->getWorkerCount();
            while (a != 0) {
                m_ObjManager->clearTileWorkers(tile->getCoordinate());
                update();
                a -= 1;
            }
            myScene->resetTile(tile);
            if (tile->getOwner()){
                std::shared_ptr<Course::PlayerBase> player = tile->getOwner();
                std::shared_ptr<Course::GameObject> obj = std::static_pointer_cast<Course::GameObject>(tile);
                player->removeObject(obj);
            }
        }
        m_GEHandler->deleteBomb(bomb);
    }

    int round = m_GEHandler->getRound();
    if (m_GEHandler->checkIfEnd() != nullptr ||
            rounds_ == round){
        endGame(m_GEHandler->getPlayers());
    }

    m_GEHandler->switchTurn();

    m_ui->actionLabel->setNum(round);

    updatePlayerMenu();
    resetButtons();

    m_ui->errorLabel->setText(QString(""));
}

void MapWindow::endGame(std::vector<std::shared_ptr<Player>> players)
{
    EndDialog* eDialog = new EndDialog(nullptr);
    eDialog->getPlayers(players);

    connect(eDialog, &QDialog::accepted, this, &MapWindow::close);

    eDialog->exec();

}

void MapWindow::updatePlayerMenu()
{
    playerInTurn_ = m_GEHandler->getPlayerInTurn()->getName();
    m_ui->inTurnLabel->setText(QString("Player")+QString::fromStdString(playerInTurn_));

    for (int i = 0; i < playerCount_ ; i++){

        std::shared_ptr<Player> pelaaja = m_GEHandler->getPlayer(i);
        if (pelaaja != nullptr){
            int money = pelaaja->getMoneyResource();
            int food = pelaaja->getFoodResource();
            int wood = pelaaja->getWoodResource();
            int stone = pelaaja->getStoneResource();
            int ore = pelaaja->getOreResources();

            moneyLabelVector_[i]->setText(QString::number(money));
            foodLabelVector_[i]->setText(QString::number(food));
            woodLabelVector_[i]->setText(QString::number(wood));
            stoneLabelVector_[i]->setText(QString::number(stone));
            oreLabelVector_[i]->setText(QString::number(ore));
        }
        else{
            moneyLabelVector_[i]->setText(QString::number(0));
            foodLabelVector_[i]->setText(QString::number(0));
            woodLabelVector_[i]->setText(QString::number(0));
            stoneLabelVector_[i]->setText(QString::number(0));
            oreLabelVector_[i]->setText(QString::number(0));
        }
    }

    m_ui->fisherButton->setChecked(false);
    m_ui->farmButton->setChecked(false);
    m_ui->mineButton->setChecked(false);
    m_ui->outpostButton->setChecked(false);
    m_ui->bombButton->setChecked(false);
    m_ui->workerButton->setChecked(false);
    m_ui->engineerButton->setChecked(false);

    m_ui->fisherButton->setDisabled(false);
    m_ui->engineerButton->setDisabled(false);
    m_ui->farmButton->setDisabled(false);
    m_ui->mineButton->setDisabled(false);
    m_ui->outpostButton->setDisabled(false);
    m_ui->bombButton->setDisabled(false);
    m_ui->workerButton->setDisabled(false);

    m_ui->errorLabel->setText(QString(""));
}

void MapWindow::on_farmButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->engineerButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->bombButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->engineerButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->bombButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}

void MapWindow::on_mineButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->engineerButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->bombButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->engineerButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->bombButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}

void MapWindow::on_outpostButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->engineerButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->bombButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->engineerButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->bombButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}

void MapWindow::on_bombButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->engineerButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->engineerButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}

void MapWindow::on_workerButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->bombButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->engineerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->bombButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->engineerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}
void MapWindow::on_engineerButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->bombButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->fisherButton->setDisabled(true);
    }else{
        m_ui->bombButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->fisherButton->setDisabled(false);
    }
}


void MapWindow::on_fisherButton_clicked(bool checked)
{
    if (checked == true){
        m_ui->bombButton->setDisabled(true);
        m_ui->farmButton->setDisabled(true);
        m_ui->mineButton->setDisabled(true);
        m_ui->outpostButton->setDisabled(true);
        m_ui->workerButton->setDisabled(true);
        m_ui->engineerButton->setDisabled(true);
    }else{
        m_ui->bombButton->setDisabled(false);
        m_ui->farmButton->setDisabled(false);
        m_ui->mineButton->setDisabled(false);
        m_ui->outpostButton->setDisabled(false);
        m_ui->workerButton->setDisabled(false);
        m_ui->engineerButton->setDisabled(false);
    }
}

void MapWindow::on_resourceButton_clicked()
{
    QDialog* resourcedialog = new ResourceList(this);
    resourcedialog->exec();
}

void MapWindow::on_rulesButton_clicked()
{
    QDialog* rulesdialog = new Rules(this);
    rulesdialog->exec();
}
} //namespace
