#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "score.h"
#include "health.h"
#include "background.h"

class Game : public QGraphicsView {
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    myPlayer * player;
    Score * score;
    Health * health;
    BackGround * bgL;
    BackGround * bgR;
};

#endif // GAME_H