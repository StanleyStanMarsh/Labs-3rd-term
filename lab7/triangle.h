#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QBrush>

class Triangle : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
    QVector<QAbstractGraphicsShapeItem*> *figures;
public:
    Triangle(const QPolygonF &polygon, QVector<QAbstractGraphicsShapeItem*> *figs,
             QGraphicsItem *parent = nullptr) :
        QGraphicsPolygonItem(polygon, parent) { figures = figs; }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void to_front();
};

#endif // TRIANGLE_H
