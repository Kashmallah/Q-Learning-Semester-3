#include "testr.h"
#include "ui_testr.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include<QtGui>
#include<QtCore>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTextStream>
#include <QBuffer>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QEvent>
#include <QWindowStateChangeEvent>
#include<QComboBox>
QString user_answer;
void processAnswer(const QString& answer);
Testr::Testr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Testr)
{
    ui->setupUi(this);
   /* QNetworkAccessManager Manager;

    QUrl APIurl("https://api..country.is/9.9.9.9");
    QNetworkRequest request(APIurl);

    QNetworkReply *reply = Manager.get(request);

    QEventLoop loop;
    connect(reply,&QNetworkReply::finished,loop,&QEventLoop::quit);
    loop.exec();*/
    ui->tabWidget->setCurrentIndex(0);
    //tabWidget->setTabEnabled(tabWidget->indexOf(tab1), true);
    //ui->tabWidget->setTabEnabled(0,false);
    ui->comboBox->addItem("Easy");
    ui->comboBox->addItem("Medium");
    ui->comboBox->addItem("Hard");
}

const QString API_KEY = "sk-proj-QtweLttwLKemmK0ai9xnT3BlbkFJhunmlvzeMR7Ro8QccD5T";
const QString API_ENDPOINT = "https://api.openai.com/v1/engines/text-davinci-003/completions";
QStringList questions;
int counter_question = 0;
int counter_answer = 1;
int total_answers= 5;
QString recognized_name = "abdullah";
QString diff;
QString subject;

Testr::~Testr()
{
    delete ui;
}
void processAnswer(const QString& answer)
{
    // Open the answers file for appending
    QFile file("answers.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open the answers file for appending:" << file.errorString();
        return;
    }

    // Append the counter to the beginning of the answer string
    QString answerWithCounter = QString::number(counter_answer) + " " + answer;

    // Check if the counter is greater than the total_answers
    if (counter_answer > total_answers)
    {
        // Empty the file
        file.resize(0);

        // Reset the counter to 1
        counter_answer = 1;
    }

    // Append the answer to the file
    QTextStream out(&file);
    out << answerWithCounter << "\n";
    counter_answer++;
    // Close the file
    file.close();
}

QString readQuestion()
{
    // Specify the file path (ai_questions.txt in the current working directory)
    QString filePath = "ai_questions.txt";

    // Open the file for reading
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading:" << file.errorString();
        return QString(); // Return an empty string on error
    }

    // Create a QTextStream for reading from the file
    QTextStream in(&file);

    // Read questions until the desired line is reached
    for (int i = 0; i < counter_question; ++i)
    {
        // Read a line from the file
        QString line = in.readLine();

        // Check if we have reached the end of the file
        if (line.isNull())
        {
            qDebug() << "Reached end of file.";
            return QString(); // Return an empty string when end of file is reached
        }
    }

    // Read the question at the specified line
    QString question = in.readLine();
    counter_question++;
    // Close the file
    file.close();

    return question;
}

QString prompt_generator(QString diff,QString sub)
{
    QString prompt;
    QVector<QString> reaction;
    reaction.push_back(diff);
    reaction.push_back(sub);
    prompt = "Suppose you are acting as a Teacher and writing Exam Questions, Generate a set of 5 questions on the topic ";
    prompt += reaction.last();
    reaction.pop_back();

    prompt += " The Difficulty level of questions should be only ";
    prompt += reaction.last();
    prompt += ". only write 5 questions nothing else.";

    reaction.pop_back();

    return prompt;
}

QString getGpt3Response(const QString& prompt) {
    QNetworkAccessManager manager;
    QNetworkRequest request((QUrl(API_ENDPOINT)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("Bearer " + API_KEY).toUtf8());
    QBuffer postDataBuffer;
    postDataBuffer.setData(QString("{\"prompt\":\"%1\",\"max_tokens\":150}").arg(prompt).toUtf8());
    postDataBuffer.open(QIODevice::ReadOnly);


    QNetworkReply* reply = manager.post(request, &postDataBuffer);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: Unable to perform the request.";
        return "Error: Unable to perform the request.";
    }

    QString result = reply->readAll();
    reply->deleteLater();

    // Parse the JSON response
    try {
        QJsonDocument response = QJsonDocument::fromJson(result.toUtf8());
        return response.object()["choices"].toArray()[0].toObject()["text"].toString();
    }
    catch (const std::exception& e) {
        qDebug() << "Error parsing JSON: " << e.what();
        return "Error: Unable to parse JSON.";
    }
}
QStringList question_seperator(const QString& questions)
{
    QStringList lines = questions.split("\n");
    qDebug() << "Questions Separated are : ";
    for (const QString& line : lines) {
        qDebug() << line;
    }

    if (lines.size() >= 5) {
        QStringList selectedQuestions = lines.mid(2, 6);
        return selectedQuestions;
        //answer_input(selectedQuestions);
    }
    else {
        qDebug() << "Error: Not enough questions generated.";
    }
    return lines;
}


void Testr::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
}


void Testr::on_pushButton_6_clicked()
{

}


void Testr::on_pushButton_7_clicked()
{

}


void Testr::on_pushButton_8_clicked()
{

}


void Testr::on_pushButton_9_clicked()
{

}





void Testr::on_pushButton_queue_clicked()
{
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,true);
    subject = "Queues";
    diff = ui->comboBox->currentText();

    QString prompt =prompt_generator(diff,subject);
    QString result = getGpt3Response(prompt);

    ui->textEdit_5->setPlainText(result);

    QThread::sleep(5);

    QStringList select = question_seperator(result);

    QString filePath = "ai_questions.txt";

    // Open the file for writing
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for writing:" << file.errorString();
        return;
    }
    QTextStream out(&file);

    for (const QString& str : select)
    {
        out << str << "\n";
    }

    file.close();
    QThread::sleep(2);

    ui->tabWidget->setCurrentIndex(2);
}

void Testr::on_pushButton_stack_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+2);
    //prompt_generator(ui->comboBox->currentText(),"Stack");
    QMessageBox::information(this,"title","Button is working");
}
void Testr::on_pushButton_linklist_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    prompt_generator(ui->comboBox->currentText(),"Linklist");
}


void Testr::on_pushButton_trees_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    prompt_generator(ui->comboBox->currentText(),"Graphs and trees");
}


void Testr::on_pushButton_4_clicked()
{
    QFile file(recognized_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);

    // Read the data from the file and insert into the table
    while (!in.atEnd())
    {
        QString s = in.readLine();
        int totalMarks = in.readLine().toInt();
        int obtainedMarks = in.readLine().toInt();
        QString difficultyLevel = in.readLine();

        // Add a new row to the table
        int row = ui->tableWidget_10->rowCount();
        ui->tableWidget_10->insertRow(row);

        ui->tableWidget_10->setItem(row, 0, new QTableWidgetItem(s));
        ui->tableWidget_10->setItem(row, 1, new QTableWidgetItem(QString::number(totalMarks)));
        ui->tableWidget_10->setItem(row, 2, new QTableWidgetItem(QString::number(obtainedMarks)));
        ui->tableWidget_10->setItem(row, 3, new QTableWidgetItem(difficultyLevel));
    }

    file.close();
}
void process_result(int m)
{
    QFile file(recognized_name);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for appending:" << file.errorString();
        return;
    }
    QTextStream out(&file);
    //out << subject << "\n";            // Write subject on one line
    //out << "50" << "\n";                // Assuming total marks are always 50
    //out << QString::number(m) << "\n";  // Write obtained marks on one line
    //out << diff << "\n";
    QString s = QString(subject);
    QString tm = QString::number(50);
    QString om = QString::number(m);
    QString d =QString(diff);


    out<<s<<"\n";
    out<<tm<<"\n";
    out<<om<<"\n";
    out<<d<<"\n";
    //file.flush();
    file.close();

}


void Testr::on_pushButton_10_clicked()
{
    ui->tabWidget->setTabEnabled(2,false);
    ui->tabWidget->setTabEnabled(3,true);
    QMessageBox::information(this,"Msg","Checking Your Paper This will take some time");
    ui->tabWidget->setCurrentIndex(3);
    ///// End the timer
    /// recall the gpt api to check the questions and store in the file system
    ///
    ///
    ///
    ///
    /// at the end empty the answers and questions file
    /// repeat the same at refresh button at results corner
    //file_empty();

    QFile questionsFileObj("ai_questions.txt");
    if (!questionsFileObj.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the questions file:" << questionsFileObj.errorString();
        return;
    }

    // Open the answers file for reading
    QFile answersFileObj("answers.txt");
    if (!answersFileObj.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the answers file:" << answersFileObj.errorString();
        return;
    }

    // Create a QTextStream for reading from the questions file
    QTextStream questionsStream(&questionsFileObj);
    // Create a QTextStream for reading from the answers file
    QTextStream answersStream(&answersFileObj);
    int marks =0;
    // Read questions and answers line by line and combine them
    while (!questionsStream.atEnd() && !answersStream.atEnd())
    {
        // Read the question
        QString question = questionsStream.readLine();
        // Read the answer (assuming the index is at the beginning of each answer)
        //QString answerIndex = answersStream.readLine();
        QString answer =answersStream.readLine();

        QString prompt;
        prompt += "Please check the questions and mark them out of 10.Remember the difficulty level is "+ diff + " ";
        prompt += ". And only return the marks, nothing else.The Question is : ";
        prompt += question ;
        prompt += " its Answer is: ";
        prompt += answer;

        QThread::sleep(12);

        QString mark = getGpt3Response(prompt);

        bool conversionOk;
        marks += mark.toInt(&conversionOk);

    }

    // Close the files
    questionsFileObj.close();
    answersFileObj.close();
    QMessageBox::information(this,"Msg","Paper checking Done");
    process_result(marks);

}


void Testr::on_pushButton_11_clicked()
{
    if(counter_answer == 5)
    {
        ui->pushButton_11->setEnabled(false);
        QMessageBox::information(this,"Message","All Questions Attempted Please Press Submit Button to View Result");
        ui->pushButton_11->setEnabled(false);
        //ui->tabWidget->setCurrentIndex(3);
    }
    user_answer = ui->textEdit_6->toPlainText();
    user_answer = user_answer.simplified();
    processAnswer(user_answer);
    ui->textEdit_6->clear();
    QString q = readQuestion();
    ui->textEdit_5->setPlainText(q);
}


void Testr::on_diff_level_2_activated(int index)
{

}

