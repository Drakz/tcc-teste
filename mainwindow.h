#ifndef MAINWINDOW_H
#define MAINWINDOW_H

enum {MESSAGE = 1, ALERT, EXAM};
enum {PROGRAMMING = 1, MULTIPLECHOICE,DISCURSIVE};

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
#include <QtXml>
#include <QRadioButton>
#include <QDateTime>
#include "question.h"
#include "professor.h"
#include "student.h"
#include "xml.h"

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
    //mainwindow
    void on_btn_login_clicked();
    QString getCurrentTime();

    //professor
    void on_btn_createRoom_clicked();
    void on_btn_loadExamFile_clicked();
    void on_btn_closeRoom_clicked();
    void on_btn_setExamStarted_clicked();
    void on_btn_setExamFinished_clicked();
    void on_ltw_setExamQuestionsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void doUpdateQuestion();
    void on_btn_removeQuestion_clicked();
    void on_btn_professorLogout_clicked();
    void on_btn_addQuestion_clicked();
    void on_btn_createExam_clicked();
    void on_cbb_type_currentIndexChanged(int index);
    void on_btn_addAlternative_clicked();
    void on_btn_removeAlternative_clicked();
    void on_btn_addTest_clicked();
    void on_btn_removeTest_clicked();
    void on_btn_searchOnDb_clicked();
    void on_btn_addToDb_clicked();

    //student
    void on_btn_enterRoom_clicked();
    void keyPressEvent(QKeyEvent *key);
    void on_btn_compile_clicked();
    void on_btn_run_clicked();
    void on_btn_studentLogout_clicked();
    void on_btn_startExam_clicked();
    void on_btn_finishExam_clicked();
    void on_ltw_examQuestionsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_ltw_examQuestionsList_currentRowChanged(int currentRow);

    //BD
    void on_btn_closeDbWindow_clicked();
    void on_cbb_questionSubject_currentIndexChanged(int index);
    void on_ltw_dbQuestionList_currentRowChanged(int currentRow);
    void on_btn_addDbQuestionToExam_clicked();
    void on_cbb_questionTopic_currentIndexChanged(int index);

public slots:
    //mainwindow
    int decodeMesage(QString* message);
    QString encodeMessage(QString message, int messageType);

    //professor
    void doProfessorAddNewSocket();
    void doProfessorReadServer();

    //student
    void doStudentReadServer();

private:
    //mainwindow
    Ui::MainWindow *ui;
    QTimer *time;
    bool isWritable = false;
    bool keyMonitoring = false;

    //professor
    professor* myProfessor;

    //student
    student* myStudent;

    //BD
    QList<professorQuestion*> dbQuestionList;

};

#endif // MAINWINDOW_H
