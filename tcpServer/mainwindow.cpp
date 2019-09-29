#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new tcpserver(this);
    server->startListening(23);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(server, &tcpserver::messageReceived, this, &MainWindow::onMessageReceived);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnClicked()
{

    QObject* button = QObject::sender();
        if (button == ui->pushButton)
        {
           sendData('1');
        }
        else if (button == ui->pushButton_2)
        {
            sendData('2');
        }
        else if(button == ui->pushButton_3)
        {
          sendData('3');
        }

        else {
            sendData('4');
        }
}

void MainWindow::onMessageReceived(QString message,QChar c)
{
    message.append('\n');
    if(c=='1'){
        ui->textEdit_2->setText(message);
    }

   else if(c=='2'){
        ui->textEdit_3->setText(message);
    }

   else if(c=='3'){
        ui->textEdit_4->setText(message);
    }

   else{
        ui->textEdit_5->setText(message);
    }

    ui->textEdit->insertPlainText(message);
}


void MainWindow::sendData(QChar c){
    QByteArray data1="10,1a,16,13,1d,23,6,7,6,7,5,5,1d,52,7d,40,10,13,1a,1f,4,4,6,27,e,10,17,1a,12,15,11,e";
    QByteArray data2="13,1b,17,14,1b,21,4,6,6,6,5,5,17,2e,7e,55,13,19,1d,26,4,4,7,41,e,11,16,1d,11,1b,19,10";
    QByteArray data3="10,19,15,13,1a,20,7,6,6,5,5,4,17,2c,7d,54,10,17,1b,24,3,3,7,40,e,10,15,1c,f,19,17,f";
    QByteArray data4="42,15,15,17,16,1a,1d,23,3b,f,13,15,16,14,18,1b,71,19,15,15,13,16,19,19,1c,14,13,13,13,14,14,14,12";

    if(c=='1')
    server->send(data1,c);

    else if(c=='2')
    server->send(data2,c);

    else if(c=='3')
    server->send(data3,c);

    else
    server->send(data4,c);
}

