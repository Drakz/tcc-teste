#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <QList>
#include <QtXml>
#include "ui_MainWindow.h"

class question{
public:
    question(int _type, QString _questionDescription);
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
    professorQuestion(int _type, QString _questionDescription, QString _title, int _difficulty);
    virtual QDomElement toXml() = 0;
    virtual void setAnswer(Ui::MainWindow *ui) = 0;
    virtual void setDatabase(Ui::MainWindow *ui) = 0;
    void setTitle(QString _title);
    QString getTitle();
    void setDifficulty(int _difficulty);
    int getDifficulty();
protected:
    QString title;
    int difficulty;
};

class professorProgrammingQuestion: public professorQuestion{
public:
    professorProgrammingQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, int _compilationAmount, QList<QString> _input, QList<QString> _output);
    QDomElement toXml();
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setInput(QList<QString> _input);
    QList<QString> getInput();
    void setOutput(QList<QString> _output);
    QList<QString> getOutput();
    void setCompilationAmount(int _compilationAmount);
    int getCompilationAmount();
private:
    QList<QString> input;
    QList<QString> output;
    int compilationAmount = 0;
};

class professorMultipleChoiceQuestion: public professorQuestion{
public:
    professorMultipleChoiceQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, QList<QString> _alternatives, int _correctChoice);
    QDomElement toXml();
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setAlternatives(QList<QString> _alternatives);
    QList<QString> getAlternatives();
    void setCorrectChoice(int _correctChoice);
    int getCorrectChoice();
private:
    QList<QString> alternatives;
    int correctChoice = -1;
};

class professorDiscursiveQuestion: public professorQuestion{
public:
    professorDiscursiveQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, QString _correctAnswer);
    QDomElement toXml();
    void setAnswer(Ui::MainWindow *ui);
    void setDatabase(Ui::MainWindow *ui);
    void setCorrectAnswer(QString _correctAnswer);
    QString getCorrectAnswer();
private:
    QString correctAnswer;
};

//student questions
class studentQuestion: public question
{
public:
    studentQuestion(int _type, QString _questionDescription);
    virtual void setStudentAnswer(QString _studentAnswer) = 0;
    virtual QString getStudentAnswer() = 0;
};

class studentDiscursiveQuestion: public studentQuestion
{
public:
    studentDiscursiveQuestion(int type, QString questionDescription);
    void setStudentAnswer(QString _studentAnswer);
    QString getStudentAnswer();
private:
    QString studentAnswer;
};

class studentProgrammingQuestion: public studentQuestion{
public:
    studentProgrammingQuestion(int _type, QString _questionDescription, int _compilationAmount);
    void setCompilerOutput(QString _compilerOutput);
    QString getCompilerOutput();
    void setStudentAnswer(QString _studentAnswer);
    QString getStudentAnswer();
    void setCompilationAmount(int _compilationAmount);
    int getCompilationAmount();
private:
    int compilationAmount;
    QString compilerOutput;
    QString studentAnswer;
};

class studentMultipleChoiceQuestion: public studentQuestion{
public:
    studentMultipleChoiceQuestion(int _type, QString _questionDescription, QList<QString> _alternatives);
    void setStudentAnswer(QString _studentAnswer);
    QString getStudentAnswer();
    QList<QString> getAlternatives();
private:
    QList<QString> alternatives;
    int studentAnswer;
};

#endif // QUESTION_H
