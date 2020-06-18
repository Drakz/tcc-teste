#include "mysocket.h"

MySocket::MySocket (QObject *parent):
    QTcpSocket(parent)
{
    socket = new QTcpSocket(this);
}

bool MySocket::connect(QString hostname, int door){

    socket->connectToHost(hostname, door);
    if(!socket->waitForConnected(1000)){
        qDebug() << "A conexão falhou...\nErro: " << socket-> errorString();
        return 1;
    }

    return 0;
}

void MySocket::desconnect(){
    socket->disconnectFromHost();
    socket->waitForDisconnected(1000);
    qDebug("Socket desconectado...");
}

void MySocket::doSocketWrite(QString message){
    socket->write(message.toUtf8());
    socket->waitForBytesWritten(1000);
}

QString MySocket::doSocketRead(){
    socket->waitForReadyRead(1000);
    return socket->readAll();

}
