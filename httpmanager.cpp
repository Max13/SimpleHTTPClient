//
// main.cpp for SimpleHTTPClient in /Users/Max13/Developpement
//
// Made by Adnan RIHAN
// Login   <adnan@rihan.fr>
//
// Started on  Fri Mar  9 15:53:38 2012 Adnan RIHAN
// Last update Fri Mar  9 15:53:38 2012 Adnan RIHAN
//

#include "httpmanager.hpp"

HttpManager::HttpManager(QObject *parent) : QObject(parent)
{
    this->netManager = new QNetworkAccessManager(parent);
    this->netRequest = new QNetworkRequest;

    this->netRequest->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}

HttpManager::~HttpManager()
{
}

void HttpManager::proceedRequest(QString method, QUrl url, QByteArray body)
{
    this->netRequest->setUrl(url);

    if (method == QString("HEAD"))
        this->netManager->head(*(this->netRequest));
    else if (method == QString("GET"))
        this->netManager->get(*(this->netRequest));
    else if (method == QString("PUT"))
        this->netManager->put(*(this->netRequest), body);
    else if (method == QString("POST"))
        this->netManager->post(*(this->netRequest), body);
    else if (method == QString("DELETE"))
        this->netManager->deleteResource(*(this->netRequest));
    else
        this->netManager->sendCustomRequest(*(this->netRequest), method.toAscii(), new QBuffer(&body));
}
