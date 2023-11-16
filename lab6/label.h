#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr);
signals:
    void valueChanged(int);

public slots:
    void setValue(int);
};

#endif // LABEL_H
