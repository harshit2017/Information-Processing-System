#include "tcpclient.h"

tcpclient::tcpclient(QObject *parent) :
QObject(parent)
{
    clientSocket=new QTcpSocket(this);
    connect(clientSocket, SIGNAL(connected()), this,SLOT(startTransfer()));
    connect(clientSocket, SIGNAL(readyRead()), this,SLOT(receive()));

}


void tcpclient::startTransfer()
{
    clientSocket->write("Client message received...");
}

tcpclient::~tcpclient()
{
   clientSocket->close();
}

void tcpclient::receive()
{

    QByteArray temp = clientSocket->read(clientSocket->bytesAvailable());
    qDebug()<<"Client : "<<temp;
    QString message;
    message=temp;
    QChar c=message.back();
    message.chop(1);

    emit messageReceived(message,c);
}

void tcpclient::connectTo(QString ip,quint16 port)
{
    clientSocket->connectToHost("192.168.0.1", port);
}
