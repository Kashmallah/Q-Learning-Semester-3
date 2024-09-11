#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Implement the button click functionality for pushButton here
    s.show();
}

void MainWindow::on_pushButton_5_clicked()
{
    // Implement the button click functionality for pushButton_5 here
}

void MainWindow::on_pushButton_6_clicked()
{
    //l.show();
}
