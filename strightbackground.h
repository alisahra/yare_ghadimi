#ifndef STRIGHTBACKGROUND_H
#define STRIGHTBACKGROUND_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class StrightBackGround :public QObject,public QGraphicsRectItem {
    Q_OBJECT
public:
    StrightBackGround();
    StrightBackGround(int a);
public slots:
    void move();
private:
    static int randNum;
    static bool changeRandNum;
};

#endif // STRIGHTBACKGROUND_H
