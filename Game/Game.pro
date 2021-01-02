TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    main.cpp \
    gameeventhandler.cpp \
    objectmanager.cpp \
    gamedialog.cpp \
    gamescene.cpp \
    mapitem.cpp \
    imagefactory.cpp \
    mapwindow.cc \
    bomb.cpp \
    mine.cpp \
    player.cpp \
    rules.cpp \
    desert.cpp \
    enddialog.cpp \
    lake.cpp \
    engineer.cpp \
    fisher.cpp \
    hill.cpp \
    resourcelist.cpp


HEADERS += \
    mapwindow.hh \
    gameeventhandler.hh \
    objectmanager.hh \
    gamedialog.hh \
    gamescene.hh \
    mapitem.hh \
    config.hh \
    imagefactory.hh \
    bomb.hh \
    mine.hh \
    player.hh \
    resourcemaps.hh \
    rules.hh \
    desert.hh \
    enddialog.hh \
    lake.hh \
    engineer.hh \
    fisher.hh \
    hill.hh \
    resourcelist.hh

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    mapwindow.ui \
    gamedialog.ui \
    rules.ui \
    enddialog.ui \
    resourcelist.ui

RESOURCES += \
    resources.qrc



