#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "md5.h"
#include "sha256.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
