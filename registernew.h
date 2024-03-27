#ifndef REGISTERNEW_H
#define REGISTERNEW_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class registerNew;
}

class registerNew : public QDialog
{
    Q_OBJECT

public:
    explicit registerNew(QWidget *parent = nullptr);
    ~registerNew();

private slots:
    void on_submit_clicked();

private:
    Ui::registerNew *ui;
};

#endif // REGISTERNEW_H
