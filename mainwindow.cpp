#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "busca.h"

bool static ctrl_remover = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow::showMaximized();
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
        ui->status->setText("Offline");
        ui->status->setStyleSheet("QLabel{color: #FF0000}");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->loginInput->text();
    QString password = ui->passwordInput->text();
    QString command = "SELECT deptID,nome FROM user WHERE username = '" + username + "' AND password = '" + password + "' AND status = 0";
    QSqlQuery query(db);
    if (query.exec(command)){
        if (query.size() > 0){
            query.first();
            if(query.value(0).toInt() == 1){
                ui->s_principal->setCurrentIndex(1);
            }
            else if(query.value(0).toInt() == 2){
                ui->p_nome->setText(query.value(1).toString());
                ui->s_principal->setCurrentIndex(2);
            }
            else{
                QMessageBox::information(this, "Login success.", "Favor entrar em contato com um administrador.");
            }
        }
        else {
            QMessageBox::information(this, "Login failed.", "Login failed. Please try again...");
        }
    }
    ui->loginInput->clear();
    ui->passwordInput->clear();
    //QSqlDatabase::removeDatabase("connection1");
}

void MainWindow::on_busca_bd_clicked()
{
    busca *b = new busca(this,&tmp_questao);
    b->setModal(true);
    b->exec();
    if(ui->lista_questoes->count() > 0){
        ui->t_enunciado->setText(tmp_questao.enunciado);
        ui->t_resposta->setText(tmp_questao.resposta);
        ui->t_titulo->setText(tmp_questao.titulo);
    }
    else{
        QMessageBox::information(this, "Alerta", "Para adicionar uma questão do banco de dados primeiro você precisa de uma questão, seu bundão.");
    }
}

void MainWindow::on_logout_professor_clicked()
{
    ui->s_principal->setCurrentIndex(0);
}

void MainWindow::on_logout_aluno_clicked()
{
    ui->s_principal->setCurrentIndex(0);
}

void MainWindow::on_adicionar_questao_clicked()
{
    ui->lista_questoes->addItem("Questão " + QString::number(ui->lista_questoes->count() + 1));
    l_Questoes.append({"","","",1});
    if(ui->t_enunciado->isReadOnly()){
        ui->t_enunciado->setReadOnly(false);
        ui->t_resposta->setReadOnly(false);
        ui->t_titulo->setReadOnly(false);
        ui->lista_questoes->setCurrentRow(0);
    }
}

void MainWindow::on_lista_questoes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(!ctrl_remover){
        if(previous){
            l_Questoes[ui->lista_questoes->row(previous)].enunciado = ui->t_enunciado->toHtml();
            l_Questoes[ui->lista_questoes->row(previous)].resposta = ui->t_resposta->toHtml();
            l_Questoes[ui->lista_questoes->row(previous)].titulo = ui->t_titulo->toHtml();
            ui->t_enunciado->clear();
            ui->t_resposta->clear();
            ui->t_titulo->clear();
        }
        if(current){
            ui->t_enunciado->setText(l_Questoes[ui->lista_questoes->row(current)].enunciado);
            ui->t_resposta->setText(l_Questoes[ui->lista_questoes->row(current)].resposta);
            ui->t_titulo->setText(l_Questoes[ui->lista_questoes->row(current)].titulo);
        }
    }
}

void MainWindow::on_remover_questao_clicked()
{
    if(ui->lista_questoes->count() > 0){
        l_Questoes.removeAt(ui->lista_questoes->currentRow());
        int c = l_Questoes.size();
        ctrl_remover = true;
        ui->lista_questoes->clear();
        for(int i = 0; i < c; i++){
            ui->lista_questoes->addItem("Questão " + QString::number(ui->lista_questoes->count() + 1));
        }
        ctrl_remover = false;
        if(c == 0){
            ui->t_enunciado->clear();
            ui->t_resposta->clear();
            ui->t_titulo->clear();
            ui->t_enunciado->setReadOnly(true);
            ui->t_resposta->setReadOnly(true);
            ui->t_titulo->setReadOnly(true);
        }
        else{
            ui->lista_questoes->setCurrentRow(0);
        }
    }
}
