#ifndef COLLECTION_H
#define COLLECTION_H
#include <QWidget>
#include <vector>
#include "label.h"
#include <QSlider>
#include <QScrollBar>
#include <QSpinBox>
#include <QDial>

class Collection
{
private:
    void bindWidget(QWidget* widget);

public:
    std::vector <QWidget*> wdgts;

    Collection();

    void newWidget();
};

#endif // COLLECTION_H
