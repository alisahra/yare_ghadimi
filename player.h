#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class myPlayer :public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    myPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void thinBgLSpawn();
    void thinBgRSpawn();
    void twoWaysBgSpawn();
public slots:
    void objectSpawn(int mov);
};

#endif // PLAYER_H
