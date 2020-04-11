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
#include "question.h"

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
    void on_insere_bd_clicked();
    void on_b_entraprova_clicked();
    void on_b_entregaprova_clicked();
    void on_l_prova_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_l_prova_currentRowChanged(int currentRow);
    void on_voltar_clicked();
    void on_materia_currentIndexChanged(int index);
    void on_list_questoes_currentRowChanged(int currentRow);
    void on_adicionar_question_clicked();
    void on_assunto_currentIndexChanged(int index);

    void on_gerar_prova_clicked();

private:
    QList<question*> bd_question;
    QList<question*> l_Questoes;
    QList<QString> l_Assunto;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
