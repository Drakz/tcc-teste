#include "aluno.h"
#include "mainwindow.h"


student::student(){
    studentSocket.socket = &studentSocket;
}

void MainWindow::doStudentReadServer(){
    QString readFromServer = myStudent->studentSocket.doSocketRead();
    int messageType = decodeMesage(&readFromServer);

    switch (messageType) {
        case MESSAGE:

        break;

        case ALERT:

        break;

        case EXAM:
            myStudent->studentQuestionsList = doBuildExam(readFromServer);
            ui->lbl_doExamMessage->setText("A prova pode ser iniciada!");
            ui->btn_startExam->setEnabled(true);
        break;

    }
}

void MainWindow::on_btn_enterRoom_clicked(){
    if(!myStudent->studentSocket.connect(ui->txt_roomHostName->text(),ui->spb_roomDoor->value())){
        QMessageBox::information(this,"Status da Conexão","Você está conectado!");
        ui->stw_doExam->setCurrentIndex(1);
    }
    else{
        QMessageBox::critical(this,"Status da Conexão","A conexão falhou...");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *key){
    QString alertMessage;
    if(myStudent->keyMonitoring){
        int pressedKey = key->key();

        switch(pressedKey){

        case Qt::Key_Meta:
            alertMessage = myStudent->studentId + " pressionou a tecla Windows!";
            break;

        case Qt::Key_Alt:
            alertMessage = myStudent->studentId + " pressionou a tecla Alt!";
            break;

        case Qt::Key_Control:
            alertMessage = myStudent->studentId + " pressionou a tecla Ctrl!";
            break;
        }
        if(alertMessage != NULL){
            myStudent->studentSocket.doSocketWrite(encodeMessage(alertMessage, ALERT));
        }
    }
}


void MainWindow::on_btn_compile_clicked()//Compilar código para o student
{
    QString studentCode = ui->txe_studentProgrammingAnswer->toPlainText();
    QString path = "C://code.c";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    QTextStream out(&file);
    out << studentCode << endl;
    QProcess studentProgram;
    studentProgram.setProcessChannelMode(QProcess::MergedChannels);
    studentProgram.start("gcc -g code.c -o code");
    studentProgram.waitForFinished();
    QString compilerOutput = studentProgram.readAll();
    if(compilerOutput != "")
        ui->txe_compilerOutput->setText(compilerOutput);
    else
        ui->txe_compilerOutput->setText("Compilado com Sucesso!");
}

void MainWindow::on_btn_run_clicked()//Executar código para o student
{
    system("code");
}

void MainWindow::on_btn_studentLogout_clicked()//Logout student
{
    ui->stw_mainInterface->setCurrentIndex(0);
}

void MainWindow::on_btn_startExam_clicked()//teste
{
    myStudent->studentSocket.doSocketWrite(encodeMessage(myStudent->studentId + ":\n(" + getCurrentTime() + ") iniciou a prova!" ,MESSAGE));
    myStudent->keyMonitoring = true;
    int listSize = myStudent->studentQuestionsList.size();
    QVBoxLayout *vbox = new QVBoxLayout();
    ui->gbx_alternatives->setLayout(vbox);
    ui->ltw_examQuestionsList->clear();
    for(int i = 0; i < listSize; i++){
        ui->ltw_examQuestionsList->addItem("Questão " + QString::number(ui->ltw_examQuestionsList->count() + 1));
    }
    ui->ltw_examQuestionsList->setCurrentRow(0);
    ui->stw_mainInterface->setCurrentIndex(3);
}

void MainWindow::on_btn_finishExam_clicked()//teste
{
    myStudent->studentSocket.doSocketWrite(encodeMessage(myStudent->studentId + ":\n(" + getCurrentTime() + ") terminou a prova!" ,MESSAGE));
    myStudent->keyMonitoring = false;
    ui->lbl_doExamMessage->setText("Aguardando recebimento da prova...");
    ui->stw_mainInterface->setCurrentIndex(1);
}

void MainWindow::on_ltw_examQuestionsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){//Mudança e armazenamento das questões da prova pelo student
    if(previous){//Salvo a resposta da questão anterior
        if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == PROGRAMMING){//Programação
            myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->setStudentAnswer(ui->txe_studentProgrammingAnswer->toPlainText());
            ui->txe_studentProgrammingAnswer->clear();
            ui->txe_compilerOutput->clear();
        }
        else if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == MULTIPLECHOICE){//Múltipla escolha
        }
        else if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == DISCURSIVE){//Discursiva
            myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->setStudentAnswer(ui->txe_studentProgrammingAnswer->toPlainText());
            ui->ptx_studentDiscursiveAnswer->clear();
        }
        ui->txe_questionDescription->clear();
    }
    if(current && previous){//Carrego as informações da questão atual
        if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == PROGRAMMING){//Programação
            ui->stw_studentAnswers->setCurrentIndex(0);
            ui->txe_studentProgrammingAnswer->setText(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getStudentAnswer());
        }
        else if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == MULTIPLECHOICE){//Múltipla escolha
            ui->stw_studentAnswers->setCurrentIndex(1);
            QLayout *layout = ui->gbx_alternatives->layout();
            QLayoutItem *child;
            if(ui->gbx_alternatives->layout()->itemAt(0) != 0){
                while ((child = layout->takeAt(0)) != 0) {
                    delete child->widget();
                    delete child;
                }
            }
            for (int i = 0; i < static_cast<studentMultipleChoiceQuestion*>(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(current)])->getAlternatives().size(); i++) {
                QRadioButton *button = new QRadioButton(static_cast<studentMultipleChoiceQuestion*>(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(current)])->getAlternatives()[i]);
                ui->gbx_alternatives->layout()->addWidget(button);
            }
        }
        else if(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getQuestionType() == DISCURSIVE){//Discursiva
            ui->stw_studentAnswers->setCurrentIndex(2);
            ui->ptx_studentDiscursiveAnswer->setPlainText(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(previous)]->getStudentAnswer());
        }
        ui->txe_questionDescription->setText(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->row(current)]->getQuestionDescription());
    }
}

void MainWindow::on_ltw_examQuestionsList_currentRowChanged(int currentRow)//Habilitar ou não botões de compilação e execução
{
    if(myStudent->studentQuestionsList[currentRow]->getQuestionType() == PROGRAMMING && static_cast<studentProgrammingQuestion*>(myStudent->studentQuestionsList[currentRow])->getCompilationAmount() > 0){
        ui->btn_compile->setText("Compilar - [" + QString::number(static_cast<studentProgrammingQuestion*>(myStudent->studentQuestionsList[currentRow])->getCompilationAmount()) + "]");
        ui->btn_compile->setEnabled(true);
        ui->btn_run->setEnabled(true);
    }
    else{
        ui->btn_compile->setText("Compilar");
        ui->btn_compile->setEnabled(false);
        ui->btn_run->setEnabled(false);
    }
}
