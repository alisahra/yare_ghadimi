#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class BackGround :public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    BackGround();
    BackGround(int a);
public slots:
    void checkColl();
private:
    static int randNum;
    static bool changeRandNum;
};

#endif // BACKGROUND_H
