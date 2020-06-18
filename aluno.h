#ifndef student_H
#define student_H

#include "mysocket.h"
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
#endif // student_H
