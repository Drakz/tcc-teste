#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>
#include "busca.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_busca_bd_clicked();

    void on_logout_professor_clicked();

    void on_logout_aluno_clicked();

    void on_adicionar_questao_clicked();

    void on_lista_questoes_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_remover_questao_clicked();

private:
    Questao tmp_questao;
    QList<Questao> l_Questoes;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
