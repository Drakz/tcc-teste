#ifndef ALUNO_H
#define ALUNO_H

#include <QDialog>

namespace Ui {
class aluno;
}

class aluno : public QDialog
{
    Q_OBJECT

public:
    explicit aluno(QWidget *parent = nullptr);
    ~aluno();

private:
    Ui::aluno *ui;
};

#endif // ALUNO_H
