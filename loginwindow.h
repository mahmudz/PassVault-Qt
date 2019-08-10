#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_LoginBTN_clicked();

    void on_exitBTN_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
