#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class tcpserver:public QObject
{
    Q_OBJECT
public:
    tcpserver(QObject *parent = nullptr);
    ~tcpserver();

    void send(QByteArray data,QChar n);
    void startListening(const quint16 &port);

signals:
    void messageReceived(QString message,QChar c);

    public slots:
        void acceptConnection();
        void receive();



private:
    QTcpServer *server = nullptr;
    QTcpSocket *serverSocket;
};

#endif // TCPSERVER_H
