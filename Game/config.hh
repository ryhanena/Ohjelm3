#ifndef CONFIG_HH
#define CONFIG_HH

#include <vector>
#include <QString>
#include <QColor>
#include <QPointF>

#include "gamescene.hh"

namespace student {

/**
 * @brief Handles important data for game
 */

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 4;

const std::vector<std::string> imagePathVector{
    ":/Assets/Assets/farmhouse.png",
    ":/Assets/Assets/bomb.png",
    ":/Assets/Assets/headquarter.png",
    ":/Assets/Assets/mine.png",
    ":/Assets/Assets/soldier.png",
    ":/Assets/Assets/basicFarmer.png",
    ":/Assets/Assets/engineer.png",
    ":/Assets/Assets/fisher.png",
    ":/Assets/Assets/blueFlag.png",
    ":/Assets/Assets/redFlag.png",
    ":/Assets/Assets/greenFlag.png",
    ":/Assets/Assets/yellowFlag.png"

};

const std::vector<std::string> picNameVector{
    "Farm",
    "Bomb",
    "HeadQuarters",
    "Mine",
    "Outpost",
    "BasicWorker",
    "Engineer",
    "Fisher",
    "1",
    "2",
    "3",
    "4"
};

const std::vector<QColor> playerColourVector = {
    Qt::blue,
    Qt::red,
    Qt::green,
    Qt::yellow
};

const std::vector<QString> playerQColourVector = {
    QString("blue"),
    QString("red"),
    QString("green"),
    QString("yellow")
};

}

#endif // CONFIG_HH
