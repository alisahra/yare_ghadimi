#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Rect :public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Rect();
};



#endif // RECT_H
