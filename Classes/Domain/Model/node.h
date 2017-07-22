#ifndef NODE_H
#define NODE_H

#include <QtCore/qglobal.h>


class Node
{
public:
    explicit Node();

//Getters

// Setters
    void setBlockchain(QString blockchain);
    void setServer(QString server);
    void setPort(QString port);
    void setRpcUser(QString user);
    void setRpcPassword(QString password);

private:

    QString blockchain, server, port;

};

#endif // NODE_H
