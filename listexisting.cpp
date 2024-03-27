#include "listexisting.h"
#include "ui_listexisting.h"

listExisting::listExisting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listExisting)
{
    ui->setupUi(this);

    QSqlDatabase corridorData=QSqlDatabase::addDatabase("QSQLITE");
    corridorData.setDatabaseName("c:/Users/robyn/Desktop/College Project/QtDroneCorridorProject/DroneCorridorProject/db/corridorDB.db");

    if(!corridorData.open())
    {
        ui->dbCheck->setText("DB Not Connected");
    }
    else
    {
        ui->dbCheck->setText("DB Connected");
    }
}

listExisting::~listExisting()
{
    delete ui;
}

void listExisting::on_refreshTable_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();

    //QSqlQuery* qry = new QSqlQuery(corridorData);

    QSqlQuery qry;
    qry.prepare("select name, start, end from corridorData where approved=1");
    qry.exec();

    modal->setQuery(qry);
    ui->corridorTable->setModel(modal);
}

