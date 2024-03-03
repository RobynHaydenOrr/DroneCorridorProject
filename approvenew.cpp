#include "approvenew.h"
#include "ui_approvenew.h"

approveNew::approveNew(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::approveNew)
{
    ui->setupUi(this);
}

approveNew::~approveNew()
{
    delete ui;
}
