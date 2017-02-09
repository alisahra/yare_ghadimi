#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    zero = 0;
    one = 1;
    two = 2;
    creat = 0;
    singelton = true;
    // create a scene
    scene = new QGraphicsScene();
    setScene(scene);

    // create a view
    //QGraphicsView * view = new QGraphicsView(scene);

    // set scrolbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create item
    player = new myPlayer();

    // add item to the scene
    scene->addItem(player);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // set the scene and view with eachOther
    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(Qt::blue));

    // set the location of player
    player->setPos((width()/2) - (player->pixmap().width()/2) , height() - player->pixmap().height());

    bgL = new BackGround();
    scene->addItem(bgL);
    bgR = new BackGround(5);
    scene->addItem(bgR);

    QTimer * baseBgTimer = new QTimer();
    QObject::connect(baseBgTimer,SIGNAL(timeout()),bgL,SLOT(checkColl()));
    QObject::connect(baseBgTimer,SIGNAL(timeout()),bgL,SLOT(checkColl()));
    baseBgTimer->start(50);

    // score
    score = new Score();
    scene->addItem(score);

    // health
    health = new Health();
    health->setPos(health->x(),health->y() + 30);
    scene->addItem(health);
    unsigned int i = 0;
    timerEnemy = new QTimer();

    QTimer * t = new QTimer();
    QObject::connect(t,SIGNAL(timeout()),this,SLOT(creatMap()));

    t->start(2000);

    //QObject::connect(timerBg,SIGNAL(timeout()),player,SLOT(bgLSpawn()));
    //QObject::connect(timerBg,SIGNAL(timeout()),player,SLOT(bgRSpawn()));

    //timerBg->start(100);

    // show the page

    show();
}

void Game::setSingelton(bool exist)
{
    singelton = exist;
    return;
}

bool Game::getSingelton()
{
    return this->singelton;
}

void Game::creatMap()
{
        if(creat%4 == 0){
            timerEnemy->stop();
            qDebug() << "salam";
            QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(objectSpawn(zero)));
            timerEnemy->start(2500);

        }else if(creat%2 == 1) {
            timerEnemy->stop();
            qDebug() << "salam nkn";
            level->incLvl();
            player->thinBgLSpawn();
            player->thinBgRSpawn();

            QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(objectSpawn(one)));

            timerEnemy->start(2500);

        }else if(creat%4 == 2){
            timerEnemy->stop();
            player->twoWaysBgSpawn();
            QObject::connect(timerEnemy,SIGNAL(timeout()),player,[player]{ objectSpawn(two); });

            timerEnemy->start(2500);
        }
        creat++;
}
