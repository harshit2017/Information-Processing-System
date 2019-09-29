#include "tcpserver.h"

tcpserver::tcpserver(QObject *parent):
    QObject(parent)
{

}

tcpserver::~tcpserver()
{
    server->close();
}


void tcpserver::startListening(const quint16 &port)
{

    if (!server)
    {
        server = new QTcpServer(this);

        if (server->listen(QHostAddress::Any, port))
        {
           connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

        }
    }


}

void tcpserver::acceptConnection()
{
    serverSocket = server->nextPendingConnection();
    qDebug()<<"Connection established";
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(receive()));

}


void tcpserver::receive()
{
    QByteArray temp = serverSocket->read(serverSocket->bytesAvailable());
    qDebug()<<"Server : "<<temp;
    QString message;
    message=temp;
    QChar c=message.back();
    message.chop(1);

    emit messageReceived(message,c);
}

void tcpserver::send(QByteArray data,QChar n){
    data.append(n);
    serverSocket->write(data);
    serverSocket->flush();
}
