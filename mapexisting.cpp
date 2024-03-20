#include "mapexisting.h"
#include "ui_mapexisting.h"
#include <QPixmap>

mapExisting::mapExisting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mapExisting)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/ireland.png");
    int w = ui->label_pix->width();
    int h = ui->label_pix->height();
    ui->label_pix->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

mapExisting::~mapExisting()
{
    delete ui;
}
