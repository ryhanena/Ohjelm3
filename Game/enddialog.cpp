#include "enddialog.hh"
#include "ui_enddialog.h"
#include <QDebug>


namespace student {


EndDialog::EndDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::EndDialog)
{
    ui->setupUi(this);

    winner_ = std::make_pair("", 0);
}

EndDialog::~EndDialog()
{
    delete ui;
}

void EndDialog::calculatePoints(std::shared_ptr<Player> player)
{
    unsigned int points = 0;
    std::string name = player->getName();
    points += player->getMoneyResource();
    points += player->getFoodResource();
    points += player->getOreResources();
    points += player->getStoneResource();
    points += player->getWoodResource();
    pointsMap_[name] = points;
}

void EndDialog::getPlayers(std::vector<std::shared_ptr<Player>> players)
{
    for (auto player : players){
        calculatePoints(player);
    }
    getWinner();
    showResults();
}

void EndDialog::showResults()
{
    ui->winnerLabel->setText(QString("Player") + QString::fromStdString(winner_.first));

    QLabel* playerLabel = new QLabel;
    QLabel* pointsLabel = new QLabel;

    playerLabel->setText(QString("Pelaaja"));
    playerLabel->setAlignment(Qt::AlignCenter);
    pointsLabel->setText(QString("Pisteet"));
    pointsLabel->setAlignment(Qt::AlignCenter);

    ui->gridLayout->addWidget(playerLabel);
    ui->gridLayout->addWidget(pointsLabel);

    for(auto iter : pointsMap_){
        QLabel* playerLabel1 = new QLabel;
        QLabel* pointsLabel1 = new QLabel;
        std::string name = iter.first;

        playerLabel1->setText(QString("Player") + QString::fromStdString(name));
        playerLabel1->setAlignment(Qt::AlignCenter);
        playerLabel1->setFrameStyle(2);
        pointsLabel1->setText(QString::number(iter.second));
        pointsLabel1->setAlignment(Qt::AlignCenter);
        pointsLabel1->setFrameStyle(2);

        ui->gridLayout->addWidget(playerLabel1);
        ui->gridLayout->addWidget(pointsLabel1);
    }

}

void EndDialog::getWinner()
{
    for (auto iter : pointsMap_){
        if (iter.second > winner_.second){
            winner_.first = iter.first;
            winner_.second = iter.second;
        }
    }
    qDebug() << winner_.first.c_str() << winner_.second;
}
}

