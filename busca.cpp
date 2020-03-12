#include "busca.h"
#include "ui_busca.h"
#include "mainwindow.h"


busca::busca(QWidget *parent, Questao *q) :
    QDialog(parent),
    ui(new Ui::busca)
{
    this->questao = q;
    ui->setupUi(this);
    QString command = "SELECT materia FROM materia";
    QSqlQuery query(MainWindow().db);
    if(query.exec(command)){
        while(query.next()){
            l_Materia.append({query.value(0).toString()});
        }
    }
    for(int i=0; i < l_Materia.count(); i++){
        ui->materia->addItem(l_Materia[i].materia);
    }
    command = "SELECT assunto, materia, id FROM assunto";
    if(query.exec(command)){
        while(query.next()){
            l_Assunto.append({query.value(0).toString(),query.value(1).toInt(),query.value(2).toInt()});
        }
    }
    for(int i = 0; i < l_Assunto.count(); i++){
        if(l_Assunto[i].materia == 1){
            ui->assunto->addItem(l_Assunto[i].assunto);
        }
    }
    QSqlDatabase::removeDatabase("connection1");
}

busca::~busca()
{
    delete ui;
}

void busca::on_voltar_clicked()
{
    this->close();
}

void busca::on_buscar_bd_clicked()
{
    l_Questao.clear();
    ui->list_questoes->clear();
    QString command = "SELECT questions.enunciado,questions.resposta,questions.titulo,questions.tipo FROM questions,assunto WHERE assunto.assunto = '" + ui->assunto->currentText() + "' AND assunto.id = questions.flag_assunto ";
    QSqlQuery query(MainWindow().db);
    if(query.exec(command)){
        while(query.next()){
            l_Questao.append({query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toInt()});
        }
    }
    for(int i = 0; i < l_Questao.count(); i++){
        ui->list_questoes->addItem(l_Questao[i].titulo);
    }
    QSqlDatabase::removeDatabase("connection1");
}

void busca::on_materia_currentIndexChanged(int index)
{
    ui->assunto->clear();
    //ui->list_questoes->clear();
    for(int i = 0; i < l_Assunto.count(); i++){
        if(l_Assunto[i].materia == index + 1){
            ui->assunto->addItem(l_Assunto[i].assunto);
        }
    }
}

void busca::on_list_questoes_currentRowChanged(int currentRow)
{
    ui->enunciado_questao->setText(l_Questao[currentRow].enunciado);
    ui->resposta_questao->setText(l_Questao[currentRow].resposta);
}

void busca::on_adicionar_question_clicked()
{
    if(ui->list_questoes->currentRow() >= 0){
        this->questao->tipo = 1;
        this->questao->titulo = l_Assunto[ui->list_questoes->currentRow() + 1].assunto;
        this->questao->resposta = ui->resposta_questao->toHtml();
        this->questao->enunciado = ui->enunciado_questao->toHtml();
        this->close();
    }
    else{
        QMessageBox::information(this, "Alerta", "Nenhuma questão selecionada.");
    }
}
