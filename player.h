#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class myPlayer :public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    myPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    ~myPlayer();
public slots:
    void objectSpawn();
    void twoWaysBgSpawn();
    void thinBgLSpawn();
    void thinBgRSpawn();
    void settingPixmap();

signals:
    void thinBgCreated();

//private:
//    int speed;

};

#endif // PLAYER_H
