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
<<<<<<< HEAD
    // getter/setter LEVEL
    void setLevel(int value);
    // getter/setter SPEED
    int getSpeed();

    // public methods
    void incLevel();

private:
    Level * level;
=======
    void gamePuase();
    Level * getLevel() const;
    void setLevel(Level *value);
    
private:
    Level * level;
    Speed * speed;
>>>>>>> master
    bool singelton;
    int creat;
    QTimer * timerBg;
    QTimer * timerEnemy;
};

#endif // GAME_H
