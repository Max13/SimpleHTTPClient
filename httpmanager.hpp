//
// main.cpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#ifndef HTTPMANAGER_HPP
#define HTTPMANAGER_HPP

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

class httpManager
{
    private:
        QNetworkAccessManager *netManager;
        QNetworkRequest *netRequest;
        QNetworkReply *netReply;

    public:
        httpManager(QObject *parent = 0);
        ~httpManager();
        QNetworkAccessManager* getNetManager() const {return (this->netManager);}
        QNetworkRequest* getNetRequest() const {return (this->netRequest);}
        QNetworkReply* getNetReply() const {return (this->netReply);}
    
    signals:
    
    public slots:
        void setUrl(QUrl const url) {this->netRequest->setUrl(url);}
};

#endif // HTTPMANAGER_HPP
