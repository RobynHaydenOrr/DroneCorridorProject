#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "approvenew.h"

namespace Ui {
class adminLogin;
}

class adminLogin : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase corridorData;
    void connClose()
    {
        corridorData.close();
        corridorData.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        QSqlDatabase corridorData=QSqlDatabase::addDatabase("QSQLITE");
        corridorData.setDatabaseName("c:/Users/robyn/Desktop/College Project/QtDroneCorridorProject/DroneCorridorProject/db/corridorDB.db");

        if(!corridorData.open())
        {
            qDebug()<<("DB Not Connected");
            return false;
        }
        else
        {
            qDebug()<<("DB Connected");
            return true;
        }
    }

public:
    explicit adminLogin(QWidget *parent = nullptr);
    ~adminLogin();

private slots:
    //void on_submit_clicked();

    void on_submitLogin_clicked();

private:
    Ui::adminLogin *ui;
};

#endif // ADMINLOGIN_H
