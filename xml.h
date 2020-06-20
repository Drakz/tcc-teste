#ifndef XML_H
#define XML_H
#include <QDialog>
#include <QtXml>
#include <QtCore>
#include "question.h"

bool doCreateXmlAnswerKey(QList<professorQuestion*> l_Questoes);
bool doCreateXmlStudentAnswer(QString base);
QList <studentQuestion*> doBuildExam(QString base);
QString getXmlExam(QString directory);

#endif // XML_H

