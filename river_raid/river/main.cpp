#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create a view
    QGraphicsView * view = new QGraphicsView(scene);

    // create item
    myPlayer * my_player = new myPlayer();

    // set the item position and area
    my_player->setRect(0,0,50,100);

    // add item to the scene
    scene->addItem(my_player);

    // make item focusable
    my_player->setFlag(QGraphicsItem::ItemIsFocusable);
    my_player->setFocus();

    view->show();

    return a.exec();
}
