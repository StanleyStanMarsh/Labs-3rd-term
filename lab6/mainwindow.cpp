#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    lay = new QGridLayout(this);
    clt = new Collection;

    btn1 = new QPushButton("make");
    QObject::connect(btn1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
    lay->addWidget(btn1);

    btn2 = new QPushButton("delete");
    QObject::connect(btn2, SIGNAL(clicked()), this, SLOT(button2_clicked()));
    lay->addWidget(btn2);
}

MainWindow::~MainWindow()
{
    delete lay;
    delete clt;
    delete btn1;
    delete btn2;
}

void MainWindow::button1_clicked() {
    clt->newWidget();
    lay->addWidget(clt->wdgts[clt->wdgts.size() - 1]);
}

void MainWindow::button2_clicked() {
    if (clt->wdgts.size() == 0) return;

    lay->removeWidget(clt->wdgts[clt->wdgts.size() - 1]);
    delete clt->wdgts[clt->wdgts.size() - 1];
    clt->wdgts.pop_back();
}
