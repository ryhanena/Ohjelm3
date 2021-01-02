#include <QApplication>

#include "mapwindow.hh"

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    student::MapWindow mapWindow;
    mapWindow.show();
    return app.exec();
}
