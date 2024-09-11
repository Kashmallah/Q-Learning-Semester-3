#include "ssqueue.h"
#include "ui_ssqueue.h"
qint16 i = 0;

SSqueue::SSqueue(QWidget *parent)
    : QWidget(parent),
     ui(new Ui::SSqueue),
currentValue(0) // Initialize currentValue to 0
{
    ui->setupUi(this);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setSpacing(10);
    ui->listWidget_2->setFlow(QListView::LeftToRight);
    ui->listWidget_2->setSpacing(10);
}

SSqueue::~SSqueue()
{
    delete ui;
}

void SSqueue::on_lcdNumber_overflow()
{
    // Handle the overflow case here if necessary
    // For example, reset the value or show a warning
    // In this example, we just reset the currentValue to 0
    currentValue = 0;
    ui->lcdNumber->display(currentValue);
}

void SSqueue::on_pushButton_clicked()
{
    // Get the input text and clear the line edit
    QString value = ui->lineEdit->text();
    if (!value.isEmpty()) {
        // Add the text to the end of the list
        ui->listWidget->addItem(value);
        ui->listWidget_2->addItem(QString::number(i));
        i = i + 1;
        ui->lineEdit->clear();

        // Increase the LCD number by 1
        currentValue++;
        ui->lcdNumber->display(currentValue);
    }
}

void SSqueue::on_pushButton_2_clicked()
{
    // Remove the first item in the list if it exists
    if (ui->listWidget->count() > 0) {
        delete ui->listWidget->takeItem(0);
        delete ui->listWidget_2->takeItem(0);

        // Update currentValue to reflect the actual number of items in the list
        currentValue = ui->listWidget->count();
        ui->lcdNumber->display(currentValue);

        // Reset the counter i to 0
        i = 0;
    }
}
