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

httpManager::httpManager(QObject *parent)
{
    this->netManager = new QNetworkAccessManager(parent);
    this->netRequest = new QNetworkRequest;
}
