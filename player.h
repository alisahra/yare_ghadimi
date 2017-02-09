#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class myPlayer :public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    myPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void twoWaysBgSpawn();
    void thinBgLSpawn();
    void thinBgRSpawn();
public slots:
    void objectSpawn();
    void bgSwapn();

};

#endif // PLAYER_H
