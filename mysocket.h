#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>
#include <QAbstractSocket>

class MySocket : public QTcpSocket
{
    Q_OBJECT

public:
    explicit MySocket(QObject *parent = 0);
    bool connect(QString, int);
    void desconnect();
    void doSocketWrite(QString mensagem);

    QTcpSocket *socket;

signals:


public slots:

    QString doSocketRead();

private:

};

#endif // MYSOCKET_H
