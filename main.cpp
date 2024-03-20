#include "mainmenu.h"
#include <QDebug>
#include <QtSql>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
