#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "mainwindow.h"

#include <QSqlQuery>


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE" , "LoginConnection");
    db.setDatabaseName(".\\db.sqlite");
    db.open();


}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginBTN_clicked()
{

    QSqlQuery query("SELECT * FROM users WHERE email = :email LIMIT 1 ");
    query.bindValue(":email", ui->inLogin->text());


    if(!query.exec())
    {
        qDebug() << "Can't Execute Query !";
    }
    else
    {
        qDebug() << "Query Executed Successfully !";
        if(query.size() == 1)
        {
            QString email, password;
            while (query.next()) {
                email = query.value(1).toString();
                password = query.value(2).toString();
            }

            qDebug() << email;
            qDebug() << password;

        }
    }

//    MainWindow *mw = new MainWindow();
//    mw->show();
//    close();
}

void LoginWindow::on_exitBTN_clicked()
{
    this->close();
}
