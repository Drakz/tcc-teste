#ifndef BUSCA_H
#define BUSCA_H
#include <QDialog>

namespace Ui {
class busca;
}

struct Assunto{
    QString assunto;
    int materia;
    int id;
};

struct Materia{
    QString materia;
};

struct Questao{
    QString enunciado;
    QString resposta;
    QString titulo;
    QString dificuldade;
    int tipo;
    int p = 0;
};

class busca : public QDialog
{
    Q_OBJECT

public:
    explicit busca(QWidget *parent = nullptr, Questao *q = nullptr);
    ~busca();

private slots:
    void on_voltar_clicked();
    //void on_buscar_bd_clicked();
    void on_materia_currentIndexChanged(int index);
    void on_list_questoes_currentRowChanged(int currentRow);
    void on_adicionar_question_clicked();
    void on_assunto_currentIndexChanged(int index);

private:
    Questao *questao;
    QList<Assunto> l_Assunto;
    QList<Materia> l_Materia;
    QList<Questao> l_Questao;
    Ui::busca *ui;
};

#endif // BUSCA_H
