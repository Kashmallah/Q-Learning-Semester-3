#include "stack.h"
#include "ui_stack.h"
#include<QListView>
#include<QStringListModel>
#include <QListWidgetItem>
#include<QListWidget>
Stack::Stack(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Stack)
{
    ui->setupUi(this);
    ui->listView->setDragEnabled(true);
    ui->listView->setAcceptDrops(true);
    ui->listView->setDropIndicatorShown(true);
    ui->listView->setDefaultDropAction(Qt::MoveAction);

    ui->listView->setStyleSheet("QListView { font-family:verdana; font-size: 13pt; font-weight: bold}"
                                "QListView { background-color:#C0392B;color:white ; padding: 10%}"
                                "QlistView{border: 4px solid #C0392B;}"
                                "QListView::item{background-color: #EA0949}"
                                "QListView::item::hover{background-color: #C0392B}");

    connect(ui->pushButton, &QPushButton::clicked, this, &Stack::pushItem);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Stack::popItem);
}

Stack::~Stack()
{
    delete ui;
}

void Stack::on_pushButton_clicked()
{
  //  QString text = ui->txtText->text();
    //if (!text.isEmpty()) {
      //  ui->listView->addItem(text);
      //  ui->txtText->clear();
      //  ui->txtText->setFocus();
    //}

}


void Stack::on_pushButton_2_clicked()
{
   // if (ui->listView->count() > 0) {
     //   delete ui->listView->takeItem(ui->listView->count() - 1);
    //}
}
void Stack::pushItem()
{
    QString text = ui->txtText->text();
    if (!text.isEmpty()) {
        ui->listView->addItem(text);
        // Increase LCD number by 1 when pushing
        ui->lcdNumber->display(ui->lcdNumber->intValue() + 1);
        ui->txtText->clear();
        ui->txtText->setFocus();
    }
}

void Stack::popItem()
{
    if (ui->listView->count() > 0) {
        delete ui->listView->takeItem(ui->listView->count() - 1);
        // Decrease LCD number by 1 when popping
        ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);
    }
}
