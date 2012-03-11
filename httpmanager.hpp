//
// httpmanager.hpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#ifndef HTTPMANAGER_HPP
#define HTTPMANAGER_HPP

#include <QBuffer>
#include <QDebug>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class HttpManager : public QObject
{
    Q_OBJECT

    private:
        QNetworkAccessManager *netManager;
        QNetworkRequest *netRequest;

    public:
        HttpManager(QObject *parent = 0);
        ~HttpManager();
        QNetworkAccessManager* getNetManager() const {return (this->netManager);}
        QNetworkRequest* getNetRequest() const {return (this->netRequest);}
        void proceedRequest(QString method, QUrl url, QByteArray body = QByteArray());
    
    signals:

    public slots:
};

#endif // HTTPMANAGER_HPP
