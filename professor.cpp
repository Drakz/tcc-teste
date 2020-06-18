#include "mainwindow.h"
#include "professor.h"
#include <QMessageBox>

professor::professor(){
    this->exam = "";
    professorServer.newServer = &professorServer;
}

void MainWindow::doProfessorAddNewSocket(){
    connect(myProfessor->professorServer.newSocket, SIGNAL(readyRead()), this, SLOT(doProfessorReadServer()));
}

void MainWindow::doProfessorReadServer(){
    QString readFromServer = myProfessor->professorServer.doServerRead();
    switch(decodeMesage(&readFromServer)){
        case 0:
            QMessageBox::critical(this,"Tipo de dado desconhecido","Houve um erro na leitura do dado pelo servidor...");
        break;

        case MESSAGE:
            ui->ltw_rooomLobby->addItem(readFromServer); //escrever comunicado no lobby da sala
        break;

        case ALERT:
            ui->ltw_rooomLobby->addItem("alertMessage! " + readFromServer); //escrever mensagem de alertMessage no log da sala
        break;

        case EXAM:
            if(doCreateXmlStudentAnswer(readFromServer)){
                QMessageBox::information(this,"Arquivo de prova","Arquivo de prova do student criado com sucesso!");
            }
            else{
                QMessageBox::critical(this,"Arquivo de prova","Houve um erro na criação do arquivo de prova do student...");
            }
        break;
    }
}

void MainWindow::on_btn_createRoom_clicked(){
    if(!myProfessor->professorServer.startServer(&myProfessor->professorServer, ui->spb_setRoomDoor->value())){
          QMessageBox::information(this,"Status da Conexão","Servidor Criado!");
          //ui->spb_setRoomDoor->setEnabled(false);
          ui->stw_applyExam->setCurrentIndex(1);
       }
       else{
          QMessageBox::critical(this,"Status da Conexão","A criação do Servidor falhou...");
       }

}

void MainWindow::on_btn_loadExamFile_clicked(){
    myProfessor->exam = getXmlExam(ui->lne_examFileDirectory->text());
    if(myProfessor->exam == ""){
        QMessageBox::critical(this,"Arquivo de Prova","O carregamento do arquivo da prova falhou...");
    }
    else{
        QMessageBox::information(this,"Arquivo de Prova","Prova carregada com sucesso!");
        ui->btn_setExamStarted->setEnabled(true);
    }
}

void MainWindow::on_btn_fechar_sala_clicked(){
    myProfessor->professorServer.doServerWrite(encodeMessage("O professor encerrou esta sala...", MESSAGE));
    myProfessor->professorServer.close();
    ui->stw_applyExam->setCurrentIndex(0);

}

void MainWindow::on_btn_setExamStarted_clicked(){
    myProfessor->professorServer.doServerWrite(encodeMessage(myProfessor->exam, EXAM)); //enviar aquivo xml para os sockets
    ui->btn_setExamFinished->setEnabled(true);
    ui->btn_setExamStarted->setEnabled(false);
}

void MainWindow::on_btn_setExamFinished_clicked(){
    myProfessor->professorServer.doServerWrite(encodeMessage("A prova terminou!", MESSAGE));//enviar mensagem do tipo comunicado para os sockets
    ui->btn_setExamFinished->setEnabled(false);
    ui->btn_setExamStarted->setEnabled(true);
}

void MainWindow::on_ltw_setExamQuestionsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)//Alternar entre questões da prova e guardar suas propriedades
{
    if(!ctrl_remover){
        if(previous){
            //delete(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(previous)]);
            if(ui->cbb_type->currentIndex() == 0){//Programação
                QList<QString> in;
                QList<QString> out;
                in.clear();
                out.clear();
                for (int j = 0; j < ui->ltw_compilationInput->count(); j++){
                    in.append(ui->ltw_compilationInput->item(j)->text());
                    out.append(ui->ltw_compilationOutput->item(j)->text());
                }
                myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(previous)] = new professorProgrammingQuestion(ui->txe_setTitle->toPlainText(),ui->txe_setQuestionDescription->toPlainText(),ui->cbb_difficulty->currentIndex(),ui->cbb_type->currentIndex() + 1,ui->spb_compilationAmount->value(),in,out);
                ui->ltw_compilationInput->clear();
                ui->ltw_compilationOutput->clear();
                ui->spb_compilationAmount->clear();
            }
            else if(ui->cbb_type->currentIndex() == 1){//Múltipla Escolha
                QList<QString> alt;
                int alternativa = -1;
                for (int j = 0; j < ui->ltw_multipleChoiceAlternatives->count(); j++) {
                    if(ui->ltw_multipleChoiceAlternatives->item(j)->checkState() == 2)
                        alternativa = j;
                    alt.append(ui->ltw_multipleChoiceAlternatives->item(j)->text());
                }
                myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(previous)] = new professorMultipleChoiceQuestion(ui->txe_setTitle->toPlainText(),ui->txe_setQuestionDescription->toPlainText(),ui->cbb_difficulty->currentIndex(),ui->cbb_type->currentIndex() + 1,alt, alternativa);
                ui->ltw_multipleChoiceAlternatives->clear();
            }
            else if(ui->cbb_type->currentIndex() == 2){//Discursiva
                myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(previous)] = new professorDiscursiveQuestion(ui->txe_setTitle->toPlainText(),ui->txe_setQuestionDescription->toPlainText(),ui->cbb_difficulty->currentIndex(),ui->cbb_type->currentIndex() + 1,ui->txe_discursiveAnswer->toHtml());
                ui->txe_discursiveAnswer->clear();
            }
            ui->txe_setQuestionDescription->clear();
            ui->txe_setTitle->clear();
        }
        if(current && previous){
            myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(current)]->getGabarito(ui);//POLIMORFISMO!!!
            ui->txe_setQuestionDescription->setText(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(current)]->enunciado);
            ui->txe_setTitle->setText(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(current)]->titulo);
            ui->cbb_difficulty->setCurrentIndex(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->row(current)]->dificuldade);
        }
    }
}

void MainWindow::doUpdateQuestion(){
    myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->currentRow()]->getGabarito(ui);//POLIMORFISMO!!!
    ui->txe_setQuestionDescription->setText(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->currentRow()]->enunciado);
    ui->txe_setTitle->setText(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->currentRow()]->titulo);
    ui->cbb_difficulty->setCurrentIndex(myProfessor->professorQuestionsList[ui->ltw_setExamQuestionsList->currentRow()]->dificuldade);
}

void MainWindow::on_remover_questao_clicked()//Remover uma questão da prova
{
    if(ui->ltw_setExamQuestionsList->count() > 0){
        myProfessor->professorQuestionsList.removeAt(ui->ltw_setExamQuestionsList->currentRow());
        int c = myProfessor->professorQuestionsList.size();
        ctrl_remover = true;
        ui->ltw_setExamQuestionsList->clear();
        for(int i = 0; i < c; i++){
            ui->ltw_setExamQuestionsList->addItem("Questão " + QString::number(ui->ltw_setExamQuestionsList->count() + 1));
        }
        ctrl_remover = false;
        if(c == 0){
            ui->txe_setQuestionDescription->clear();
            ui->txe_discursiveAnswer->clear();
            ui->txe_setTitle->clear();
            ui->txe_setQuestionDescription->setReadOnly(true);
            ui->txe_discursiveAnswer->setReadOnly(true);
            ui->txe_setTitle->setReadOnly(true);
            ui->g_resposta->setEnabled(false);
            //ui->t_resposta_prog->setEnabled(false);
            ui->cbb_type->setEnabled(false);
            ui->cbb_difficulty->setEnabled(false);
        }
        else{
            ui->ltw_setExamQuestionsList->setCurrentRow(0);
        }
    }
}



void MainWindow::on_btn_professorLogout_clicked()//Logout professor
{
    ui->stw_mainInterface->setCurrentIndex(0);
}

void MainWindow::on_adicionar_questao_clicked()//Criando uma questão para a prova
{
    ui->ltw_setExamQuestionsList->addItem("Questão " + QString::number(ui->ltw_setExamQuestionsList->count() + 1));
    myProfessor->professorQuestionsList.append(new question_prog{"","",0,0,0,{},{}});
    if(ui->txe_setQuestionDescription->isReadOnly()){
        ui->txe_setQuestionDescription->setReadOnly(false);
        ui->txe_setTitle->setReadOnly(false);
        ui->g_resposta->setEnabled(true);
        ui->txe_studentProgrammingAnswers->setEnabled(true);
        ui->cbb_type->setEnabled(true);
        ui->cbb_difficulty->setEnabled(true);
        ui->ltw_setExamQuestionsList->setCurrentRow(0);
    }
}

void MainWindow::on_btn_createExam_clicked()//Gerar XML prova
{
    if(doCreateXmlAnswerKey(myProfessor->professorQuestionsList)){
        QMessageBox::information(this, "Criar Nova Prova", "Prova gerada com sucesso!");
    }
    else{
        QMessageBox::information(this, "Criar Nova Prova", "Houve um erro na criação da prova...");
    }
}

void MainWindow::on_cbb_type_currentIndexChanged(int index)//Resposta responsiva ao tipo de questão na criação de provas
{
    ui->txe_studentProgrammingAnswers->setCurrentIndex(index);
}

void MainWindow::on_btn_addAlternative_clicked()//Adicionar alternativa de múltipla escolha na criação de provas
{
    QListWidgetItem* item = new QListWidgetItem("Nova alternativa");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setCheckState(Qt::Unchecked);
    ui->ltw_multipleChoiceAlternatives->addItem(item);
}

void MainWindow::on_btn_removeAlternative_clicked()//Remover alternativa de múltipla escolha na criação de provas
{
    QListWidgetItem* item = ui->ltw_multipleChoiceAlternatives->currentItem();
    ui->ltw_multipleChoiceAlternatives->removeItemWidget(item);
    delete item;
}

void MainWindow::on_btn_addTest_clicked()//Adicionar par input output na criação de provas
{
    QListWidgetItem* input = new QListWidgetItem("Input");
    QListWidgetItem* output = new QListWidgetItem("Output");
    input->setFlags(input->flags() | Qt::ItemIsEditable);
    output->setFlags(output->flags() | Qt::ItemIsEditable);
    ui->ltw_compilationInput->addItem(input);
    ui->ltw_compilationOutput->addItem(output);
}

void MainWindow::on_btn_removeTest_clicked()//Remover par input output na criação de provas
{
    qDebug() << ui->ltw_compilationInput->count();
    QListWidgetItem* input = ui->ltw_compilationInput->takeItem(ui->ltw_compilationInput->count() - 1);
    QListWidgetItem* output = ui->ltw_compilationOutput->takeItem(ui->ltw_compilationOutput->count() - 1);
    ui->ltw_compilationInput->removeItemWidget(input);
    ui->ltw_compilationOutput->removeItemWidget(output);
    delete input;
    delete output;
}

void MainWindow::on_busca_bd_clicked()//Entrada na janela de busca do banco de dados
{
    if(ui->ltw_setExamQuestionsList->count() > 0){
        ui->stw_mainInterface->setCurrentIndex(4);
        QString command = "SELECT materia FROM materia";
        QSqlQuery query(db);
        if(query.exec(command)){
            while(query.next()){
                ui->materia->addItem({query.value(0).toString()});
            }
        }
    }
    else{
        QMessageBox::information(this, "alertMessage", "Para adicionar uma questão do banco de dados primeiro você precisa de uma questão, seu bundão.");
    }
}

void MainWindow::on_insere_bd_clicked()//Inserir questão no banco de dados
{
    QString command = "SELECT titulo,enunciado FROM questions WHERE titulo = '" + ui->txe_setTitle->toPlainText() + "' OR enunciado = '" + ui->txe_setQuestionDescription->toPlainText() + "'";
    QSqlQuery query(db);
    if(query.exec(command)){
        if(query.size() > 0){
            QMessageBox::information(this, "alertMessage", "Já existe essa questão no banco de dados, cabeção!");
        }
        else{
            QMessageBox::information(this, "alertMessage", "Questão adicionada no banco de dados!");
        }
    }
}
