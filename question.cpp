#include "question.h"
//CONSTRUCTORS
//super class
question::question(int _type, QString _questionDescription){
    this->type = _type;
    this->questionDescription = _questionDescription;
}
//professor classes
professorQuestion::professorQuestion(int _type, QString _questionDescription, QString _title, int _difficulty) : question (_type, _questionDescription){
    this->title = _title;
    this->difficulty = _difficulty;
}

professorProgrammingQuestion::professorProgrammingQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, int _compilationAmount, QList<QString> _input, QList<QString> _output) : professorQuestion(_type,_questionDescription,_title,_difficulty){
    this->compilationAmount = _compilationAmount;
    this->input = _input;
    this->output = _output;
}

professorMultipleChoiceQuestion::professorMultipleChoiceQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, QList<QString> _alternatives, int _correctChoice) : professorQuestion(_type,_questionDescription,_title,_difficulty){
    this->alternatives = _alternatives;
    this->correctChoice = _correctChoice;
}

professorDiscursiveQuestion::professorDiscursiveQuestion(int _type, QString _questionDescription, QString _title, int _difficulty, QString _correctAnswer) : professorQuestion(_type,_questionDescription,_title,_difficulty){
    this->correctAnswer = _correctAnswer;
}
//student classes

studentQuestion::studentQuestion(int _type, QString _questionDescription) : question (_type, _questionDescription){

}

studentDiscursiveQuestion::studentDiscursiveQuestion(int _type, QString _questionDescription) : studentQuestion (_type, _questionDescription){

}

studentProgrammingQuestion::studentProgrammingQuestion(int _type, QString _questionDescription, int _compilationAmount) : studentQuestion (_type, _questionDescription){
    this->compilationAmount = _compilationAmount;
}

studentMultipleChoiceQuestion::studentMultipleChoiceQuestion(int _type, QString _questionDescription, QList<QString> _alternatives) : studentQuestion (_type, _questionDescription){
    this->alternatives = _alternatives;
}

//DESTRUCTORS
question::~question(){}

//question functions
int question::getQuestionType(){
    return this->type;
}
QString question::getQuestionDescription(){
    return this->questionDescription;
}

//professorQuestion functions
void professorQuestion::setTitle(QString _title){
    this->title = _title;
}
QString professorQuestion::getTitle(){
    return this->title;
}
void professorQuestion::setDifficulty(int _difficulty){
    this->difficulty = _difficulty;
}
int professorQuestion::getDifficulty(){
    return this->difficulty;
}

//professorProgrammingQuestion functions
QDomElement professorProgrammingQuestion::toXml(){
    QDomDocument exam;
    QDomElement question = exam.createElement("Question");
    question.setAttribute("QuestionDescription", this->questionDescription);
    question.setAttribute("Difficulty", this->difficulty);
    question.setAttribute("Type", this->type);
    QString input = "";
    QString output = "";
    for(int i = 0; i < this->input.size(); i++){
        input.append(this->input[i] + "¬||¬");
        output.append(this->output[i] + "¬||¬");
    }
    question.setAttribute("Inputs", input);
    question.setAttribute("Outputs", output);
    question.setAttribute("CompilationAmount", this->compilationAmount);
    return question;
}

void professorProgrammingQuestion::setAnswer(Ui::MainWindow *ui){
    ui->cbb_type->setCurrentIndex(0);
    ui->ltw_compilationInput->clear();
    ui->spb_compilationAmount->setValue(this->getCompilationAmount());
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* itemInput = new QListWidgetItem(in);
        itemInput->setFlags(itemInput->flags() | Qt::ItemIsEditable);
        ui->ltw_compilationInput->addItem(itemInput);
        QListWidgetItem* itemOutput = new QListWidgetItem(out);
        itemOutput->setFlags(itemOutput->flags() | Qt::ItemIsEditable);
        ui->ltw_compilationOutput->addItem(itemOutput);
    }
}

void professorProgrammingQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stw_dbQuestions->setCurrentIndex(0);
    ui->ltw_dbCompilationInput->clear();
    ui->ltw_dbCompilationOutput->clear();
    ui->txe_dbQuestionDescription->setText(this->questionDescription);
    ui->spb_dbCompilationAmount->setText(QString::number(this->compilationAmount));
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* item = new QListWidgetItem(in);
        ui->ltw_dbCompilationInput->addItem(item);
    }
    foreach(out,this->output){
        QListWidgetItem* item = new QListWidgetItem(out);
        ui->ltw_dbCompilationOutput->addItem(item);
    }
}

bool professorProgrammingQuestion::doSaveInDb(QSqlDatabase* db){
    if(this->input.size() == 0){
        return false;
    }
    else{
        QString answer = "";
        for (int j = 0; j < this->input.size(); j++){
            answer.append(this->input[j] + "¬:¬" + this->output[j] + "¬:¬");
        }
        answer.append("¬:¬" + QString::number(this->compilationAmount));
        QString command;
        QSqlQuery query(*db);
        command = "INSERT INTO questions (enunciado, tipo, resposta, flag_assunto, titulo, dificuldade) VALUES ('"+this->questionDescription+"', '"+ QString::number(this->type) +"', '"+answer+"', '"+QString::number(1)+"', '"+this->title+"', '"+QString::number(this->difficulty)+"')";
        if(query.exec(command)){
            return true;
        }
        else{
            return false;
        }
    }
}

void professorProgrammingQuestion::setInput(QList<QString> _input){
    this->input = _input;
}
QList<QString> professorProgrammingQuestion::getInput(){
    return this->input;
}
void professorProgrammingQuestion::setOutput(QList<QString> _output){
    this->output = _output;
}
QList<QString> professorProgrammingQuestion::getOutput(){
    return this->output;
}
void professorProgrammingQuestion::setCompilationAmount(int _compilationAmount){
    this->compilationAmount = _compilationAmount;
}
int professorProgrammingQuestion::getCompilationAmount(){
    return this->compilationAmount;
}

//professorMultipleChoiceQuestion functions
QDomElement professorMultipleChoiceQuestion::toXml(){
    QDomDocument exam;
    QDomElement question = exam.createElement("Question");
    question.setAttribute("QuestionDescription", this->questionDescription);
    question.setAttribute("Difficulty", this->difficulty);
    question.setAttribute("Type", this->type);
    QString alternatives = "";
    for(int i = 0; i < this->alternatives.size(); i++){
        alternatives.append(this->alternatives[i] + "¬||¬");
    }
    question.setAttribute("Alternatives", alternatives);
    question.setAttribute("CorrectChoice", this->correctChoice);
    return question;
}

void professorMultipleChoiceQuestion::setAnswer(Ui::MainWindow *ui){
    ui->cbb_type->setCurrentIndex(1);
    ui->ltw_multipleChoiceAlternatives->clear();
    QString alt;
    foreach(alt,this->alternatives){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->ltw_multipleChoiceAlternatives->addItem(item);
    }
    if(this->correctChoice != -1){
        ui->ltw_multipleChoiceAlternatives->item(this->correctChoice)->setCheckState(Qt::Checked);
    }
}

void professorMultipleChoiceQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stw_dbQuestions->setCurrentIndex(1);
    ui->ltw_dbMultipleChoiceAlternatives->clear();
    ui->txe_dbQuestionDescription->setText(this->questionDescription);
    QString alt;
    foreach(alt,this->alternatives){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setCheckState(Qt::Unchecked);
        ui->ltw_dbMultipleChoiceAlternatives->addItem(item);
    }
    if(this->correctChoice != -1){
        ui->ltw_dbMultipleChoiceAlternatives->item(this->correctChoice)->setCheckState(Qt::Unchecked);
    }
}

bool professorMultipleChoiceQuestion::doSaveInDb(QSqlDatabase* db){
    if(this->alternatives.size() == 0){
        return false;
    }
    else{
        QString answer = "";
        for (int j = 0; j < this->alternatives.size(); j++){
            answer.append(this->alternatives[j] + "¬:¬");
        }
        answer.append(QString::number(this->correctChoice));
        QString command;
        QSqlQuery query(*db);
        command = "INSERT INTO questions (enunciado, tipo, resposta, flag_assunto, titulo, dificuldade) VALUES ('"+this->questionDescription+"', '"+ QString::number(this->type) +"', '"+answer+"', '"+QString::number(1)+"', '"+this->title+"', '"+QString::number(this->difficulty)+"')";
        if(query.exec(command)){
            return true;
        }
        else{
            return false;
        }
    }
}

void professorMultipleChoiceQuestion::setAlternatives(QList<QString> _alternatives){
    this->alternatives = _alternatives;
}
QList<QString> professorMultipleChoiceQuestion::getAlternatives(){
    return this->alternatives;
}
void professorMultipleChoiceQuestion::setCorrectChoice(int _correctChoice){
    this->correctChoice = _correctChoice;
}
int professorMultipleChoiceQuestion::getCorrectChoice(){
    return this->correctChoice;
}
//professorDiscursiveQuestion functions
QDomElement professorDiscursiveQuestion::toXml(){
    QDomDocument exam;
    QDomElement question = exam.createElement("Question");
    question.setAttribute("QuestionDescription", this->questionDescription);
    question.setAttribute("Difficulty", this->difficulty);
    question.setAttribute("Type", this->type);
    question.setAttribute("CorrectAnswer", this->correctAnswer);
    return question;
}

void professorDiscursiveQuestion::setAnswer(Ui::MainWindow *ui){
    ui->cbb_type->setCurrentIndex(2);
    ui->txe_discursiveAnswer->setText(this->correctAnswer);
}

void professorDiscursiveQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stw_dbQuestions->setCurrentIndex(2);
    ui->txe_dbQuestionDescription->setText(this->questionDescription);
    ui->txe_dbDiscursiveAnswer->setText(this->correctAnswer);
}

void professorDiscursiveQuestion::setCorrectAnswer(QString _correctAnswer){
    this->correctAnswer = _correctAnswer;
}
QString professorDiscursiveQuestion::getCorrectAnswer(){
    return this->correctAnswer;
}

bool professorDiscursiveQuestion::doSaveInDb(QSqlDatabase *db){
    if(this->correctAnswer == ""){
        return false;
    }
    else{
        QString command;
        QSqlQuery query(*db);
        command = "INSERT INTO questions (enunciado, tipo, resposta, flag_assunto, titulo, dificuldade) VALUES ('"+this->questionDescription+"', '"+ QString::number(this->type) +"', '"+this->correctAnswer+"', '"+QString::number(1)+"', '"+this->title+"', '"+QString::number(this->difficulty)+"')";
        if(query.exec(command)){
            return true;
        }
        else{
            return false;
        }
    }
}

//studentDiscursiveQuestion functions
void studentDiscursiveQuestion::setStudentAnswer(QString _studentAnswer){
    this->studentAnswer = _studentAnswer;
}
QString studentDiscursiveQuestion::getStudentAnswer(){
    return this->studentAnswer;
}

//studentProgrammingQuestion functions
void studentProgrammingQuestion::setCompilerOutput(QString _compilerOutput){
    this->compilerOutput = _compilerOutput;
}
QString studentProgrammingQuestion::getCompilerOutput(){
    return this->compilerOutput;
}
void studentProgrammingQuestion::setStudentAnswer(QString _studentAnswer){
    this->studentAnswer = _studentAnswer;
}
QString studentProgrammingQuestion::getStudentAnswer(){
    return this->studentAnswer;
}
void studentProgrammingQuestion::setCompilationAmount(int _compilationAmount){
    this->compilationAmount = _compilationAmount;
}
int studentProgrammingQuestion::getCompilationAmount(){
    return this->compilationAmount;
}

//studentMultipleChoiceQuestion functions
void studentMultipleChoiceQuestion::setStudentAnswer(QString _studentAnswer){
    this->studentAnswer = _studentAnswer.toInt();
}
QString studentMultipleChoiceQuestion::getStudentAnswer(){
    return QString::number(this->studentAnswer);
}
QList<QString> studentMultipleChoiceQuestion::getAlternatives(){
    return this->alternatives;
}
