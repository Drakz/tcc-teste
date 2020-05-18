#include "mainwindow.h"

bool static ctrl_remover = false;

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

void MainWindow::on_logout_aluno_clicked()//Logout aluno
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
    if(previous){//Salvo a resposta da questão anterior
        if(l_Questoes[ui->l_prova->row(previous)]->tipo == 1){//Programação
            l_Questoes[ui->l_prova->row(previous)]->resposta = ui->p_resposta->toPlainText();
            ui->p_resposta->clear();
            ui->p_compilador->clear();
        }
        else if(l_Questoes[ui->l_prova->row(previous)]->tipo == 2){//Múltipla escolha
        }
        else if(l_Questoes[ui->l_prova->row(previous)]->tipo == 3){//Discursiva
            l_Questoes[ui->l_prova->row(previous)]->resposta = ui->prova_resposta_discursiva->toPlainText();
            ui->prova_resposta_discursiva->clear();
        }
        ui->p_enunciado->clear();
    }
    if(current && previous){//Carrego as informações da questão atual
        if(l_Questoes[ui->l_prova->row(current)]->tipo == 1){//Programação
            ui->pag_respostas->setCurrentIndex(0);
            ui->p_resposta->setText(l_Questoes[ui->l_prova->row(previous)]->resposta);
        }
        else if(l_Questoes[ui->l_prova->row(current)]->tipo == 2){//Múltipla escolha
            ui->pag_respostas->setCurrentIndex(1);
            QVBoxLayout *vbox = new QVBoxLayout();
            for (int i = 0; i < static_cast<question_mult*>(l_Questoes[ui->l_prova->row(current)])->alternativas.size(); i++) {
                QRadioButton *button = new QRadioButton(static_cast<question_mult*>(l_Questoes[ui->l_prova->row(current)])->alternativas[i]);
                vbox->addWidget(button);
            }
            ui->g_alternativas->setLayout(vbox);
        }
        else if(l_Questoes[ui->l_prova->row(current)]->tipo == 3){//Discursiva
            ui->pag_respostas->setCurrentIndex(2);
            ui->prova_resposta_discursiva->setPlainText(l_Questoes[ui->l_prova->row(previous)]->resposta);
        }
        ui->p_enunciado->setText(l_Questoes[ui->l_prova->row(current)]->enunciado);
    }
}

void MainWindow::on_l_prova_currentRowChanged(int currentRow)//Habilitar ou não botões de compilação e execução
{
    if(l_Questoes[currentRow]->tipo == 1 && static_cast<question_prog*>(l_Questoes[currentRow])->qtd_comp > 0){
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

void MainWindow::on_gerar_prova_clicked()//TODO
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

void MainWindow::on_b_compilar_clicked()//Compilar código para o aluno
{
    QString codigo = ui->p_resposta->toPlainText();
    QString path = "code.c";
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return;
    }
    QTextStream out(&file);
    out << codigo << endl;
    QProcess comp;
    comp.setProcessChannelMode(QProcess::MergedChannels);
    comp.start("gcc -g code.c -o code");
    comp.waitForFinished();
    QString resp = comp.readAll();
    if(resp != "")
        ui->p_compilador->setText(resp);
    else
        ui->p_compilador->setText("Compilado com Sucesso!");
}

void MainWindow::on_b_executar_clicked()//Executar código para o aluno
{
    system("code");
}
