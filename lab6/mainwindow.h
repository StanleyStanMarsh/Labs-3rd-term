#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "collection.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Collection *clt;
    QGridLayout *lay;

    QPushButton *btn1;
    QPushButton *btn2;

private slots:
    void button1_clicked();
    void button2_clicked();
};

#endif // MAINWINDOW_H
