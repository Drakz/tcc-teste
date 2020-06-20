#ifndef STUDENT_H
#define STUDENT_H

#include <QListWidgetItem>
#include "mysocket.h"
#include "question.h"
#include <QKeyEvent>

class student : QObject{
public:
    student();
    MySocket studentSocket;
    QString studentId;
    bool keyMonitoring = false;

    QList <studentQuestion*> studentQuestionsList;


};
#endif // STUDENT_H

