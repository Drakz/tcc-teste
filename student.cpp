#include "student.h"
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
    if(!myStudent->studentSocket.connect(ui->txt_roomHostName->text(),ui->spb_roomPort->value())){
        QMessageBox::information(this,"Status da Conexão","Você está conectado!");
        ui->stw_doExam->setCurrentIndex(1);
    }
    else{
        QMessageBox::critical(this,"Status da Conexão","A conexão falhou...");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *key){
    if(keyMonitoring){
        QString alertMessage;
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
    static_cast<studentProgrammingQuestion*>(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->currentRow()])->setCompilationAmount(static_cast<studentProgrammingQuestion*>(myStudent->studentQuestionsList[ui->ltw_examQuestionsList->currentRow()])->getCompilationAmount()-1);
    QString studentCode = ui->txe_studentProgrammingAnswer->toPlainText();
    QString questionNumber = QString::number(ui->ltw_examQuestionsList->currentRow());
    QString path = "C://code" + questionNumber + ".c";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    QTextStream out(&file);
    out << studentCode << endl;
    QProcess studentProgram;
    QString studentProcess = "gcc";
    QStringList studentProcessArguments = {"-g", "code"+questionNumber+".c", "-o", "code"+questionNumber};
    studentProgram.setProcessChannelMode(QProcess::MergedChannels);
    studentProgram.start(studentProcess, studentProcessArguments);
    studentProgram.waitForFinished();
    QString compilerOutput = studentProgram.readAll();
    if(compilerOutput != "")
        ui->txe_compilerOutput->setText(compilerOutput);
    else
        ui->txe_compilerOutput->setText("Compilado com Sucesso!");

}

void MainWindow::on_btn_run_clicked()//Executar código para o student
{
    QString questionNumber = QString::number(ui->ltw_examQuestionsList->currentRow());
    QString systemCall = "code" + questionNumber;
    system(systemCall.toUtf8());
}

void MainWindow::on_btn_studentLogout_clicked()//Logout student
{
    ui->stw_mainInterface->setCurrentIndex(0);
}

void MainWindow::on_btn_startExam_clicked()//teste
{
    myStudent->studentSocket.doSocketWrite(encodeMessage(myStudent->studentId + ":\n(" + getCurrentTime() + ") iniciou a prova!" ,MESSAGE));
    keyMonitoring = true;
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
    keyMonitoring = false;
    ui->lbl_doExamMessage->setText("Aguardando recebimento da prova...");
    ui->stw_mainInterface->setCurrentIndex(1);
}

void MainWindow::on_ltw_examQuestionsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){//Mudança e armazenamento das questões da prova pelo student
    if(previous){//Salvo a resposta da questão anterior
        doSaveQuestionInStudentList(ui->ltw_examQuestionsList->row(previous));
    }
    if(current && previous){//Carrego as informações da questão atual
        doUpdateStudentQuestion(ui->ltw_examQuestionsList->row(current));
    }
}

void MainWindow::doUpdateStudentQuestion(int index){
    if(myStudent->studentQuestionsList[index]->getQuestionType() == PROGRAMMING){//Programação
        ui->stw_studentAnswers->setCurrentIndex(0);
        ui->txe_studentProgrammingAnswer->setText(myStudent->studentQuestionsList[index]->getStudentAnswer());
    }
    else if(myStudent->studentQuestionsList[index]->getQuestionType() == MULTIPLECHOICE){//Múltipla escolha
        ui->stw_studentAnswers->setCurrentIndex(1);
        QLayout *layout = ui->gbx_alternatives->layout();
        QLayoutItem *child;
        if(ui->gbx_alternatives->layout()->itemAt(0) != 0){
            while ((child = layout->takeAt(0)) != 0) {
                delete child->widget();
                delete child;
            }
        }
        for (int i = 0; i < static_cast<studentMultipleChoiceQuestion*>(myStudent->studentQuestionsList[index])->getAlternatives().size(); i++) {
            QCheckBox *checkBox = new QCheckBox(static_cast<studentMultipleChoiceQuestion*>(myStudent->studentQuestionsList[index])->getAlternatives()[i]);
            ui->gbx_alternatives->layout()->addWidget(checkBox);
        }
    }
    else if(myStudent->studentQuestionsList[index]->getQuestionType() == DISCURSIVE){//Discursiva
        ui->stw_studentAnswers->setCurrentIndex(2);
        ui->ptx_studentDiscursiveAnswer->setPlainText(myStudent->studentQuestionsList[index]->getStudentAnswer());
    }
    ui->txe_questionDescription->setText(myStudent->studentQuestionsList[index]->getQuestionDescription());
}

void MainWindow::doSaveQuestionInStudentList(int index){
    if(myStudent->studentQuestionsList[index]->getQuestionType() == PROGRAMMING){//Programação
        myStudent->studentQuestionsList[index]->setStudentAnswer(ui->txe_studentProgrammingAnswer->toPlainText());
        static_cast<studentProgrammingQuestion*>(myStudent->studentQuestionsList[index])->setCompilerOutput(ui->txe_compilerOutput->toPlainText());
    }
    else if(myStudent->studentQuestionsList[index]->getQuestionType() == MULTIPLECHOICE){//Múltipla escolha
        QLayout *layout = ui->gbx_alternatives->layout();
        QLayoutItem *child;
        if(ui->gbx_alternatives->layout()->itemAt(0) != 0){
            while ((child = layout->takeAt(0)) != 0) {
                if(static_cast<QCheckBox*>(child->widget())->checkState() == Qt::Checked){
                    static_cast<studentMultipleChoiceQuestion*>(myStudent->studentQuestionsList[index])->setStudentAnswer("3");//checar qual a certa
                }
            }
        }
    }
    else if(myStudent->studentQuestionsList[index]->getQuestionType() == DISCURSIVE){//Discursiva
        myStudent->studentQuestionsList[index]->setStudentAnswer(ui->txe_studentProgrammingAnswer->toPlainText());
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

