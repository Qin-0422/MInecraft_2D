#-------------------------------------------------
#
# Project created by QtCreator 2025-03-14T22:49:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Minecraft_2D
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        Widget.cpp \
    Init.cpp \
    BeginInterface.cpp \
    HelpInterface.cpp \
    ArchiveInterface.cpp \
    Level_Map.cpp \
    Map_Level_1.cpp \
    Character.cpp \
    Steve.cpp \
    Map_Level_2.cpp \
    Map_Change.cpp

HEADERS += \
        Widget.h \
    Init.h \
    BeginInterface.h \
    HelpInterface.h \
    ArchiveInterface.h \
    Level_Map.h \
    Map_Level_1.h \
    Character.h \
    Steve.h \
    Map_Level_2.h \
    Map_Change.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img_back.qrc
