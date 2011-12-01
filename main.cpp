#include <QtGui/QApplication>
#include "mainwindow.h"
#include "donneurgraphique.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    w.showMaximized();
    return a.exec();
}
