#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit MyServer(QObject *parent = 0);
    int startServer(MyServer* newServer, int door);
    void doServerWrite(QString message);
    QList < QTcpSocket *> socketsList;
    QTcpSocket *newSocket;
    QTcpServer *newServer;

signals:

public slots:
    void addNewSocket();
    QString doServerRead();
};
#endif // MYSERVER_H
