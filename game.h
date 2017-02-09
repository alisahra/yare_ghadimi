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

class Game :public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    myPlayer * player;
    Score * score;
    Health * health;
    BackGround * bgL;
    BackGround * bgR;
    Level * level;
    Speed * speed;
    void setSingelton(bool exist);
    bool getSingelton();

private:
    bool singelton;
    int creat;
    QTimer * timerBg;
    QTimer * timerEnemy;
    int zero;
    int one;
    int two;
};

#endif // GAME_H
