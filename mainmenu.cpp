#include "mainmenu.h"
#include "./ui_mainmenu.h"
#include "approvenew.h"
#include "mapexisting.h"
#include "registernew.h"
#include "listexisting.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
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


void MainMenu::on_approveNew_clicked()
{
    approveNew approveNew;
    approveNew.setModal(true);
    approveNew.exec();
}


void MainMenu::on_mapExisting_clicked()
{
    mapExisting mapExisting;
    mapExisting.setModal(true);
    mapExisting.exec();
}

