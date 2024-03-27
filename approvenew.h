#ifndef APPROVENEW_H
#define APPROVENEW_H

#include <QDialog>

namespace Ui {
class approveNew;
}

class approveNew : public QDialog
{
    Q_OBJECT

public:
    explicit approveNew(QWidget *parent = nullptr);
    ~approveNew();

private:
    Ui::approveNew *ui;
};

#endif // APPROVENEW_H
