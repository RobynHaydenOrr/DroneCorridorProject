#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
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
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_registerNew_clicked();

    void on_listExisting_clicked();

    void on_adminLogin_clicked();

    void on_mapExisting_clicked();

private:
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
