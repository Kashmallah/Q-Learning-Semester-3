#include "bubblesort.h"
#include "ui_bubblesort.h"

Bubblesort::Bubblesort(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Bubblesort)

{
    m_numbers = QVector<int>();
    ui->setupUi(this);

    setupListWidgets();
}


Bubblesort::~Bubblesort()
{
    delete ui;
}
void Bubblesort::setupListWidgets()
{
    // Set the flow and wrapping for listWidget and listWidget2 to listWidget7
    QListWidget* listWidgets[] = {ui->listWidget, ui->listWidget_2, ui->listWidget_3, ui->listWidget_4, ui->listWidget_5, ui->listWidget_6, ui->listWidget_7};
    for(QListWidget* listWidget : listWidgets) {
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setWrapping(true);
    }
}

void Bubblesort::on_pushButton_clicked()
{
    bool ok;
    int number = ui->lineEdit->text().toInt(&ok);
    if(ok) {
        m_numbers.append(number);
        ui->listWidget->addItem(QString::number(number));
        ui->lineEdit->clear();
    }
    // Call the bubble sort step-by-step function
    bubbleSortStepByStep();
}

void Bubblesort::bubbleSortStepByStep()
{
    QVector<int> tempNumbers = m_numbers;

    // Step 1: Initial array state (shown in listWidget2)
    updateListWidget(ui->listWidget_2, tempNumbers);

    int n = tempNumbers.size();
    int step = 1;

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempNumbers[j] > tempNumbers[j + 1]) {
                // Swap if the current element is greater than the next element
                qSwap(tempNumbers[j], tempNumbers[j + 1]);
            }

            // Update the list widget for each comparison and swap step
            switch (step) {
            case 1: updateListWidget(ui->listWidget_3, tempNumbers); break;
            case 2: updateListWidget(ui->listWidget_4, tempNumbers); break;
            case 3: updateListWidget(ui->listWidget_5, tempNumbers); break;
            case 4: updateListWidget(ui->listWidget_6, tempNumbers); break;
            case 5: updateListWidget(ui->listWidget_7, tempNumbers); break;
            }

            step++;
            if (step > 5) return;  // Only handle up to 5 steps
        }
    }
}

void Bubblesort::updateListWidget(QListWidget *listWidget, const QVector<int> &numbers)
{
    listWidget->clear();
    for (int number : numbers) {
        listWidget->addItem(QString::number(number));
    }
}
