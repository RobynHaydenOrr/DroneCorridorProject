#include "registernew.h"
#include "ui_registernew.h"
#include <QMessageBox>

registerNew::registerNew(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerNew)
{
    ui->setupUi(this);
}

registerNew::~registerNew()
{
    delete ui;
}

void registerNew::on_submit_clicked()
{
    QString corridorName = ui->name->text();
    QString corridorStart = ui->start->text();
    QString corridorEnd = ui->end->text();

    if(corridorName == "NULL" && corridorStart == "NULL" && corridorEnd == "NULL") {

        QMessageBox::warning(this, "Error!", "There was a problem with your request.");
    }
    else {
        QMessageBox::information(this, "Success!", "Corridor Request Submitted.");
    }
}

