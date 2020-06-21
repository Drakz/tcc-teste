#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <QListWidgetItem>
#include <QMessageBox>
#include "myserver.h"
#include "question.h"

class professor : QObject{
public:
    professor();
    MyServer professorServer;
    QString exam;
    QList <professorQuestion*> professorQuestionsList;

public slots:

private:
};

#endif // PROFESSOR_H
