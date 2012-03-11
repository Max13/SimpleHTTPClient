//
// mainwindow.cpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->cWidget = new QWidget(this);
    this->verticalLayout = new QVBoxLayout(this->cWidget);
    this->formLayout = new QFormLayout;
    this->horizontalLayout = new QHBoxLayout;
    this->urlBox = new QLineEdit(this->cWidget);
    this->bodyBox = new QLineEdit(this->cWidget);
    this->methodBox = new QComboBox(this->cWidget);
    this->resetButton = new QPushButton(tr("Reset"), this->cWidget);
    this->submitButton = new QPushButton(tr("Submit"), this->cWidget);
    //this->bodyField = new QTextEdit(this->cWidget);
    this->respField = new QTextEdit(this->cWidget);
    this->httpClient = new HttpManager;

    this->cWidget->setLayout(this->verticalLayout);
    this->verticalLayout->addLayout(this->formLayout);
    this->verticalLayout->addLayout(this->horizontalLayout);
    this->verticalLayout->addWidget(this->respField);
    this->formLayout->addRow(tr("URL"), this->urlBox);
    this->formLayout->addRow(tr("Parameters"), this->bodyBox);
    this->formLayout->addRow(tr("Method"), this->methodBox);
    this->horizontalLayout->addWidget(this->resetButton);
    this->horizontalLayout->addWidget(this->submitButton);

    this->urlBox->setPlaceholderText(tr("URL of the resource"));
    this->methodBox->addItem("HEAD");
    this->methodBox->addItem("GET");
    this->methodBox->addItem("PUT");
    this->methodBox->addItem("POST");
    this->methodBox->addItem("DELETE");
    this->methodBox->addItem("CUSTOM");
    this->methodBox->setCurrentIndex(1);

    this->setCentralWidget(this->cWidget);

    connect(methodBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(methodChanged(QString)));
    connect(httpClient->getNetManager(), SIGNAL(finished(QNetworkReply*)), this, SLOT(showReceivedData(QNetworkReply*)));
    this->connect(this->submitButton, SIGNAL(clicked()), this, SLOT(proceedRequest()));
}

void MainWindow::proceedRequest()
{
    this->httpClient->proceedRequest(this->methodBox->currentText(), this->urlBox->text(), this->bodyBox->text().toAscii());
}

void MainWindow::showReceivedData(QNetworkReply *reply)
{
    qDebug() << "Finished emitted. Data received.";
    qDebug() << "Data Size: " << reply->size();
    this->respField->setPlainText(reply->readAll());
    reply->close();
}

void MainWindow::methodChanged(QString newMethodName)
{
    if (newMethodName == QString("CUSTOM"))
        this->methodBox->setEditable(true);
    else if (this->methodBox->isEditable())
        this->methodBox->setEditable(false);
}
