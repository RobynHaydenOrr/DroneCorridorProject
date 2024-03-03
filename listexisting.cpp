#include "listexisting.h"
#include "ui_listexisting.h"

listExisting::listExisting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listExisting)
{
    ui->setupUi(this);
}

listExisting::~listExisting()
{
    delete ui;
}
