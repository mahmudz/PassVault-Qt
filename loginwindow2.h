#ifndef LOGINWINDOW2_H
#define LOGINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class LoginWindow2;
}

class LoginWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow2(QWidget *parent = nullptr);
    ~LoginWindow2();

private:
    Ui::LoginWindow2 *ui;
};

#endif // LOGINWINDOW2_H
