#include "game.h"
#include <stdlib.h>
#include <time.h>

Game::Game(QWidget *parent) : QGraphicsView(parent) {
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
    int i = 0;
//    while(1){
//        i++;
//        if(i%2 == 1){
//            QTimer * timerEnemy = new QTimer();
//            QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(enemySpawn(i)));
//            timerEnemy->start(2500);
//        }
//    }

    // spawn the enemies
    QTimer * timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(objectSpawn()));

    timerEnemy->start(2500);

    QTimer * timerThinBg = new QTimer();
    QObject::connect(timerThinBg,SIGNAL(timeout()),player,SLOT(thinBgLSpawn()));
    QObject::connect(timerThinBg,SIGNAL(timeout()),player,SLOT(thinBgRSpawn()));



    timerThinBg->start(15000);
    //QObject::connect(timerBg,SIGNAL(timeout()),player,SLOT(bgLSpawn()));
    //QObject::connect(timerBg,SIGNAL(timeout()),player,SLOT(bgRSpawn()));

    //timerBg->start(100);

    // show the page
    show();
}
