#ifndef MAPEXISTING_H
#define MAPEXISTING_H

#include <QDialog>

namespace Ui {
class mapExisting;
}

class mapExisting : public QDialog
{
    Q_OBJECT

public:
    explicit mapExisting(QWidget *parent = nullptr);
    ~mapExisting();

private:
    Ui::mapExisting *ui;
};

#endif // MAPEXISTING_H
