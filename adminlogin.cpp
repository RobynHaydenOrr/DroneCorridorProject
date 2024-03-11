#include "adminlogin.h"
#include "ui_adminlogin.h"

adminlogin::adminlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminlogin)
{
    ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}
