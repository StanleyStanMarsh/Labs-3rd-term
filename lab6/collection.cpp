#include "collection.h"


Collection::Collection()
{
    wdgts.resize(0);
}

void Collection::newWidget() {
    QWidget* wdgt;
    switch (rand() % 5) {
    case 0:
        wdgt = new Label;
        break;
    case 1:
        wdgt = new QSlider;
        break;
    case 2:
        wdgt = new QScrollBar;
        break;
    case 3:
        wdgt = new QSpinBox;
        break; //QDial
    case 4:
        wdgt = new QDial;
    }
    if (wdgts.size() != 0)
        bindWidget(wdgt);

    wdgts.push_back(wdgt);
}

void Collection::bindWidget(QWidget* widget) {
    QObject::connect(widget, SIGNAL(valueChanged(int)), wdgts[wdgts.size() - 1], SLOT(setValue(int)));
    QObject::connect(wdgts[wdgts.size() - 1], SIGNAL(valueChanged(int)), widget, SLOT(setValue(int)));

}
