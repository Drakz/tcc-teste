#include "mainwindow.h"
#include "professor.h"
#include "aluno.h"
#include "bancodedados.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::showMaximized();
    db = QSqlDatabase::addDatabase("QMYSQL","connection1");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("qt");
    db.setUserName("tester");
    db.setPassword("123456");
    if (db.open()){
        ui->status->setText("Online!");
        ui->status->setStyleSheet("QLabel{color: #008000}");
    }
    else{
        ui->status->setText("Offline...");
        ui->status->setStyleSheet("QLabel{color: #FF0000}");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()//Login
{
    if(ui->passwordInput->isEnabled()){
        QString username = ui->loginInput->text();
        QString password = ui->passwordInput->text();
        QString command = "SELECT nome FROM user WHERE username = '" + username + "' AND password = '" + password + "' AND status = 0";
        QSqlQuery query(db);
        if (query.exec(command)){
            if (query.size() > 0){
                query.first();
                if(l_Questoes.size() > 0){
                    ui->lista_questoes->clear();
                    for (int i = 0; i < l_Questoes.size(); i++) {
                        ui->lista_questoes->addItem("Questão " + QString::number(i + 1));
                    }
                }
                ui->p_nome->setText(query.value(0).toString());
                ui->s_principal->setCurrentIndex(2);
            }
            else{
                QMessageBox::information(this, "Login inválido.", "Senha ou usuário incorreto.");
            }
        }
    }
    else{
        ui->s_principal->setCurrentIndex(1);
    }
    ui->loginInput->clear();
    ui->passwordInput->clear();
}
