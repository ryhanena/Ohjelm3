#include "gamedialog.hh"
#include "ui_gamedialog.h"


gameDialog::gameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameDialog)

{
    playerCount_ = 2;
    rounds_ = 10;
    mapSize_ = 10;
    scale_ = 50;
    ui->setupUi(this);
}

gameDialog::~gameDialog()
{
    delete ui;
}

void gameDialog::on_pushButton_clicked()
{
    emit sendData(mapSize_, scale_, rounds_);
    emit setPlayerCount(playerCount_);
    this->close();
}

void gameDialog::on_setScale_valueChanged(int arg1)
{
    scale_ = arg1;
}

void gameDialog::on_MapSize_valueChanged(int arg1)
{
    mapSize_ = arg1;
}

void gameDialog::on_Players_valueChanged(int arg1)
{
    playerCount_ = arg1;
}

void gameDialog::on_setRounds_valueChanged(int arg1)
{
    rounds_ = arg1;
}
