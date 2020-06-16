#include "question.h"
//CONSTRUCTORS
//super class
question::question(int type, QString questionDescription){
    this->type = type;
    this->questionDescription = questionDescription;
}
//professor classes
professorQuestion::professorQuestion(int type, QString questionDescription, QString title, int difficulty) : question (type, questionDescription){
    this->title = title;
    this->difficulty = difficulty;
}

professorProgrammingQuestion::professorProgrammingQuestion(int type, QString questionDescription, QString title, int difficulty, int compilationAmount, QList<QString> input, QList<QString> output) : professorQuestion(type,questionDescription,title,difficulty){
    this->compilationAmount = compilationAmount;
    this->input = input;
    this->output = output;
}

professorMultipleChoiceQuestion::professorMultipleChoiceQuestion(int type, QString questionDescription, QString title, int difficulty, QList<QString> alternatives, int correctChoice) : professorQuestion(type,questionDescription,title,difficulty){
    this->alternatives = alternatives;
    this->correctChoice = correctChoice;
}

professorDiscursiveQuestion::professorDiscursiveQuestion(int type, QString questionDescription, QString title, int difficulty, QString correctAnswer) : professorQuestion(type,questionDescription,title,difficulty){
    this->correctAnswer = correctAnswer;
}
//student classes
studentDiscursiveQuestion::studentDiscursiveQuestion(int type, QString questionDescription) : question (type, questionDescription){

}

studentProgrammingQuestion::studentProgrammingQuestion(int type, QString questionDescription, int compilationAmount) : question (type, questionDescription){
    this->compilationAmount = compilationAmount;
}

studentMultipleChoiceQuestion::studentMultipleChoiceQuestion(int type, QString questionDescription, QList<QString> alternatives) : question (type, questionDescription){
    this->alternatives = alternatives;
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
void professorQuestion::setTitle(QString title){
    this->title = title;
}
QString professorQuestion::getTitle(){
    return this->title;
}
void professorQuestion::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}
int professorQuestion::getDifficulty(){
    return this->difficulty;
}

//professorProgrammingQuestion functions
QString professorProgrammingQuestion::toXml(){
    QString aux = "";
    for(int i = 0; i < this->input.size(); i++){
        aux = this->input[i] + "¬:¬" + this->output[i];
    }
    return aux;
}

void professorProgrammingQuestion::setAnswer(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(0);
    ui->s_numcomp->setValue(this->getCompilationAmount());
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* item = new QListWidgetItem(in);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->l_input->addItem(item);
    }
    foreach(out,this->output){
        QListWidgetItem* item = new QListWidgetItem(out);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->l_output->addItem(item);
    }
}

void professorProgrammingQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(0);
    ui->bd_l_input->clear();
    ui->bd_l_output->clear();
    ui->enunciado_questao->setText(this->questionDescription);
    ui->bd_numcomp->setText(QString::number(this->compilationAmount));
    QString in;
    QString out;
    foreach(in,this->input){
        QListWidgetItem* item = new QListWidgetItem(in);
        ui->bd_l_input->addItem(item);
    }
    foreach(out,this->output){
        QListWidgetItem* item = new QListWidgetItem(out);
        ui->bd_l_output->addItem(item);
    }
}

void professorProgrammingQuestion::setInput(QList<QString> input){
    this->input = input;
}
QList<QString> professorProgrammingQuestion::getInput(){
    return this->input;
}
void professorProgrammingQuestion::setOutput(QList<QString> output){
    this->output = output;
}
QList<QString> professorProgrammingQuestion::getOutput(){
    return this->output;
}
void professorProgrammingQuestion::setCompilationAmount(int compilationAmount){
    this->compilationAmount = compilationAmount;
}
int professorProgrammingQuestion::getCompilationAmount(){
    return this->compilationAmount;
}

//professorMultipleChoiceQuestion functions
QString professorMultipleChoiceQuestion::toXml(){
    return QString::number(this->correctChoice);
}

void professorMultipleChoiceQuestion::setAnswer(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(1);
    QString alt;
    foreach(alt,this->alternatives){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->t_resposta_mult->addItem(item);
    }
    if(this->correctChoice != -1){
        ui->t_resposta_mult->item(this->correctChoice)->setCheckState(Qt::Checked);
    }
}

void professorMultipleChoiceQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(1);
    ui->bd_respmult->clear();
    ui->enunciado_questao->setText(this->questionDescription);
    QString alt;
    foreach(alt,this->alternatives){
        QListWidgetItem* item = new QListWidgetItem(alt);
        item->setCheckState(Qt::Unchecked);
        ui->bd_respmult->addItem(item);
    }
    if(this->correctChoice != -1){
        ui->bd_respmult->item(this->correctChoice)->setCheckState(Qt::Checked);
    }
}

void professorMultipleChoiceQuestion::setAlternatives(QList<QString> alternatives){
    this->alternatives = alternatives;
}
QList<QString> professorMultipleChoiceQuestion::getAlternatives(){
    return this->alternatives;
}
void professorMultipleChoiceQuestion::setCorrectChoice(int correctChoice){
    this->correctChoice = correctChoice;
}
int professorMultipleChoiceQuestion::getCorrectChoice(){
    return this->correctChoice;
}
//professorDiscursiveQuestion functions
QString professorDiscursiveQuestion::toXml(){
    return this->correctAnswer;
}

void professorDiscursiveQuestion::setAnswer(Ui::MainWindow *ui){
    ui->c_tipo->setCurrentIndex(2);
    ui->t_resposta_discursiva->setText(this->correctAnswer);
}

void professorDiscursiveQuestion::setDatabase(Ui::MainWindow *ui){
    ui->stacked_bd->setCurrentIndex(2);
    ui->enunciado_questao->setText(this->questionDescription);
    ui->bd_respdiscursiva->setText(this->correctAnswer);
}

void professorDiscursiveQuestion::setCorrectAnswer(QString correctAnswer){
    this->correctAnswer = correctAnswer;
}
QString professorDiscursiveQuestion::getCorrectAnswer(){
    return this->correctAnswer;
}

//studentDiscursiveQuestion functions
void studentDiscursiveQuestion::setStudentAnswer(QString studentAnswer){
    this->studentAnswer = studentAnswer;
}
QString studentDiscursiveQuestion::getStudentAnswer(){
    return this->studentAnswer;
}

//studentProgrammingQuestion functions
void studentProgrammingQuestion::setCompilerOutput(QString compilerOutput){
    this->compilerOutput = compilerOutput;
}
QString studentProgrammingQuestion::getCompilerOutput(){
    return this->compilerOutput;
}
void studentProgrammingQuestion::setStudentAnswer(QString studentAnswer){
    this->studentAnswer = studentAnswer;
}
QString studentProgrammingQuestion::getStudentAnswer(){
    return this->studentAnswer;
}
void studentProgrammingQuestion::setCompilationAmount(int compilationAmount){
    this->compilationAmount = compilationAmount;
}
int studentProgrammingQuestion::getCompilationAmount(){
    return this->compilationAmount;
}

//studentMultipleChoiceQuestion functions
void studentMultipleChoiceQuestion::setStudentChoice(int studentChoice){
    this->studentChoice = studentChoice;
}
int studentMultipleChoiceQuestion::getStudentChoice(){
    return this->studentChoice;
}
QList<QString> studentMultipleChoiceQuestion::getAlternatives(){
    return this->alternatives;
}
