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
#include "speed.h"
#include "level.h"
#include <QObject>

class Game :public QGraphicsView {
    Q_OBJECT
public:
    Game();
    QGraphicsScene * scene;
    myPlayer * player;
    Score * score;
    Health * health;
    BackGround * bgL;
    BackGround * bgR;
    void setSingelton(bool exist);
    bool getSingelton();
    // getter/setter LEVEL
    void setLevel(int value);
    // getter/setter SPEED
    int getSpeed();

    // public methods
    void incLevel();

    void gamePuase();
private:
    Level * level;
    bool singelton;
    int creat;
    QTimer * timerBg;
    QTimer * timerEnemy;
};

#endif // GAME_H
