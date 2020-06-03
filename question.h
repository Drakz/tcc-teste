#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <QList>
#include "ui_mainwindow.h"

class question
{
public:
    question(QString t, QString e, int d, int tp);
    QString titulo;
    QString enunciado;
    QString resposta = "";
    int dificuldade;
    int tipo;
    virtual QString imprimir() = 0;
    virtual void getGabarito(Ui::MainWindow *ui) = 0;
    virtual void setBanco(Ui::MainWindow *ui) = 0;
};

class question_prog: public question{
public:
    question_prog(QString t, QString e, int d, int tp, int qtd, QList<QString> i, QList<QString> o);
    QString imprimir();
    void getGabarito(Ui::MainWindow *ui);
    void setBanco(Ui::MainWindow *ui);
    QList<QString> input;
    QList<QString> output;
    int qtd_comp = 0;
};

class question_mult: public question{
public:
    QString imprimir();
    void getGabarito(Ui::MainWindow *ui);
    void setBanco(Ui::MainWindow *ui);
    question_mult(QString t, QString e, int d, int tp, QList<QString> alt, int alt_cor);
    QList<QString> alternativas;
    int alt_correta = -1;
};

class question_disc: public question{
public:
    QString imprimir();
    void getGabarito(Ui::MainWindow *ui);
    void setBanco(Ui::MainWindow *ui);
    question_disc(QString t, QString e, int d, int tp, QString g);
    QString gabarito;
};

#endif // QUESTION_H
