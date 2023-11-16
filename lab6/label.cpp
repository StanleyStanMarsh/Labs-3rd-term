#include "label.h"

Label::Label(QWidget *parent): QLabel(parent) {}

void Label::setValue(int i) {
    if (QString::number(i) != text()) {
        this->setNum(i);
        emit valueChanged(i);
    }
}
