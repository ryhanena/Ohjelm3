#-------------------------------------------------
#
# Project created by QtCreator 2019-11-28T18:05:29
#
#-------------------------------------------------

QT       += widgets testlib

TARGET = tst_objectmanagertest
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++14

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_objectmanagertest.cpp \
    ../../Game/bomb.cpp \
    ../../Game/engineer.cpp \
    ../../Game/fisher.cpp \
    ../../Game/desert.cpp \
    ../../Game/lake.cpp \
    ../../Game/hill.cpp \
    ../../Game/gamedialog.cpp \
    ../../Game/gameeventhandler.cpp \
    ../../Game/enddialog.cpp \
    ../../Game/gamescene.cpp \
    ../../Game/imagefactory.cpp \
    ../../Game/mapitem.cpp \
    ../../Game/mapwindow.cc \
    ../../Game/mine.cpp \
    ../../Game/objectmanager.cpp \
    ../../Game/player.cpp \
    ../../Game/rules.cpp \
    ../../Game/resourcelist.cpp \
    ../../Course/CourseLib/buildings/buildingbase.cpp \
    ../../Course/CourseLib/buildings/farm.cpp \
    ../../Course/CourseLib/buildings/headquarters.cpp \
    ../../Course/CourseLib/buildings/outpost.cpp \
    ../../Course/CourseLib/core/basicresources.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Course/CourseLib/core/gameobject.cpp \
    ../../Course/CourseLib/core/placeablegameobject.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Course/CourseLib/core/worldgenerator.cpp \
    ../../Course/CourseLib/graphics/simplegamescene.cpp \
    ../../Course/CourseLib/graphics/simplemapitem.cpp \
    ../../Course/CourseLib/tiles/forest.cpp \
    ../../Course/CourseLib/tiles/grassland.cpp \
    ../../Course/CourseLib/tiles/tilebase.cpp \
    ../../Course/CourseLib/workers/basicworker.cpp \
    ../../Course/CourseLib/workers/workerbase.cpp

SUBDIRS += \
    ../../Game/Game.pro

RESOURCES += \
    ../../Game/resources.qrc

FORMS += \
    ../../Game/gamedialog.ui \
    ../../Game/mapwindow.ui \
    ../../Game/enddialog.ui \
    ../../Game/resourcelist.ui \
    ../../Game/rules.ui

HEADERS += \
    ../../Game/bomb.hh \
    ../../Game/engineer.hh \
    ../../Game/fisher.hh \
    ../../Game/config.hh \
    ../../Game/desert.hh \
    ../../Game/lake.hh \
    ../../Game/hill.cpp \
    ../../Game/gamedialog.hh \
    ../../Game/gameeventhandler.hh \
    ../../Game/enddialog.hh \
    ../../Game/gamescene.hh \
    ../../Game/imagefactory.hh \
    ../../Game/mapitem.hh \
    ../../Game/mapwindow.hh \
    ../../Game/mine.hh \
    ../../Game/objectmanager.hh \
    ../../Game/player.hh \
    ../../Game/resourcemaps.hh \
    ../../Game/resourcelist.hh \
    ../../Game/rules.hh \
    ../../Course/CourseLib/interfaces/igameeventhandler.h \
    ../../Course/CourseLib/interfaces/iobjectmanager.h \
    ../../Course/CourseLib/buildings/buildingbase.h \
    ../../Course/CourseLib/buildings/farm.h \
    ../../Course/CourseLib/buildings/headquarters.h \
    ../../Course/CourseLib/buildings/outpost.h \
    ../../Course/CourseLib/core/basicresources.h \
    ../../Course/CourseLib/core/coordinate.h \
    ../../Course/CourseLib/core/gameobject.h \
    ../../Course/CourseLib/core/placeablegameobject.h \
    ../../Course/CourseLib/core/playerbase.h \
    ../../Course/CourseLib/core/resourcemaps.h \
    ../../Course/CourseLib/core/worldgenerator.h \
    ../../Course/CourseLib/exceptions/baseexception.h \
    ../../Course/CourseLib/exceptions/illegalaction.h \
    ../../Course/CourseLib/exceptions/invalidpointer.h \
    ../../Course/CourseLib/exceptions/keyerror.h \
    ../../Course/CourseLib/exceptions/notenoughspace.h \
    ../../Course/CourseLib/exceptions/ownerconflict.h \
    ../../Course/CourseLib/graphics/simplegamescene.h \
    ../../Course/CourseLib/graphics/simplemapitem.h \
    ../../Course/CourseLib/tiles/forest.h \
    ../../Course/CourseLib/tiles/grassland.h \
    ../../Course/CourseLib/tiles/tilebase.h \
    ../../Course/CourseLib/workers/basicworker.h \
    ../../Course/CourseLib/workers/workerbase.h

INCLUDEPATH += ../../Game \
                ../../Course/CourseLib/interfaces \
                ../../Course/CourseLib

DEPENDPATH += ../../Game \
                ../../Course/CourseLib/interfaces \
                ../../Course/CourseLib
