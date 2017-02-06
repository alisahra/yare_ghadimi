#include "game.h"

Game::Game(QWidget *parent)
{
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

    // set the item position and area
    player->setRect(0,0,50,100);

    // add item to the scene
    scene->addItem(player);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // show the page
    //view->show();

    // set the scene and view with eachOther
    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    // set the location of player
    player->setPos((width()/2) - (player->rect().width()/2) , height() - player->rect().height());

    // score
    score = new Score();
    scene->addItem(score);

    // health
    health = new Health();
    health->setPos(health->x(),health->y() + 30);
    scene->addItem(health);

    // spawn the enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

    timer->start(3000);

    show();
}
