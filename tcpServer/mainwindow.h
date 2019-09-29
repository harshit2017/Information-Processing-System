#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sendData(QChar n);

private slots:

    // for sending data
    void onBtnClicked();
    void onMessageReceived(QString message,QChar n);


private:
    Ui::MainWindow *ui;
    tcpserver *server;

};

#endif // MAINWINDOW_H
