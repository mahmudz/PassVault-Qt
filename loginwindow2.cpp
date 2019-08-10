#include "loginwindow2.h"
#include "ui_loginwindow2.h"

LoginWindow2::LoginWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow2)
{
    ui->setupUi(this);
}

LoginWindow2::~LoginWindow2()
{
    delete ui;
}
