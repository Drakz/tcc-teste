#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <QList>
#include <QtXml>
#include "ui_mainwindow.h"

class question{
public:
    question(int type, QString questionDescription);
    ~question();
    int getQuestionType();
    QString getQuestionDescription();
protected:
    int type;
    QString questionDescription;
};

//professor questions
class professorQuestion: public question
{
public:
    professorQuestion(int type, QString questionDescription, QString title, int difficulty);
    virtual QDomElement toXml(QDomDocument exam) = 0;
    virtual void setAnswer(Ui::MainWindow *ui) = 0;
    virtual void setDatabase(Ui::MainWindow *ui) = 0;
    void setTitle(QString title);
    QString getTitle();
    void setDifficulty(int difficulty);
    int getDifficulty();
protected:
    QString title;
    int difficulty;
};

class professorProgrammingQuestion: public professorQuestion{
public:
    professorProgrammingQuestion(int type, QString questionDescription, QString title, int difficulty, int compilationAmount, QList<QString> input, QList<QString> output);
    QDomElement toXml(QDomDocument exam);
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setInput(QList<QString> input);
    QList<QString> getInput();
    void setOutput(QList<QString> output);
    QList<QString> getOutput();
    void setCompilationAmount(int compilationAmount);
    int getCompilationAmount();
private:
    QList<QString> input;
    QList<QString> output;
    int compilationAmount = 0;
};

class professorMultipleChoiceQuestion: public professorQuestion{
public:
    professorMultipleChoiceQuestion(int type, QString questionDescription, QString title, int difficulty, QList<QString> alternatives, int correctChoice);
    QDomElement toXml(QDomDocument exam);
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setAlternatives(QList<QString> alternatives);
    QList<QString> getAlternatives();
    void setCorrectChoice(int correctChoice);
    int getCorrectChoice();
private:
    QList<QString> alternatives;
    int correctChoice = -1;
};

class professorDiscursiveQuestion: public professorQuestion{
public:
    professorDiscursiveQuestion(int type, QString questionDescription, QString title, int difficulty, QString correctAnswer);
    QDomElement toXml(QDomDocument exam);
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setCorrectAnswer(QString correctAnswer);
    QString getCorrectAnswer();
private:
    QString correctAnswer;
};

//student questions
class studentDiscursiveQuestion: public question
{
public:
    studentDiscursiveQuestion(int type, QString questionDescription);
    void setStudentAnswer(QString studentAnswer);
    QString getStudentAnswer();
private:
    QString studentAnswer;
};

class studentProgrammingQuestion: public question{
public:
    studentProgrammingQuestion(int type, QString questionDescription, int compilationAmount);
    void setCompilerOutput(QString compilerOutput);
    QString getCompilerOutput();
    void setStudentAnswer(QString studentAnswer);
    QString getStudentAnswer();
    void setCompilationAmount(int compilationAmount);
    int getCompilationAmount();
private:
    int compilationAmount;
    QString compilerOutput;
    QString studentAnswer;
};

class studentMultipleChoiceQuestion: public question{
public:
    studentMultipleChoiceQuestion(int type, QString questionDescription, QList<QString> alternatives);
    void setStudentChoice(int studentChoice);
    int getStudentChoice();
    QList<QString> getAlternatives();
private:
    QList<QString> alternatives;
    int studentChoice;
};

#endif // QUESTION_H
