#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>

class Rectangle : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    QVector<QAbstractGraphicsShapeItem*> *figures;
public:
    Rectangle(qreal x, qreal y, qreal w, qreal h, QVector<QAbstractGraphicsShapeItem*> *figs,
              QGraphicsItem *parent = nullptr) :
    QGraphicsRectItem(x, y, w, h, parent) { figures = figs; }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void to_front();
};

#endif // RECTANGLE_H
