#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainmenu.h"

adminLogin::adminLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminLogin)
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

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_submitLogin_clicked()
{
    QString username, password;
    username=ui->inputName->text();
    password=ui->inputPass->text();

    if(!corridorData.open())
    {
        ui->dbCheck->setText("DB Not Connected");
    }
    else
    {
        ui->dbCheck->setText("DB Connected");
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from adminLogin where username='"+ username +"' and password='"+password+"'");

    if(qry.exec())
    {
        int count;
        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            ui->dbCheck->setText("Correct!");
            connClose();
            this->hide();
            approveNew approveNew;
            approveNew.setModal(true);
            approveNew.exec();
        }
        if(count > 1)
        {
            ui->dbCheck->setText("Duplicate!");
        }
        if(count < 1)
        {
            ui->dbCheck->setText("Incorrect");
        }
    }
}

