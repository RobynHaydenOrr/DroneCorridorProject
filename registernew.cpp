#include "registernew.h"
#include "ui_registernew.h"
#include <QMessageBox>
#include "mainmenu.h"

registerNew::registerNew(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerNew)
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

registerNew::~registerNew()
{
    delete ui;
}

void registerNew::on_submit_clicked()
{
    QString corridorName, corridorStart, corridorEnd;
    corridorName = ui->name->text();
    corridorStart = ui->start->text();
    corridorEnd = ui->end->text();

    QSqlQuery qry;
    qry.prepare("insert into corridorData (name, start, end) values ('"+corridorName+"', '"+corridorStart+"', '"+corridorEnd+"')");

    if(!qry.exec()) {

        QMessageBox::warning(this, "Error!", "There was a problem with your request.");
    }
    else {
        QMessageBox::information(this, "Success!", "Corridor Request Submitted.");
    }
}

