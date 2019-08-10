#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->deleteBTN->setEnabled(false);
    ui->editBTN->setEnabled(false);

    db = QSqlDatabase::addDatabase("QSQLITE" , "MainConnection");
    db.setDatabaseName(".\\db.sqlite");
    if(!db.open()) {
        qDebug() << "Can't Connect to DB !";
    }
    else {
        qDebug() << "Connected Successfully to DB !";
    }


}

MainWindow::~MainWindow()
{
//    delete ui;
}

void MainWindow::on_addBTN_clicked()
{

    QString website = ui->inWebsite->text();
    QString email = ui->inEmail->text();
    QString username = ui->inUsername->text();
    QString password = ui->inPasswrod->text();

    if ((website != "" || password != "") && (email != "" || username != "")) {

        int rowCount = ui->dataTable->rowCount();
        ui->dataTable->insertRow(rowCount);
        ui->dataTable->setItem(rowCount, 0, new QTableWidgetItem(website));
        ui->dataTable->setItem(rowCount, 1, new QTableWidgetItem(email));
        ui->dataTable->setItem(rowCount, 2, new QTableWidgetItem(username));
        ui->dataTable->setItem(rowCount, 3, new QTableWidgetItem(password));

        ui->inWebsite->setText("");
        ui->inEmail->setText("");
        ui->inUsername->setText("");
        ui->inPasswrod->setText("");
    }else{
        QMessageBox msgBox;
        msgBox.setText("Please fill all the fields.");
        msgBox.exec();

    }


}

void MainWindow::on_deleteBTN_clicked()
{
    QModelIndexList selection = ui->dataTable->selectionModel()->selectedRows();

    for(int i=0; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        ui->dataTable->removeRow(index.row());
    }

}

void MainWindow::on_dataTable_itemSelectionChanged()
{
    ui->deleteBTN->setEnabled(true);
    ui->editBTN->setEnabled(true);
}
