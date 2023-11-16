#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(0, 0, 400, 400);
    w.show();
    return a.exec();
}
