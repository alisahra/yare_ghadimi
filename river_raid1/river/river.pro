#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T13:39:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = river
TEMPLATE = app


SOURCES += main.cpp\
        player.cpp \
    shot.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp

HEADERS  += player.h \
    shot.h \
    enemy.h \
    game.h \
    score.h \
    health.h

FORMS    += player.ui
