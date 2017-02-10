#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include "thinbackground.h"
#include <QProgressBar>
//#include <fstream>
//#include <iostream>
//#include <string>
#include <QFile>
#include"puasepage.h"
PuasePage * puasepage;

//using namespace std;

Game::Game(){
    singelton = true;
    // create a scene
    scene = new QGraphicsScene();
    setScene(scene);
    // set scrolbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    QString line;
//    ifstream levelFile ("level.txt");
//    getline(levelFile,line);

//    int lev = line.toInt();

    QFile levelF("level.txt");
    QTextStream in(&levelF);
    QString line = in.readLine();
    int lev = line.toInt();
    levelF.close();

    // set level
    level = new Level(lev);

    // health
    QTimer * hTimer = new QTimer();
    health = new Health();
    health->setPos(health->x()+100,health->y() + 30);
    QObject::connect(hTimer, SIGNAL(timeout()),health,SLOT(decrease()));
    scene->addItem(health);
    hTimer->start(100);

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
//    belowScene->setSceneRect(0,600,800,200);


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

   // unsigned int i = 0;
    timerEnemy = new QTimer();

    QTimer * t = new QTimer();
    QObject::connect(t,SIGNAL(timeout()),player,SLOT(thinBgLSpawn()));
    QObject::connect(t,SIGNAL(timeout()),player,SLOT(thinBgRSpawn()));
    t->start(30000);

    QTimer * tw = new QTimer();
    QObject::connect(tw,SIGNAL(timeout()),player,SLOT(twoWaysBgSpawn()));
    tw->start(20000-(100*lev));

    QTimer * enemyTimer = new QTimer();
    QObject::connect(enemyTimer,SIGNAL(timeout()),player,SLOT(objectSpawn()));
    enemyTimer->start(2500-(100*lev));

    QTimer * playerTimer = new QTimer();
    QObject::connect(playerTimer,SIGNAL(timeout()),player,SLOT(settingPixmap()));
    playerTimer->start(200);

    QObject::connect(player,SIGNAL(thinBgCreated()),level,SLOT(incLvl()));

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

void Game::setLevel(int value)
{
    level->setLvl(value);
}

int Game::getSpeed()
{
    return level->getSpeed();
}

void Game::incLevel()
{
    level->incLvl();
}

void Game::gamePuase()
{
    puasepage = new PuasePage();
    puasepage->show();
}
void Game::gameOver()
{
    delete player;
}
