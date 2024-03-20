#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_registerNew_clicked();

    void on_listExisting_clicked();

    void on_adminLogin_clicked();

    void on_mapExisting_clicked();

private:
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
