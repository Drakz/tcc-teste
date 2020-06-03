#include "question.h"

question::question(QString t, QString e, int d, int tp)
{
    this->titulo = t;
    this->enunciado = e;
    this->dificuldade = d;
    this->tipo = tp;
}

QString question::imprimir(){
    return titulo + "§" + enunciado + "§" + dificuldade + "§" + tipo;
}

question_prog::question_prog(QString t, QString e, int d, int tp, int qtd, QList<QString> i, QList<QString> o) : question(t,e,d,tp){
    this->qtd_comp = qtd;
    this->input = i;
    this->output = o;
}

void question_prog::getGabarito(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(0);
    ui->s_numcomp->setValue(this->qtd_comp);
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* item = new QListWidgetItem(in);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->l_input->addItem(item);
    }
    foreach(out,this->output){
        QListWidgetItem* item = new QListWidgetItem(out);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->l_output->addItem(item);
    }
}

void question_mult::getGabarito(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(1);
    QString alt;
    foreach(alt,this->alternativas){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->t_resposta_mult->addItem(item);
    }
    if(this->alt_correta != -1){
        ui->t_resposta_mult->item(this->alt_correta)->setCheckState(Qt::Checked);
    }
}

void question_disc::getGabarito(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(2);
    ui->t_resposta_discursiva->setText(this->gabarito);
}

void question_prog::setBanco(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(0);
    ui->bd_l_input->clear();
    ui->bd_l_output->clear();
    ui->enunciado_questao->setText(this->enunciado);
    ui->bd_numcomp->setText(QString::number(this->qtd_comp));
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* item = new QListWidgetItem(in);
        ui->bd_l_input->addItem(item);
    }
    foreach(out,this->output){
        QListWidgetItem* item = new QListWidgetItem(out);
        ui->bd_l_output->addItem(item);
    }
}

void question_mult::setBanco(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(1);
    ui->bd_respmult->clear();
    ui->enunciado_questao->setText(this->enunciado);
    QString alt;
    foreach(alt,this->alternativas){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setCheckState(Qt::Unchecked);
        ui->bd_respmult->addItem(item);
    }
    if(this->alt_correta != -1){
        ui->bd_respmult->item(this->alt_correta)->setCheckState(Qt::Checked);
    }
}

void question_disc::setBanco(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(2);
    ui->enunciado_questao->setText(this->enunciado);
    ui->bd_respdiscursiva->setText(this->gabarito);
}

QString question_prog::imprimir(){
    QString aux = "";
    for(int i = 0; i < this->input.size(); i++){
        aux = this->input[i] + "¬:¬" + this->output[i];
    }

    return aux;
}

QString question_mult::imprimir(){
    return QString::number(this->alt_correta);
}

QString question_disc::imprimir(){
    return this->gabarito;
}
question_mult::question_mult(QString t, QString e, int d, int tp, QList<QString> alt, int alt_cor) : question(t,e,d,tp){
    this->alternativas = alt;
    this->alt_correta = alt_cor;
}

question_disc::question_disc(QString t, QString e, int d, int tp, QString g) : question(t,e,d,tp){
    this->gabarito = g;
}
