#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <map>
#include <vector>

#include "core/playerbase.h"
#include "gameeventhandler.hh"
#include "gamedialog.hh"
#include "enddialog.hh"
#include "gamescene.hh"
#include "objectmanager.hh"
#include "rules.hh"
#include "mapitem.hh"

namespace Ui {
class MapWindow;
}

namespace student {

/**
 * @brief The MapWindow class represents the mainwindow of the game.
 * Creates scene, objManager, geHandler and other stuff needed in game
 *
 */
class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MapWindow constructor
     * @param parent
     */
    explicit MapWindow(QWidget *parent = 0);

    ~MapWindow();

    /**
     * @brief setSize of playground
     * @param width
     * @param height
     */
    void setSize(int width, int height);

    /**
     * @brief setScale of playground
     * @param scale
     */
    void setScale(int scale);

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
     * @brief setPlayerCount in mapWindow
     */
    void setPlayerCount();

    /**
     * @brief setPlayerMenu set playerGraphics in menuscreen
     */
    void setPlayerMenu();
    
    /**
     * @brief checkButtons check which button is pressed
     * @return name of action
     */
    std::string checkButtons();

    /**
     * @brief resetButtons resets the action buttons
     */
    void resetButtons();

    /**
     * @brief endTurn ends the turn,
     * explodes bombs and clear tiles
     * also checks if game is over
     */
    void endTurn();

    /**
     * @brief endGame creates endGameDialog
     * @param players whose finished alive through the game
     */
    void endGame(std::vector<std::shared_ptr<Player>> players);

    /**
     * @brief updatePlayerMenu updates playerMenu Graphics
     * while game is on
     */
    void updatePlayerMenu();


public slots:

    /**
     * @brief receiveData receive information of game from dialog
     * @param size
     * @param scale
     * @param rounds
     */
    void receiveData(int size, int scale, int rounds);

    /**
     * @brief tilePressed control actions
     * get coordinate from gameScene
     * @param coordinate to be operated
     */
    void tilePressed(Course::Coordinate coord);

    /**
     * @brief receivePlayerCount from dialog
     * @param count
     */
    void receivePlayerCount(int count);

    /**
     * @brief on_Button_clicked functions receive information of
     * which button in checked
     * @params checked
     */
    void on_farmButton_clicked(bool ckecked);
    void on_mineButton_clicked(bool checked);
    void on_outpostButton_clicked(bool checked);
    void on_bombButton_clicked(bool checked);
    void on_workerButton_clicked(bool checked);
    void on_engineerButton_clicked(bool checked);
    void on_fisherButton_clicked(bool checked);

private slots:

    /**
     * @brief on_rulesButton_clicked opens the resourceDialog
     */
    void on_resourceButton_clicked();

    /**
     * @brief on_rulesButton_clicked opens the rulesDialog
     */
    void on_rulesButton_clicked();

private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<student::ObjectManager> m_ObjManager;
    std::shared_ptr<student::GameScene> myScene = nullptr;
    std::map<Course::Coordinate, std::shared_ptr<MapItem>> itemMap_;
    std::shared_ptr<Course::PlayerBase> player_;

    int mapSize_ = 0;
    int scale_ = 0;
    int rounds_ = 0;
    int playerCount_ = 0;
    int actions_ = 1;

    std::string playerInTurn_ = "";
    std::vector<QLabel*> flagLabelVector_;
    std::vector<QLabel*> moneyLabelVector_;
    std::vector<QLabel*> foodLabelVector_;
    std::vector<QLabel*> woodLabelVector_;
    std::vector<QLabel*> stoneLabelVector_;
    std::vector<QLabel*> oreLabelVector_;

};
}
#endif // MapWINDOW_HH

