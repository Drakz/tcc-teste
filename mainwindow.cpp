#include "mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::showMaximized();
    time = new QTimer (this);
    connect (time, SIGNAL(timeout()), this, SLOT(getCurrentTime()));
    time->start(1000);

    db = QSqlDatabase::addDatabase("QMYSQL","connection1");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("qt");
    db.setUserName("tester");
    db.setPassword("123456");
    if (db.open()){
        ui->lbl_status->setText("Online!");
        ui->lbl_status->setStyleSheet("QLabel{color: #008000}");
    }
    else{
        ui->lbl_status->setText("Offline...");
        ui->lbl_status->setStyleSheet("QLabel{color: #FF0000}");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()//Login
{
    if(ui->lne_loginPassword->isEnabled()){
        QString username = ui->lne_loginUser->text();
        QString password = ui->lne_loginPassword->text();
        QString command = "SELECT nome FROM user WHERE username = '" + username + "' AND password = '" + password + "' AND status = 0";
        QSqlQuery query(db);
        if (query.exec(command)){
            if (query.size() > 0){
                query.first();
                ui->lbl_professorName->setText(query.value(0).toString());
                myProfessor = new professor();
                connect(myProfessor->professorServer.newServer, SIGNAL(newConnection()), this, SLOT(doProfessorAddNewSocket()));
                ui->stw_mainInterface->setCurrentIndex(2);
           }
            else{
                QMessageBox::information(this, "Login inválido.", "Senha ou usuário incorreto.");
            }
        }
    }
    else{
        myStudent = new student();
        myStudent->studentId = ui->lne_loginUser->text();
        connect(myStudent->studentSocket.socket, SIGNAL(readyRead()), this, SLOT(doStudentReadServer()));
        ui->stw_mainInterface->setCurrentIndex(1);
    }
    ui->lne_loginUser->clear();
    ui->lne_loginPassword->clear();
}

int MainWindow::decodeMesage(QString* message){
    qDebug() << *message;
    QStringList aux = message->split("¬:¬");
    *message = aux[1];
    qDebug() << *message;
    return aux[0].toInt();
}

QString MainWindow::encodeMessage(QString message, int messageType){
    QString encodedMessage = NULL;
    if(1 > messageType || 3 < messageType){
        return NULL;
    }
    else{
        return QString::number(messageType) + "¬:¬" + message;
    }
}

QString MainWindow::getCurrentTime(){
    QTime currentTime = QTime::currentTime();
    return currentTime.toString("hh:mm:ss");
}
