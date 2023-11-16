#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QAbstractGraphicsShapeItem>
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"

class Mainwindow : public QWidget
{
    Q_OBJECT

    QGridLayout *main_grid;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPushButton *add_fig;
    QPushButton *del_fig;

    QVector<QAbstractGraphicsShapeItem*> figs;
public:
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();
private slots:
    void add_fig_clicked();
    void del_fig_clicked();
};
#endif // MAINWINDOW_H
