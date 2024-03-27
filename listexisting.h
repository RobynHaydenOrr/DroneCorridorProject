#ifndef LISTEXISTING_H
#define LISTEXISTING_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class listExisting;
}

class listExisting : public QDialog
{
    Q_OBJECT

public:
    explicit listExisting(QWidget *parent = nullptr);
    ~listExisting();

private slots:
    void on_pushButton_clicked();

    void on_refreshTable_clicked();

private:
    Ui::listExisting *ui;
};

#endif // LISTEXISTING_H
