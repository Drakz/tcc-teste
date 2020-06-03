#include "mainwindow.h"

void MainWindow::on_voltar_clicked()//Sair da busca do banco de dados
{
    ui->s_principal->setCurrentIndex(2);
}

void MainWindow::on_materia_currentIndexChanged(int index)//Busca assuntos em uma determinada matéria
{
    ui->assunto->clear();
    QString command;
    QSqlQuery query(db);
    command = "SELECT assunto, materia, id FROM assunto WHERE materia = '" + QString::number(index+1) + "'";
    if(query.exec(command)){
        while(query.next()){
            ui->assunto->addItem(query.value(0).toString());
        }
    }
}

void MainWindow::on_list_questoes_currentRowChanged(int currentRow)//Mostrando cada questão após a busca no banco dados
{
    bd_question[currentRow]->setBanco(ui);
}

void MainWindow::on_adicionar_question_clicked()//Mandando questão para a tela de criação de provas
{
    if(ui->list_questoes->currentRow() >= 0){
        l_Questoes[ui->lista_questoes->currentRow()] = bd_question[ui->list_questoes->currentRow()];
        ctrl_remover = true;
        atualizarquestao();
        ui->s_principal->setCurrentIndex(2);
        ctrl_remover = false;
    }
    else{
        QMessageBox::information(this, "Alerta", "Nenhuma questão selecionada.");
    }
}

void MainWindow::on_assunto_currentIndexChanged(int index)//Fazendo a busca no banco de dados para questoes de determinado assunto
{
    //Precisaria de uma função sem esse index maldito mas aparentemente não existe
    bd_question.clear();
    ui->list_questoes->clear();
    QString command = "SELECT questions.titulo,questions.enunciado,questions.resposta,questions.dificuldade,questions.tipo FROM questions,assunto WHERE assunto.assunto = '" + ui->assunto->currentText() + "' AND assunto.id = questions.flag_assunto ";
    QSqlQuery query(db);
    if(query.exec(command)){
        while(query.next()){
            if(query.value(4).toInt() == 1){
                QStringList lista = query.value(2).toString().split("¬:¬");
                int tam = lista.size();
                QStringList input;
                QStringList output;
                for (int i = 0; i < (tam-1); i = i + 2) {
                    input.append(lista[i]);
                    output.append(lista[i+1]);
                }
                bd_question.append(new question_prog(query.value(0).toString(),query.value(1).toString(),query.value(3).toInt(),query.value(4).toInt() - 1,lista[tam-1].toInt(),input,output));
            }
            else if(query.value(4).toInt() == 2){
                QStringList lista = query.value(2).toString().split("¬:¬");
                int tam = lista.size();
                QStringList alternativas;
                for (int i = 0; i < (tam-1); i++) {
                    alternativas.append(lista[i]);
                }
                bd_question.append(new question_mult(query.value(0).toString(),query.value(1).toString(),query.value(3).toInt(),query.value(4).toInt() - 1,alternativas,lista[tam-1].toInt()));
            }
            else {
                bd_question.append(new question_disc(query.value(0).toString(),query.value(1).toString(),query.value(3).toInt(),query.value(4).toInt() - 1,query.value(2).toString()));
            }
        }
    }
    QStringList dificuldades = {"Fácil", "Médio", "Difícil"};
    for(int i = 0; i < bd_question.count(); i++){
        ui->list_questoes->addItem(bd_question[i]->titulo +" - "+ dificuldades[bd_question[i]->dificuldade]);
    }
}
