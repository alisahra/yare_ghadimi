#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class myPlayer :public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    myPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void enemySpawn();
    void thinBgLSpawn();
    void thinBgRSpawn();
    void twoWaysBgSpawn();
};

#endif // PLAYER_H
