#include "mainwindow.h"

#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    w.show();
    return a.exec();
}
