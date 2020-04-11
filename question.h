#ifndef QUESTION_H
#define QUESTION_H
#include <QString>

class question
{
public:
    question(QString t, QString e, QString g, QString r, int d, int tp);
    QString imprimir();
    QString titulo;
    QString enunciado;
    QString gabarito;
    QString resposta;
    int dificuldade;
    int tipo;
};

class question_prog: public question{
public:
    question_prog(QString t, QString e, QString g, QString r, int d, int tp, int qtd);
    int qtd_comp;
};

class question_mult: public question{
public:

};

class question_disc: public question{
public:

};

#endif // QUESTION_H
