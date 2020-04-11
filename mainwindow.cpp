#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::on_busca_bd_clicked()//Entrada na janela de busca do banco de dados
{
    if(ui->lista_questoes->count() > 0){
        ui->s_principal->setCurrentIndex(4);
        QString command = "SELECT materia FROM materia";
        QSqlQuery query(db);
        if(query.exec(command)){
            while(query.next()){
                ui->materia->addItem({query.value(0).toString()});
            }
        }
        command = "SELECT assunto, materia, id FROM assunto";
        if(query.exec(command)){
            while(query.next()){
                ui->assunto->addItem(query.value(0).toString());
            }
        }
    }
    else{
        QMessageBox::information(this, "Alerta", "Para adicionar uma questão do banco de dados primeiro você precisa de uma questão, seu bundão.");
    }
}

void MainWindow::on_logout_professor_clicked()//Logout professor
{
    ui->s_principal->setCurrentIndex(0);
}

void MainWindow::on_logout_aluno_clicked()//Logout aluno
{
    ui->s_principal->setCurrentIndex(0);
}

void MainWindow::on_adicionar_questao_clicked()//Criando uma questão para a prova
{
    ui->lista_questoes->addItem("Questão " + QString::number(ui->lista_questoes->count() + 1));
    l_Questoes.append(new question{"","","","",0,0});
    if(ui->t_enunciado->isReadOnly()){
        ui->t_enunciado->setReadOnly(false);
        ui->t_resposta->setReadOnly(false);
        ui->t_titulo->setReadOnly(false);
        ui->lista_questoes->setCurrentRow(0);
    }
}

void MainWindow::on_lista_questoes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)//Alternar entre questões da prova e guardar suas propriedades
{
    if(!ctrl_remover){
        if(previous){
            l_Questoes[ui->lista_questoes->row(previous)]->enunciado = ui->t_enunciado->toPlainText();
            l_Questoes[ui->lista_questoes->row(previous)]->gabarito = ui->t_resposta->toPlainText();
            l_Questoes[ui->lista_questoes->row(previous)]->titulo = ui->t_titulo->toPlainText();
            l_Questoes[ui->lista_questoes->row(previous)]->tipo = ui->c_tipo->currentIndex() + 1;
            l_Questoes[ui->lista_questoes->row(previous)]->dificuldade = ui->q_dificuldade->currentIndex();
            ui->t_enunciado->clear();
            ui->t_resposta->clear();
            ui->t_titulo->clear();
        }
        if(current){
            ui->t_enunciado->setText(l_Questoes[ui->lista_questoes->row(current)]->enunciado);
            ui->t_resposta->setText(l_Questoes[ui->lista_questoes->row(current)]->gabarito);
            ui->t_titulo->setText(l_Questoes[ui->lista_questoes->row(current)]->titulo);
            ui->c_tipo->setCurrentIndex(l_Questoes[ui->lista_questoes->row(current)]->tipo - 1);
            ui->q_dificuldade->setCurrentIndex(l_Questoes[ui->lista_questoes->row(current)]->dificuldade);
        }
    }
}

void MainWindow::on_remover_questao_clicked()//Remover uma questão da prova
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

void MainWindow::on_insere_bd_clicked()//Inserir questão no banco de dados
{
    QString command = "SELECT titulo,enunciado FROM questions WHERE titulo = '" + ui->t_titulo->toPlainText() + "' OR enunciado = '" + ui->t_enunciado->toPlainText() + "'";
    QSqlQuery query(db);
    if(query.exec(command)){
        if(query.size() > 0){
            QMessageBox::information(this, "Alerta", "Já existe essa questão no banco de dados, cabeção!");
        }
        else{
            QMessageBox::information(this, "Alerta", "Questão adicionada no banco de dados!");
        }
    }
}

void MainWindow::on_b_entraprova_clicked()//teste
{
    int c = l_Questoes.size();
    ui->lista_questoes->clear();
    for(int i = 0; i < c; i++){
        ui->l_prova->addItem("Questão " + QString::number(ui->l_prova->count() + 1));
    }
    ui->l_prova->setCurrentRow(0);
    ui->s_principal->setCurrentIndex(3);
}

void MainWindow::on_b_entregaprova_clicked()//teste
{
    ui->s_principal->setCurrentIndex(1);
}

void MainWindow::on_l_prova_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){//Mudança e armazenamento das questões da prova pelo aluno
    if(previous){
        l_Questoes[ui->l_prova->row(previous)]->resposta = ui->p_resposta->toPlainText();
        ui->p_enunciado->clear();
        ui->p_resposta->clear();
    }
    if(current){
        ui->p_enunciado->setText(l_Questoes[ui->l_prova->row(current)]->enunciado);
        ui->p_resposta->setText(l_Questoes[ui->l_prova->row(current)]->resposta);
    }
}

void MainWindow::on_l_prova_currentRowChanged(int currentRow)//Habilitar ou não botões de compilação e execução
{
    if(l_Questoes[currentRow]->tipo == 1){
        ui->b_compilar->setText("Compilar - [" + QString::number(static_cast<question_prog*>(l_Questoes[currentRow])->qtd_comp) + "]");
        ui->b_compilar->setEnabled(true);
        ui->b_executar->setEnabled(true);
    }
    else{
        ui->b_compilar->setText("Compilar");
        ui->b_compilar->setEnabled(false);
        ui->b_executar->setEnabled(false);
    }
}

void MainWindow::on_voltar_clicked()//Sair da busca do banco de dados
{
    ui->s_principal->setCurrentIndex(2);
}

void MainWindow::on_materia_currentIndexChanged(int index)
{
    ui->assunto->clear();
    //ui->list_questoes->clear();
    for(int i = 0; i < l_Assunto.count(); i++){
        //if(l_Assunto[i].materia == index + 1){
            //ui->assunto->addItem(l_Assunto[i].assunto);
        //}
    }
}

void MainWindow::on_list_questoes_currentRowChanged(int currentRow)//Mostrando cada questão após a busca no banco dados
{
    ui->enunciado_questao->setText(bd_question[currentRow]->enunciado);
    ui->resposta_questao->setText(bd_question[currentRow]->gabarito);
}

void MainWindow::on_adicionar_question_clicked()//Mandando questão para a tela de criação de provas
{
    if(ui->list_questoes->currentRow() >= 0){
        ui->t_enunciado->setText(ui->enunciado_questao->toPlainText());
        ui->t_resposta->setText(ui->resposta_questao->toPlainText());
        QStringList temp = ui->list_questoes->currentItem()->text().split(" - ");
        ui->t_titulo->setText(temp[0]);
        if(temp[1] == "Fácil"){
            ui->q_dificuldade->setCurrentIndex(0);
        }
        else if (temp[1] == "Médio") {
            ui->q_dificuldade->setCurrentIndex(1);
        }
        else {
            ui->q_dificuldade->setCurrentIndex(2);
        }
        ui->s_principal->setCurrentIndex(2);
    }
    else{
        QMessageBox::information(this, "Alerta", "Nenhuma questão selecionada.");
    }
}

void MainWindow::on_assunto_currentIndexChanged(int index)//Fazendo a busca no banco de dados para questoes de determinado assunto
{
    bd_question.clear();
    ui->list_questoes->clear();
    QString command = "SELECT questions.titulo,questions.enunciado,questions.resposta,questions.dificuldade,questions.tipo FROM questions,assunto WHERE assunto.assunto = '" + ui->assunto->currentText() + "' AND assunto.id = questions.flag_assunto ";
    QSqlQuery query(db);
    if(query.exec(command)){
        while(query.next()){
            if(query.value(4).toInt() == 1){
                bd_question.append(new question_prog(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),"",query.value(3).toInt(),query.value(4).toInt(),5));
            }
            else {
                bd_question.append(new question(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),"",query.value(3).toInt(),query.value(4).toInt()));
            }
        }
    }
    QStringList dificuldades = {"Fácil", "Médio", "Difícil"};
    for(int i = 0; i < bd_question.count(); i++){
        ui->list_questoes->addItem(bd_question[i]->titulo +" - "+ dificuldades[bd_question[i]->dificuldade]);
    }
}

void MainWindow::on_gerar_prova_clicked()
{
    QString path = "prova.txt";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    QTextStream out(&file);
    QString questao = "";
    for(int i = 0; i < l_Questoes.size(); i++){
        questao = l_Questoes[i]->imprimir();
        out << questao << endl;
    }

}
