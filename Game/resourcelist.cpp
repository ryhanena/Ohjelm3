#include "resourcelist.hh"
#include "ui_resourcelist.h"

ResourceList::ResourceList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResourceList)
{
    ui->setupUi(this);
}

ResourceList::~ResourceList()
{
    delete ui;
}

void ResourceList::on_pushButton_clicked()
{
    this->close();
}
