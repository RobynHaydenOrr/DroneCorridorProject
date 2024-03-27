#include "mainmenu.h"
#include "adminlogin.h"
#include "listexisting.h"
#include "mapexisting.h"
#include "registernew.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QSqlDatabase corridorData=QSqlDatabase::addDatabase("QSQLITE");
    corridorData.setDatabaseName("c:/Users/robyn/Desktop/College Project/QtDroneCorridorProject/DroneCorridorProject/db/corridorDB.db");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_registerNew_clicked()
{
    registerNew registerNew;
    registerNew.setModal(true);
    registerNew.exec();
}


void MainMenu::on_listExisting_clicked()
{
    listExisting listExisting;
    listExisting.setModal(true);
    listExisting.exec();
}


void MainMenu::on_adminLogin_clicked()
{
    adminLogin adminLogin;
    adminLogin.setModal(true);
    adminLogin.exec();
}


void MainMenu::on_mapExisting_clicked()
{
    mapExisting mapExisting;
    mapExisting.setModal(true);
    mapExisting.exec();
}

