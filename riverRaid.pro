#-------------------------------------------------
#
# Project created by QtCreator 2017-02-07T04:31:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = riverRaid
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    enemy.cpp \
    health.cpp \
    player.cpp \
    score.cpp \
    shot.cpp \
    background.cpp \
    helicopter.cpp \
    ship.cpp \
    jet.cpp \
    strightbackground.cpp \
    thinbackground.cpp \
    twowaybg.cpp \
    speed.cpp

HEADERS  += game.h \
    enemy.h \
    health.h \
    player.h \
    score.h \
    shot.h \
    background.h \
    helicopter.h \
    ship.h \
    jet.h \
    strightbackground.h \
    thinbackground.h \
    twowaybg.h \
    speed.h

FORMS    += game.ui

RESOURCES += \
    resource.qrc
