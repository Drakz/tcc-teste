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
    ui->enunciado_questao->setText(bd_question[currentRow]->enunciado);
    //ui->resposta_questao->setText(bd_question[currentRow]->gabarito);
}

void MainWindow::on_adicionar_question_clicked()//Mandando questão para a tela de criação de provas
{
    if(ui->list_questoes->currentRow() >= 0){
        ui->t_enunciado->setText(ui->enunciado_questao->toPlainText());
        ui->t_resposta_discursiva->setText(ui->resposta_questao->toPlainText());
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
    //Precisaria de uma função sem esse index maldito mas aparentemente não existe
    bd_question.clear();
    ui->list_questoes->clear();
    QString command = "SELECT questions.titulo,questions.enunciado,questions.resposta,questions.dificuldade,questions.tipo FROM questions,assunto WHERE assunto.assunto = '" + ui->assunto->currentText() + "' AND assunto.id = questions.flag_assunto ";
    QSqlQuery query(db);
    if(query.exec(command)){
        while(query.next()){
            if(query.value(4).toInt() == 1){
                //bd_question.append(new question_prog(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),"",query.value(3).toInt(),query.value(4).toInt(),5));
            }
            else {
                //bd_question.append(new question(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),"",query.value(3).toInt(),query.value(4).toInt()));
            }
        }
    }
    QStringList dificuldades = {"Fácil", "Médio", "Difícil"};
    for(int i = 0; i < bd_question.count(); i++){
        ui->list_questoes->addItem(bd_question[i]->titulo +" - "+ dificuldades[bd_question[i]->dificuldade]);
    }
}
