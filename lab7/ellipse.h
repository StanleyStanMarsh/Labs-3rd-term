#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QBrush>

class Ellipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    QVector<QAbstractGraphicsShapeItem*> *figures;
public:
    Ellipse(qreal x, qreal y, qreal w, qreal h, QVector<QAbstractGraphicsShapeItem*> *figs,
            QGraphicsItem *parent = nullptr) :
        QGraphicsEllipseItem(x, y, w, h, parent) { figures = figs; }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    void to_front();
};

#endif // ELLIPSE_H
