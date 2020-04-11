#include "question.h"

question::question(QString t, QString e, QString g, QString r, int d, int tp)
{
    this->titulo = t;
    this->enunciado = e;
    this->gabarito = g;
    this->resposta = r;
    this->dificuldade = d;
    this->tipo = tp;
}

QString question::imprimir(){
    return titulo + "§" + enunciado + "§" + gabarito + "§" + dificuldade + "§" + tipo;
}

question_prog::question_prog(QString t, QString e, QString g, QString r, int d, int tp, int qtd) : question(t,e,g,r,d,tp){
    this->qtd_comp = qtd;
}
