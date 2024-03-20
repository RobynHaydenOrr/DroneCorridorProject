#ifndef LISTEXISTING_H
#define LISTEXISTING_H

#include <QDialog>

namespace Ui {
class listExisting;
}

class listExisting : public QDialog
{
    Q_OBJECT

public:
    explicit listExisting(QWidget *parent = nullptr);
    ~listExisting();

private:
    Ui::listExisting *ui;
};

#endif // LISTEXISTING_H
