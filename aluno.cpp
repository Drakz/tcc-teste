#include "aluno.h"
#include "ui_aluno.h"

aluno::aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aluno)
{
    ui->setupUi(this);
}

aluno::~aluno()
{
    delete ui;
}
