#include "mainwindow.h"



void MainWindow::on_lista_questoes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)//Alternar entre questões da prova e guardar suas propriedades
{
    if(!ctrl_remover){
        if(previous){
            //delete(l_Questoes[ui->lista_questoes->row(previous)]);
            if(ui->c_tipo->currentIndex() == 0){//Programação
                QList<QString> in;
                QList<QString> out;
                in.clear();
                out.clear();
                for (int j = 0; j < ui->l_input->count(); j++){
                    in.append(ui->l_input->item(j)->text());
                    out.append(ui->l_output->item(j)->text());
                }
                l_Questoes[ui->lista_questoes->row(previous)] = new question_prog(ui->t_titulo->toPlainText(),ui->t_enunciado->toPlainText(),ui->q_dificuldade->currentIndex(),ui->c_tipo->currentIndex() + 1,ui->s_numcomp->value(),in,out);
                ui->l_input->clear();
                ui->l_output->clear();
                ui->s_numcomp->clear();
            }
            else if(ui->c_tipo->currentIndex() == 1){//Múltipla Escolha
                QList<QString> alt;
                int alternativa = -1;
                for (int j = 0; j < ui->t_resposta_mult->count(); j++) {
                    if(ui->t_resposta_mult->item(j)->checkState() == 2)
                        alternativa = j;
                    alt.append(ui->t_resposta_mult->item(j)->text());
                }
                l_Questoes[ui->lista_questoes->row(previous)] = new question_mult(ui->t_titulo->toPlainText(),ui->t_enunciado->toPlainText(),ui->q_dificuldade->currentIndex(),ui->c_tipo->currentIndex() + 1,alt, alternativa);
                ui->t_resposta_mult->clear();
            }
            else if(ui->c_tipo->currentIndex() == 2){//Discursiva
                l_Questoes[ui->lista_questoes->row(previous)] = new question_disc(ui->t_titulo->toPlainText(),ui->t_enunciado->toPlainText(),ui->q_dificuldade->currentIndex(),ui->c_tipo->currentIndex() + 1,ui->t_resposta_discursiva->toHtml());
                ui->t_resposta_discursiva->clear();
            }
            ui->t_enunciado->clear();
            ui->t_titulo->clear();
        }
        if(current && previous){
            l_Questoes[ui->lista_questoes->row(current)]->getGabarito(ui);//POLIMORFISMO!!!
            ui->t_enunciado->setText(l_Questoes[ui->lista_questoes->row(current)]->enunciado);
            ui->t_titulo->setText(l_Questoes[ui->lista_questoes->row(current)]->titulo);
            ui->q_dificuldade->setCurrentIndex(l_Questoes[ui->lista_questoes->row(current)]->dificuldade);
        }
    }
}

void MainWindow::atualizarquestao(){
    l_Questoes[ui->lista_questoes->currentRow()]->getGabarito(ui);//POLIMORFISMO!!!
    ui->t_enunciado->setText(l_Questoes[ui->lista_questoes->currentRow()]->enunciado);
    ui->t_titulo->setText(l_Questoes[ui->lista_questoes->currentRow()]->titulo);
    ui->q_dificuldade->setCurrentIndex(l_Questoes[ui->lista_questoes->currentRow()]->dificuldade);
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
            ui->t_resposta_discursiva->clear();
            ui->t_titulo->clear();
            ui->t_enunciado->setReadOnly(true);
            ui->t_resposta_discursiva->setReadOnly(true);
            ui->t_titulo->setReadOnly(true);
            ui->g_resposta->setEnabled(false);
            //ui->t_resposta_prog->setEnabled(false);
            ui->c_tipo->setEnabled(false);
            ui->q_dificuldade->setEnabled(false);
        }
        else{
            ui->lista_questoes->setCurrentRow(0);
        }
    }
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
    }
    else{
        QMessageBox::information(this, "Alerta", "Para adicionar uma questão do banco de dados primeiro você precisa de uma questão, seu bundão.");
    }
}

void MainWindow::on_logout_professor_clicked()//Logout professor
{
    ui->s_principal->setCurrentIndex(0);
}

void MainWindow::on_adicionar_questao_clicked()//Criando uma questão para a prova
{
    ui->lista_questoes->addItem("Questão " + QString::number(ui->lista_questoes->count() + 1));
    l_Questoes.append(new question_prog{"","",0,0,0,{},{}});
    if(ui->t_enunciado->isReadOnly()){
        ui->t_enunciado->setReadOnly(false);
        ui->t_titulo->setReadOnly(false);
        ui->g_resposta->setEnabled(true);
        ui->p_respostas->setEnabled(true);
        ui->c_tipo->setEnabled(true);
        ui->q_dificuldade->setEnabled(true);
        ui->lista_questoes->setCurrentRow(0);
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

void MainWindow::on_gerar_prova_clicked()//Gerar XML prova
{
    QDomDocument prova;
    QDomElement raiz = prova.createElement("Prova");
    prova.appendChild(raiz);
    QDomElement questoes = prova.createElement("Questoes");
    raiz.appendChild(questoes);
    for(int i = 0; i < l_Questoes.size(); i++){
        QDomElement questao = prova.createElement("Questao");
        questao.setAttribute("ID", QString::number(i + 1));
        questao.setAttribute("Enunciado ",  l_Questoes[i]->enunciado);
        questao.setAttribute("Dificuldade ",  l_Questoes[i]->dificuldade);
        questao.setAttribute("Tipo ",  l_Questoes[i]->tipo);
        if(l_Questoes[i]->tipo == 1){
            QStringList aux = l_Questoes[i]->imprimir().split("¬:¬");
            int tam = aux.size();
            QString input;
            QString output;
            for (int i = 0; i < (tam-1); i = i + 2) {
                input = input + aux[i];
                output = output + aux[i+1];
            }
            questao.setAttribute("Input ",  input);
            questao.setAttribute("Output ",  output);
            questao.setAttribute("NumeroCompilacao ",  aux[tam-1]);
        }
        else{
            questao.setAttribute("Gabarito ", l_Questoes[i]->imprimir());
        }
        questoes.appendChild(questao);
    }
    QFile arquivo("C://Users/eduar/Desktop/Nova pasta/prova.xml");
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    else{
        QTextStream stream (&arquivo);
        stream << prova;
        arquivo.close();
        qDebug() << "Prova criada com sucesso!";
    }
}

void MainWindow::on_c_tipo_currentIndexChanged(int index)//Resposta responsiva ao tipo de questão na criação de provas
{
    ui->p_respostas->setCurrentIndex(index);
}

void MainWindow::on_t_adc_questao_clicked()//Adicionar alternativa de múltipla escolha na criação de provas
{
    QListWidgetItem* item = new QListWidgetItem("Nova alternativa");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setCheckState(Qt::Unchecked);
    ui->t_resposta_mult->addItem(item);
}

void MainWindow::on_t_rmv_questao_clicked()//Remover alternativa de múltipla escolha na criação de provas
{
    QListWidgetItem* item = ui->t_resposta_mult->currentItem();
    ui->t_resposta_mult->removeItemWidget(item);
    delete item;
}

void MainWindow::on_t_adc_teste_clicked()//Adicionar par input output na criação de provas
{
    QListWidgetItem* input = new QListWidgetItem("Input");
    QListWidgetItem* output = new QListWidgetItem("Output");
    input->setFlags(input->flags() | Qt::ItemIsEditable);
    output->setFlags(output->flags() | Qt::ItemIsEditable);
    ui->l_input->addItem(input);
    ui->l_output->addItem(output);
}

void MainWindow::on_t_rmv_teste_clicked()//Remover par input output na criação de provas
{
    qDebug() << ui->l_input->count();
    QListWidgetItem* input = ui->l_input->takeItem(ui->l_input->count() - 1);
    QListWidgetItem* output = ui->l_output->takeItem(ui->l_output->count() - 1);
    ui->l_input->removeItemWidget(input);
    ui->l_output->removeItemWidget(output);
    delete input;
    delete output;
}
