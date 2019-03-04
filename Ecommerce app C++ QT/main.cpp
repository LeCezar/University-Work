#include "mainwindow.h"
#include "adminhud.h"
#include <QApplication>
#include "UI.h"
#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    Controller c;
    MainWindow w;
    w.show();
//    AdminHUD ah(&c);
//    ah.show();


//    testRepo();
//    testController();

//    UI ui;
//    ui.start();


    return a.exec();
}
