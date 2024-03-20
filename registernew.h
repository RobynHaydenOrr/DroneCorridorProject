#ifndef REGISTERNEW_H
#define REGISTERNEW_H

#include <QDialog>

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
