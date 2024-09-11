#include "select.h"
#include "ui_select.h"
Select::Select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Select)
{
    ui->setupUi(this);
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    s.show();
}


void Select::on_pushButton_2_clicked()
{
    //b.show();
}


void Select::on_pushButton_3_clicked()
{
    //e.show();
}


void Select::on_pushButton_4_clicked()
{
    ss.show();
}

