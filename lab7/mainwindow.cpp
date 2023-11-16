#include "mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
{
    figs.resize(0);

    this->resize(600, 500);

    main_grid = new QGridLayout(this);

    add_fig = new QPushButton("Добавить фигуру");
    QObject::connect(add_fig, SIGNAL(clicked(bool)), this, SLOT(add_fig_clicked()));
    main_grid->addWidget(add_fig, 0, 0);

    del_fig = new QPushButton("Удалить фигуру");
    QObject::connect(del_fig, SIGNAL(clicked(bool)), this, SLOT(del_fig_clicked()));
    main_grid->addWidget(del_fig, 1, 0);

    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setScene(scene);
    main_grid->addWidget(view, 2, 0);
}

void Mainwindow::add_fig_clicked() {
    QAbstractGraphicsShapeItem* abstr_fig;
    switch (rand() % 3) {
    case 0:
        abstr_fig = new Ellipse(rand() % 200, rand() % 200, 30, 30, &figs);
        break;
    case 1:
        abstr_fig = new Rectangle(rand() % 200, rand() % 200, 30, 40, &figs);
        break;
    case 2:
        QPolygonF pol;
        QPointF first(-30, 0);
        QPointF second(0, -40);
        QPointF third(30, 0);
        pol << first << second << third << first;
        abstr_fig = new Triangle(pol, &figs);
        abstr_fig->setPos(rand() % 200, rand() % 200);
        break;
    }
    abstr_fig->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    abstr_fig->setFlag(QGraphicsItem::ItemIsMovable, true);
    abstr_fig->setFlag(QGraphicsItem::ItemIsSelectable, true);

    figs.push_back(abstr_fig);
    scene->addItem(abstr_fig);
}

void Mainwindow::del_fig_clicked() {
    if (figs.isEmpty()) return;
    for (auto c: scene->selectedItems()) {
        scene->removeItem(c);
        for (int i = 0; i < figs.size(); i++) {
            if (figs[i] == c) {
                figs.removeAt(i);
                break;
            }
        }
    }
}

Mainwindow::~Mainwindow()
{
    delete main_grid;
    delete scene;
    delete view;
    delete add_fig;
    delete del_fig;
}

