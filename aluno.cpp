#include "mainwindow.h"

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

void MainWindow::on_logout_aluno_clicked()//Logout aluno
{
    ui->s_principal->setCurrentIndex(0);
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
