//
// main.cpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#include <QDebug>
#include <QtGui/QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "httpmanager.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow *w;
    QWidget *widget;
    QFormLayout *flayout;
    QLineEdit *urlbox;
    QPushButton *submit;

    httpManager httpClient;

    w = new QMainWindow;
    widget = new QWidget(w);
    flayout = new QFormLayout(w);
    urlbox = new QLineEdit(w);
    submit = new QPushButton("Submit", w);

    flayout->addRow("URL", urlbox);
    flayout->addRow(submit);
    widget->setLayout(flayout);
    w->setCentralWidget(widget);

    QObject::connect(submit, SIGNAL(clicked()), &httpClient, SLOT(setUrl(QUrl)))

    w->show();
    
    return a.exec();
}
