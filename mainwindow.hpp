//
// mainwindow.hpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

#include "httpmanager.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        QWidget *cWidget;
        QVBoxLayout *verticalLayout;
        QFormLayout *formLayout;
        QHBoxLayout *horizontalLayout;
        QLineEdit *urlBox;
        QLineEdit *bodyBox;
        QComboBox *methodBox;
        QPushButton *resetButton;
        QPushButton *submitButton;
        QTextEdit *bodyField;
        QTextEdit *respField;
        HttpManager *httpClient;

    public:
        MainWindow(QWidget *parent = 0);

    signals:
    
    public slots:
        void proceedRequest();
        void showReceivedData(QNetworkReply *);
        void methodChanged(QString newMethodName);
};

#endif // MAINWINDOW_HPP
