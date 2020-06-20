#include "xml.h"

bool doCreateXmlAnswerKey(QList <professorQuestion*> professorQuestionsList){
    QDomDocument answerKey;
    QDomElement root = answerKey.createElement("Prova");
    answerKey.appendChild(root);
    QDomElement questions = answerKey.createElement("Questoes");
    for(int i = 0; i < professorQuestionsList.size(); i++){
        questions.appendChild(professorQuestionsList[i]->toXml());
    }
    root.appendChild(questions);
    QFile xmlFile("C:/Users/eduar/Desktop/Nova pasta/XmlProva.special");
    if (!xmlFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "File open failed";
        return 0;
    }
    else{
        QTextStream stream (&xmlFile);
        stream << answerKey;
        xmlFile.close();
        qDebug() << "Prova criada com sucesso!";
        return 1;
    }

}

bool doCreateXmlStudentAnswer(QString base){
    if(base != "")
        return true;
    return false;
}

QString getXmlExam(QString directory){
    QDomDocument xmlExam;
    QString exam = "";
    QFile answerKey(directory);
    if(!answerKey.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file...";
        return "";
    }
    else{
        if(!xmlExam.setContent(&answerKey)){
            qDebug() << "Failed to load document...";
            return "";
        }
        answerKey.close();
    }

    QDomElement root = xmlExam.firstChildElement();

    QDomNodeList questions = root.elementsByTagName("Question");
    for(int i = 0; i< questions.count(); i++){
        QDomNode questionNode = questions.at(i);

        if(questionNode.isElement()){
            if(questionNode.isElement()){
                QDomElement itemElement = questionNode.toElement();
                qDebug() << itemElement.attribute("Type");
                if(itemElement.attribute("Type") == "1"){

                    exam = exam + itemElement.attribute("Type") + "¬||¬" + itemElement.attribute("QuestionDescription") + "¬||¬" + itemElement.attribute("CompilationAmount") + "¬|¬";
                }
                else if(itemElement.attribute("Type") == "2"){
                        exam = exam + itemElement.attribute("Type") + "¬||¬" + itemElement.attribute("QuestionDescription") + "¬||¬" + itemElement.attribute("Alternatives") + "¬|¬";
                }
                else if(itemElement.attribute("Type") == "3"){
                        exam = exam + itemElement.attribute("Type") + "¬||¬" + itemElement.attribute("QuestionDescription") + "¬|¬";
                }
            }
        }
    }

    qDebug() << "Finished getting Xml Exam";
    qDebug() << exam;
    return exam;
}

QList <studentQuestion*> doBuildExam(QString base){
    QList <studentQuestion*> exam;
    QStringList questions = base.split("¬|¬");

    for(int i = 0; i < questions.count(); i++){
        QStringList parameters = questions[i].split("¬||¬");
        if(parameters[0].toInt() == 1){
            exam[i] = new studentDiscursiveQuestion(1, parameters[1]);
        }
        else
            if( parameters[0].toInt() == 2){
                QStringList alternatives;
                for(int j = 2; j < parameters.count(); j++){
                    alternatives[j-2] = parameters[j];
                }
                exam[i] = new studentMultipleChoiceQuestion(2, parameters[1], alternatives);
            }
                else {
                    if( parameters[0].toInt() == 3){
                        for(int j = 2; j < parameters.count(); j++){
                           exam[i] = new studentProgrammingQuestion(2, parameters[1], parameters[2].toInt());
                        }
                    }
                }
    }
    return exam;
}
