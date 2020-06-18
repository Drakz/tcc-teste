#ifndef XML_H
#define XML_H
#include <QDialog>
#include <QtXml>
#include "question.h"

bool doCreateXmlAnswerKey(QList<question*> l_Questoes);
bool doCreateXmlStudentAnswer(QString base);
QList <studentQuestion*> doBuildExam(QString base);
QString getXmlExam(QString directory);



#endif // XML_H
