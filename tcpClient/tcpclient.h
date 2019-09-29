#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>

class tcpclient :public QObject
{
    Q_OBJECT
private:
    QTcpSocket *clientSocket;
signals:
    void messageReceived(QString message,QChar c);
public:
    tcpclient(QObject *parent=nullptr);
    ~tcpclient();
    void connectTo(QString ip,quint16 port);
    void sendData(QByteArray,QChar);


public slots:
    void receive();
    void startTransfer();

};

#endif // TCPCLIENT_H
