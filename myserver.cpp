#include "myserver.h"

MyServer::MyServer (QObject *parent):
    QTcpServer(parent)
{
    newSocket = new QTcpSocket(this);
    newServer = new QTcpServer(this);
    connect(this, SIGNAL(newConnection()), this, SLOT(addNewSocket()));

}

void MyServer::addNewSocket(){
    newSocket = nextPendingConnection();
    socketsList << newSocket;
}

int MyServer::startServer(MyServer *newServer, int door){
    if(!newServer->listen(QHostAddress::Any, door)){
        qDebug() << "Server falhou ao iniciar...";
        return 1;
    }
    else{
        qDebug() << "Server iniciado!";
        return 0;
    }
}

void MyServer::doServerWrite(QString message){
    if(!socketsList.isEmpty()){
        for(int i = 0; i < socketsList.size(); i++){
            socketsList[i]->write(message.toUtf8());
            socketsList[i]->waitForBytesWritten(1000);
            }
        }
}

QString MyServer::doServerRead(){
    QString readMessage = NULL;
    if(!socketsList.isEmpty()){
        for(int i = 0; i < socketsList.size(); i++){
            readMessage = socketsList[i]->readAll();
            if(readMessage != NULL){
                return readMessage;
            }
        }
     }
    return NULL;
}
