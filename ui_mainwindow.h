/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *wgt_centralWidget;
    QGridLayout *gridLayout_11;
    QStackedWidget *stw_mainInterface;
    QWidget *wgt_login;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QGroupBox *gbx_login;
    QVBoxLayout *verticalLayout;
    QLineEdit *lne_loginUser;
    QLineEdit *lne_loginPassword;
    QCheckBox *ckb_checkUser;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbl_status;
    QWidget *wgt_student;
    QGridLayout *gridLayout_2;
    QTabWidget *tbw_student;
    QWidget *wgt_studentProfile;
    QPushButton *btn_studentLogout;
    QWidget *wgt_exam;
    QStackedWidget *stw_doExam;
    QWidget *wgt_enterRoom;
    QPushButton *btn_enterRoom;
    QLabel *lbl_roomDoor;
    QLabel *lbl_roomHostName;
    QLineEdit *txt_roomHostName;
    QSpinBox *spb_roomDoor;
    QWidget *wgt_waitingExam;
    QPushButton *btn_startExam;
    QLabel *lbl_doExamMessage;
    QWidget *wgt_professor;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tbw_professor;
    QWidget *wgt_professorProfile;
    QGroupBox *gbx_professorProfile;
    QVBoxLayout *verticalLayout_6;
    QLabel *lbl_professorImage;
    QLabel *lbl_professorName;
    QPushButton *btn_professorLogout;
    QWidget *wgt_editExam;
    QGridLayout *gridLayout_4;
    QGroupBox *gbx_answer;
    QVBoxLayout *verticalLayout_11;
    QStackedWidget *stw_answers;
    QWidget *wgt_setProgrammingAnswer;
    QGridLayout *gridLayout_5;
    QSpinBox *spb_compilationAmount;
    QLabel *lbl_compilationAmount;
    QPushButton *btn_addTest;
    QListWidget *ltw_compilationInput;
    QListWidget *ltw_compilationOutput;
    QPushButton *btn_removeTest;
    QLabel *lbl_compilationInput;
    QLabel *lbl_compilationOutput;
    QWidget *wgt_multipleChoiceAnswer;
    QVBoxLayout *verticalLayout_9;
    QListWidget *ltw_multipleChoiceAlternatives;
    QPushButton *btn_addAlternative;
    QPushButton *btn_removeAlternative;
    QWidget *wgt_discursiveAnswer;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *txe_discursiveAnswer;
    QGroupBox *gbx_setQuestionDescription;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *txe_setQuestionDescription;
    QGroupBox *gbx_createExam;
    QGridLayout *gridLayout_3;
    QPushButton *btn_addToDb;
    QPushButton *btn_searchOnDb;
    QPushButton *btn_createExam;
    QGroupBox *gbx_setExamQuestionsList;
    QVBoxLayout *verticalLayout_2;
    QListWidget *ltw_setExamQuestionsList;
    QPushButton *btn_removeQuestion;
    QPushButton *btn_addQuestion;
    QComboBox *cbb_difficulty;
    QComboBox *cbb_type;
    QGroupBox *gbx_setQuestionTitle;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *txe_setTitle;
    QWidget *wgt_applyExam;
    QStackedWidget *stw_applyExam;
    QWidget *wgt_createRoom;
    QLabel *lbl_setRoomDoor;
    QSpinBox *spb_setRoomDoor;
    QPushButton *btn_createRoom;
    QWidget *wgt_room;
    QPushButton *btn_setExamStarted;
    QPushButton *btn_setExamFinished;
    QPushButton *btn_closeRoom;
    QLabel *lbl_roomLobby;
    QListWidget *ltw_rooomLobby;
    QLabel *lbl_setExamFileDirectory;
    QLineEdit *lne_examFileDirectory;
    QPushButton *btn_loadExamFile;
    QWidget *wgt_studentExam;
    QGridLayout *gridLayout_12;
    QStackedWidget *stw_studentAnswers;
    QWidget *wgt_studentProgrammingAnswer;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *gbx_studentProgrammingAnswer;
    QGridLayout *gridLayout_6;
    QTextEdit *txe_studentProgrammingAnswer;
    QGroupBox *gbx_compilerOutput;
    QVBoxLayout *verticalLayout_12;
    QTextEdit *txe_compilerOutput;
    QWidget *wgt_alternatives;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *gbx_alternatives;
    QWidget *wgt_studentDiscursiveAnswer;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *gbx_studentDiscursiveAnswer;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *ptx_studentDiscursiveAnswer;
    QGroupBox *gbx_examQuestionsList;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gbx_commands;
    QGridLayout *gridLayout_8;
    QPushButton *btn_compile;
    QPushButton *btn_run;
    QListWidget *ltw_examQuestionsList;
    QPushButton *btn_finishExam;
    QGroupBox *gbx_questionDescription;
    QGridLayout *gridLayout_7;
    QTextEdit *txe_questionDescription;
    QWidget *p_busca_bd;
    QGridLayout *gridLayout_10;
    QStackedWidget *stacked_bd;
    QWidget *bd_programacao;
    QGridLayout *gridLayout_13;
    QLabel *bd_input;
    QLabel *bd_output;
    QLabel *label_bd_numcomp;
    QLineEdit *bd_numcomp;
    QListWidget *bd_ltw_compilationInput;
    QListWidget *bd_l_output;
    QWidget *bd_mult;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *bd_respmult;
    QWidget *bd_discursiva;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *bd_respdiscursiva;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QComboBox *materia;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QComboBox *assunto;
    QListWidget *list_questoes;
    QPushButton *voltar;
    QPushButton *adicionar_question;
    QTextEdit *enunciado_questao;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        wgt_centralWidget = new QWidget(MainWindow);
        wgt_centralWidget->setObjectName(QString::fromUtf8("wgt_centralWidget"));
        gridLayout_11 = new QGridLayout(wgt_centralWidget);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        stw_mainInterface = new QStackedWidget(wgt_centralWidget);
        stw_mainInterface->setObjectName(QString::fromUtf8("stw_mainInterface"));
        wgt_login = new QWidget();
        wgt_login->setObjectName(QString::fromUtf8("wgt_login"));
        gridLayout = new QGridLayout(wgt_login);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        gbx_login = new QGroupBox(wgt_login);
        gbx_login->setObjectName(QString::fromUtf8("gbx_login"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbx_login->sizePolicy().hasHeightForWidth());
        gbx_login->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(gbx_login);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lne_loginUser = new QLineEdit(gbx_login);
        lne_loginUser->setObjectName(QString::fromUtf8("lne_loginUser"));

        verticalLayout->addWidget(lne_loginUser);

        lne_loginPassword = new QLineEdit(gbx_login);
        lne_loginPassword->setObjectName(QString::fromUtf8("lne_loginPassword"));
        lne_loginPassword->setEnabled(false);
        lne_loginPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lne_loginPassword);

        ckb_checkUser = new QCheckBox(gbx_login);
        ckb_checkUser->setObjectName(QString::fromUtf8("ckb_checkUser"));

        verticalLayout->addWidget(ckb_checkUser);

        btn_login = new QPushButton(gbx_login);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(btn_login);


        gridLayout->addWidget(gbx_login, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        lbl_status = new QLabel(wgt_login);
        lbl_status->setObjectName(QString::fromUtf8("lbl_status"));
        lbl_status->setEnabled(true);
        QFont font;
        font.setPointSize(12);
        lbl_status->setFont(font);
        lbl_status->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl_status, 0, 2, 1, 1);

        stw_mainInterface->addWidget(wgt_login);
        wgt_student = new QWidget();
        wgt_student->setObjectName(QString::fromUtf8("wgt_student"));
        gridLayout_2 = new QGridLayout(wgt_student);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tbw_student = new QTabWidget(wgt_student);
        tbw_student->setObjectName(QString::fromUtf8("tbw_student"));
        wgt_studentProfile = new QWidget();
        wgt_studentProfile->setObjectName(QString::fromUtf8("wgt_studentProfile"));
        btn_studentLogout = new QPushButton(wgt_studentProfile);
        btn_studentLogout->setObjectName(QString::fromUtf8("btn_studentLogout"));
        btn_studentLogout->setGeometry(QRect(150, 200, 80, 21));
        tbw_student->addTab(wgt_studentProfile, QString());
        wgt_exam = new QWidget();
        wgt_exam->setObjectName(QString::fromUtf8("wgt_exam"));
        stw_doExam = new QStackedWidget(wgt_exam);
        stw_doExam->setObjectName(QString::fromUtf8("stw_doExam"));
        stw_doExam->setGeometry(QRect(9, 9, 741, 491));
        wgt_enterRoom = new QWidget();
        wgt_enterRoom->setObjectName(QString::fromUtf8("wgt_enterRoom"));
        btn_enterRoom = new QPushButton(wgt_enterRoom);
        btn_enterRoom->setObjectName(QString::fromUtf8("btn_enterRoom"));
        btn_enterRoom->setGeometry(QRect(240, 100, 131, 31));
        lbl_roomDoor = new QLabel(wgt_enterRoom);
        lbl_roomDoor->setObjectName(QString::fromUtf8("lbl_roomDoor"));
        lbl_roomDoor->setGeometry(QRect(10, 60, 221, 21));
        lbl_roomHostName = new QLabel(wgt_enterRoom);
        lbl_roomHostName->setObjectName(QString::fromUtf8("lbl_roomHostName"));
        lbl_roomHostName->setGeometry(QRect(10, 35, 211, 21));
        txt_roomHostName = new QLineEdit(wgt_enterRoom);
        txt_roomHostName->setObjectName(QString::fromUtf8("txt_roomHostName"));
        txt_roomHostName->setGeometry(QRect(240, 30, 201, 21));
        spb_roomDoor = new QSpinBox(wgt_enterRoom);
        spb_roomDoor->setObjectName(QString::fromUtf8("spb_roomDoor"));
        spb_roomDoor->setGeometry(QRect(240, 60, 91, 22));
        spb_roomDoor->setMaximum(999999);
        stw_doExam->addWidget(wgt_enterRoom);
        wgt_waitingExam = new QWidget();
        wgt_waitingExam->setObjectName(QString::fromUtf8("wgt_waitingExam"));
        btn_startExam = new QPushButton(wgt_waitingExam);
        btn_startExam->setObjectName(QString::fromUtf8("btn_startExam"));
        btn_startExam->setEnabled(false);
        btn_startExam->setGeometry(QRect(20, 60, 161, 31));
        lbl_doExamMessage = new QLabel(wgt_waitingExam);
        lbl_doExamMessage->setObjectName(QString::fromUtf8("lbl_doExamMessage"));
        lbl_doExamMessage->setGeometry(QRect(10, 10, 221, 21));
        stw_doExam->addWidget(wgt_waitingExam);
        tbw_student->addTab(wgt_exam, QString());

        gridLayout_2->addWidget(tbw_student, 0, 0, 1, 1);

        stw_mainInterface->addWidget(wgt_student);
        wgt_professor = new QWidget();
        wgt_professor->setObjectName(QString::fromUtf8("wgt_professor"));
        horizontalLayout = new QHBoxLayout(wgt_professor);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tbw_professor = new QTabWidget(wgt_professor);
        tbw_professor->setObjectName(QString::fromUtf8("tbw_professor"));
        tbw_professor->setTabShape(QTabWidget::Rounded);
        wgt_professorProfile = new QWidget();
        wgt_professorProfile->setObjectName(QString::fromUtf8("wgt_professorProfile"));
        gbx_professorProfile = new QGroupBox(wgt_professorProfile);
        gbx_professorProfile->setObjectName(QString::fromUtf8("gbx_professorProfile"));
        gbx_professorProfile->setGeometry(QRect(10, 10, 151, 221));
        verticalLayout_6 = new QVBoxLayout(gbx_professorProfile);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lbl_professorImage = new QLabel(gbx_professorProfile);
        lbl_professorImage->setObjectName(QString::fromUtf8("lbl_professorImage"));
        sizePolicy1.setHeightForWidth(lbl_professorImage->sizePolicy().hasHeightForWidth());
        lbl_professorImage->setSizePolicy(sizePolicy1);
        lbl_professorImage->setMinimumSize(QSize(128, 128));
        lbl_professorImage->setLayoutDirection(Qt::LeftToRight);
        lbl_professorImage->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image: url(:/images/foto_login.png);\n"
"}"));
        lbl_professorImage->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lbl_professorImage);

        lbl_professorName = new QLabel(gbx_professorProfile);
        lbl_professorName->setObjectName(QString::fromUtf8("lbl_professorName"));
        lbl_professorName->setAlignment(Qt::AlignCenter);
        lbl_professorName->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_6->addWidget(lbl_professorName);

        btn_professorLogout = new QPushButton(gbx_professorProfile);
        btn_professorLogout->setObjectName(QString::fromUtf8("btn_professorLogout"));

        verticalLayout_6->addWidget(btn_professorLogout);

        tbw_professor->addTab(wgt_professorProfile, QString());
        wgt_editExam = new QWidget();
        wgt_editExam->setObjectName(QString::fromUtf8("wgt_editExam"));
        gridLayout_4 = new QGridLayout(wgt_editExam);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gbx_answer = new QGroupBox(wgt_editExam);
        gbx_answer->setObjectName(QString::fromUtf8("gbx_answer"));
        gbx_answer->setEnabled(true);
        sizePolicy.setHeightForWidth(gbx_answer->sizePolicy().hasHeightForWidth());
        gbx_answer->setSizePolicy(sizePolicy);
        verticalLayout_11 = new QVBoxLayout(gbx_answer);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        stw_answers = new QStackedWidget(gbx_answer);
        stw_answers->setObjectName(QString::fromUtf8("stw_answers"));
        stw_answers->setEnabled(true);
        wgt_setProgrammingAnswer = new QWidget();
        wgt_setProgrammingAnswer->setObjectName(QString::fromUtf8("wgt_setProgrammingAnswer"));
        gridLayout_5 = new QGridLayout(wgt_setProgrammingAnswer);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        spb_compilationAmount = new QSpinBox(wgt_setProgrammingAnswer);
        spb_compilationAmount->setObjectName(QString::fromUtf8("spb_compilationAmount"));
        spb_compilationAmount->setMinimumSize(QSize(0, 0));

        gridLayout_5->addWidget(spb_compilationAmount, 0, 1, 1, 1);

        lbl_compilationAmount = new QLabel(wgt_setProgrammingAnswer);
        lbl_compilationAmount->setObjectName(QString::fromUtf8("lbl_compilationAmount"));
        lbl_compilationAmount->setMaximumSize(QSize(130, 16777215));
        lbl_compilationAmount->setLayoutDirection(Qt::LeftToRight);
        lbl_compilationAmount->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lbl_compilationAmount, 0, 0, 1, 1, Qt::AlignHCenter);

        btn_addTest = new QPushButton(wgt_setProgrammingAnswer);
        btn_addTest->setObjectName(QString::fromUtf8("btn_addTest"));

        gridLayout_5->addWidget(btn_addTest, 3, 0, 1, 2);

        ltw_compilationInput = new QListWidget(wgt_setProgrammingAnswer);
        ltw_compilationInput->setObjectName(QString::fromUtf8("ltw_compilationInput"));

        gridLayout_5->addWidget(ltw_compilationInput, 2, 0, 1, 1);

        ltw_compilationOutput = new QListWidget(wgt_setProgrammingAnswer);
        ltw_compilationOutput->setObjectName(QString::fromUtf8("ltw_compilationOutput"));

        gridLayout_5->addWidget(ltw_compilationOutput, 2, 1, 1, 1);

        btn_removeTest = new QPushButton(wgt_setProgrammingAnswer);
        btn_removeTest->setObjectName(QString::fromUtf8("btn_removeTest"));

        gridLayout_5->addWidget(btn_removeTest, 4, 0, 1, 2);

        lbl_compilationInput = new QLabel(wgt_setProgrammingAnswer);
        lbl_compilationInput->setObjectName(QString::fromUtf8("lbl_compilationInput"));

        gridLayout_5->addWidget(lbl_compilationInput, 1, 0, 1, 1, Qt::AlignHCenter);

        lbl_compilationOutput = new QLabel(wgt_setProgrammingAnswer);
        lbl_compilationOutput->setObjectName(QString::fromUtf8("lbl_compilationOutput"));

        gridLayout_5->addWidget(lbl_compilationOutput, 1, 1, 1, 1, Qt::AlignHCenter);

        stw_answers->addWidget(wgt_setProgrammingAnswer);
        wgt_multipleChoiceAnswer = new QWidget();
        wgt_multipleChoiceAnswer->setObjectName(QString::fromUtf8("wgt_multipleChoiceAnswer"));
        verticalLayout_9 = new QVBoxLayout(wgt_multipleChoiceAnswer);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        ltw_multipleChoiceAlternatives = new QListWidget(wgt_multipleChoiceAnswer);
        ltw_multipleChoiceAlternatives->setObjectName(QString::fromUtf8("ltw_multipleChoiceAlternatives"));
        ltw_multipleChoiceAlternatives->setAlternatingRowColors(true);
        ltw_multipleChoiceAlternatives->setViewMode(QListView::ListMode);
        ltw_multipleChoiceAlternatives->setSelectionRectVisible(false);

        verticalLayout_9->addWidget(ltw_multipleChoiceAlternatives);

        btn_addAlternative = new QPushButton(wgt_multipleChoiceAnswer);
        btn_addAlternative->setObjectName(QString::fromUtf8("btn_addAlternative"));

        verticalLayout_9->addWidget(btn_addAlternative);

        btn_removeAlternative = new QPushButton(wgt_multipleChoiceAnswer);
        btn_removeAlternative->setObjectName(QString::fromUtf8("btn_removeAlternative"));

        verticalLayout_9->addWidget(btn_removeAlternative);

        stw_answers->addWidget(wgt_multipleChoiceAnswer);
        wgt_discursiveAnswer = new QWidget();
        wgt_discursiveAnswer->setObjectName(QString::fromUtf8("wgt_discursiveAnswer"));
        verticalLayout_10 = new QVBoxLayout(wgt_discursiveAnswer);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        txe_discursiveAnswer = new QTextEdit(wgt_discursiveAnswer);
        txe_discursiveAnswer->setObjectName(QString::fromUtf8("txe_discursiveAnswer"));
        txe_discursiveAnswer->setReadOnly(false);

        verticalLayout_10->addWidget(txe_discursiveAnswer);

        stw_answers->addWidget(wgt_discursiveAnswer);

        verticalLayout_11->addWidget(stw_answers);


        gridLayout_4->addWidget(gbx_answer, 9, 1, 1, 2);

        gbx_setQuestionDescription = new QGroupBox(wgt_editExam);
        gbx_setQuestionDescription->setObjectName(QString::fromUtf8("gbx_setQuestionDescription"));
        verticalLayout_4 = new QVBoxLayout(gbx_setQuestionDescription);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        txe_setQuestionDescription = new QTextEdit(gbx_setQuestionDescription);
        txe_setQuestionDescription->setObjectName(QString::fromUtf8("txe_setQuestionDescription"));
        txe_setQuestionDescription->setReadOnly(true);

        verticalLayout_4->addWidget(txe_setQuestionDescription);


        gridLayout_4->addWidget(gbx_setQuestionDescription, 5, 1, 1, 2);

        gbx_createExam = new QGroupBox(wgt_editExam);
        gbx_createExam->setObjectName(QString::fromUtf8("gbx_createExam"));
        gbx_createExam->setMaximumSize(QSize(400, 16777215));
        gridLayout_3 = new QGridLayout(gbx_createExam);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btn_addToDb = new QPushButton(gbx_createExam);
        btn_addToDb->setObjectName(QString::fromUtf8("btn_addToDb"));

        gridLayout_3->addWidget(btn_addToDb, 1, 1, 1, 2);

        btn_searchOnDb = new QPushButton(gbx_createExam);
        btn_searchOnDb->setObjectName(QString::fromUtf8("btn_searchOnDb"));
        btn_searchOnDb->setAcceptDrops(false);
        btn_searchOnDb->setLayoutDirection(Qt::LeftToRight);
        btn_searchOnDb->setCheckable(false);
        btn_searchOnDb->setFlat(false);

        gridLayout_3->addWidget(btn_searchOnDb, 2, 1, 1, 2);

        btn_createExam = new QPushButton(gbx_createExam);
        btn_createExam->setObjectName(QString::fromUtf8("btn_createExam"));

        gridLayout_3->addWidget(btn_createExam, 3, 1, 1, 2);

        gbx_setExamQuestionsList = new QGroupBox(gbx_createExam);
        gbx_setExamQuestionsList->setObjectName(QString::fromUtf8("gbx_setExamQuestionsList"));
        verticalLayout_2 = new QVBoxLayout(gbx_setExamQuestionsList);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ltw_setExamQuestionsList = new QListWidget(gbx_setExamQuestionsList);
        ltw_setExamQuestionsList->setObjectName(QString::fromUtf8("ltw_setExamQuestionsList"));
        ltw_setExamQuestionsList->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(ltw_setExamQuestionsList);

        btn_removeQuestion = new QPushButton(gbx_setExamQuestionsList);
        btn_removeQuestion->setObjectName(QString::fromUtf8("btn_removeQuestion"));

        verticalLayout_2->addWidget(btn_removeQuestion);

        btn_addQuestion = new QPushButton(gbx_setExamQuestionsList);
        btn_addQuestion->setObjectName(QString::fromUtf8("btn_addQuestion"));

        verticalLayout_2->addWidget(btn_addQuestion);


        gridLayout_3->addWidget(gbx_setExamQuestionsList, 0, 1, 1, 2);


        gridLayout_4->addWidget(gbx_createExam, 0, 0, 10, 1);

        cbb_difficulty = new QComboBox(wgt_editExam);
        cbb_difficulty->addItem(QString());
        cbb_difficulty->addItem(QString());
        cbb_difficulty->addItem(QString());
        cbb_difficulty->setObjectName(QString::fromUtf8("cbb_difficulty"));
        cbb_difficulty->setEnabled(false);

        gridLayout_4->addWidget(cbb_difficulty, 0, 2, 1, 1);

        cbb_type = new QComboBox(wgt_editExam);
        cbb_type->addItem(QString());
        cbb_type->addItem(QString());
        cbb_type->addItem(QString());
        cbb_type->setObjectName(QString::fromUtf8("cbb_type"));
        cbb_type->setEnabled(false);

        gridLayout_4->addWidget(cbb_type, 0, 1, 1, 1);

        gbx_setQuestionTitle = new QGroupBox(wgt_editExam);
        gbx_setQuestionTitle->setObjectName(QString::fromUtf8("gbx_setQuestionTitle"));
        gbx_setQuestionTitle->setMaximumSize(QSize(16777215, 80));
        verticalLayout_5 = new QVBoxLayout(gbx_setQuestionTitle);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        txe_setTitle = new QTextEdit(gbx_setQuestionTitle);
        txe_setTitle->setObjectName(QString::fromUtf8("txe_setTitle"));
        txe_setTitle->setReadOnly(true);

        verticalLayout_5->addWidget(txe_setTitle);


        gridLayout_4->addWidget(gbx_setQuestionTitle, 4, 1, 1, 2);

        tbw_professor->addTab(wgt_editExam, QString());
        gbx_setQuestionDescription->raise();
        gbx_answer->raise();
        gbx_createExam->raise();
        cbb_type->raise();
        gbx_setQuestionTitle->raise();
        cbb_difficulty->raise();
        wgt_applyExam = new QWidget();
        wgt_applyExam->setObjectName(QString::fromUtf8("wgt_applyExam"));
        stw_applyExam = new QStackedWidget(wgt_applyExam);
        stw_applyExam->setObjectName(QString::fromUtf8("stw_applyExam"));
        stw_applyExam->setGeometry(QRect(9, 9, 741, 501));
        wgt_createRoom = new QWidget();
        wgt_createRoom->setObjectName(QString::fromUtf8("wgt_createRoom"));
        lbl_setRoomDoor = new QLabel(wgt_createRoom);
        lbl_setRoomDoor->setObjectName(QString::fromUtf8("lbl_setRoomDoor"));
        lbl_setRoomDoor->setGeometry(QRect(10, 30, 131, 21));
        spb_setRoomDoor = new QSpinBox(wgt_createRoom);
        spb_setRoomDoor->setObjectName(QString::fromUtf8("spb_setRoomDoor"));
        spb_setRoomDoor->setGeometry(QRect(150, 20, 81, 31));
        spb_setRoomDoor->setMaximum(999999);
        btn_createRoom = new QPushButton(wgt_createRoom);
        btn_createRoom->setObjectName(QString::fromUtf8("btn_createRoom"));
        btn_createRoom->setGeometry(QRect(240, 20, 111, 31));
        stw_applyExam->addWidget(wgt_createRoom);
        wgt_room = new QWidget();
        wgt_room->setObjectName(QString::fromUtf8("wgt_room"));
        btn_setExamStarted = new QPushButton(wgt_room);
        btn_setExamStarted->setObjectName(QString::fromUtf8("btn_setExamStarted"));
        btn_setExamStarted->setEnabled(false);
        btn_setExamStarted->setGeometry(QRect(410, 90, 111, 31));
        btn_setExamFinished = new QPushButton(wgt_room);
        btn_setExamFinished->setObjectName(QString::fromUtf8("btn_setExamFinished"));
        btn_setExamFinished->setEnabled(false);
        btn_setExamFinished->setGeometry(QRect(620, 90, 111, 31));
        btn_closeRoom = new QPushButton(wgt_room);
        btn_closeRoom->setObjectName(QString::fromUtf8("btn_closeRoom"));
        btn_closeRoom->setGeometry(QRect(620, 461, 111, 31));
        lbl_roomLobby = new QLabel(wgt_room);
        lbl_roomLobby->setObjectName(QString::fromUtf8("lbl_roomLobby"));
        lbl_roomLobby->setGeometry(QRect(10, 10, 91, 31));
        ltw_rooomLobby = new QListWidget(wgt_room);
        ltw_rooomLobby->setObjectName(QString::fromUtf8("ltw_rooomLobby"));
        ltw_rooomLobby->setGeometry(QRect(10, 50, 381, 441));
        lbl_setExamFileDirectory = new QLabel(wgt_room);
        lbl_setExamFileDirectory->setObjectName(QString::fromUtf8("lbl_setExamFileDirectory"));
        lbl_setExamFileDirectory->setGeometry(QRect(410, 10, 151, 21));
        lne_examFileDirectory = new QLineEdit(wgt_room);
        lne_examFileDirectory->setObjectName(QString::fromUtf8("lne_examFileDirectory"));
        lne_examFileDirectory->setGeometry(QRect(410, 50, 281, 31));
        btn_loadExamFile = new QPushButton(wgt_room);
        btn_loadExamFile->setObjectName(QString::fromUtf8("btn_loadExamFile"));
        btn_loadExamFile->setGeometry(QRect(699, 50, 31, 31));
        stw_applyExam->addWidget(wgt_room);
        tbw_professor->addTab(wgt_applyExam, QString());

        horizontalLayout->addWidget(tbw_professor);

        stw_mainInterface->addWidget(wgt_professor);
        wgt_studentExam = new QWidget();
        wgt_studentExam->setObjectName(QString::fromUtf8("wgt_studentExam"));
        gridLayout_12 = new QGridLayout(wgt_studentExam);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        stw_studentAnswers = new QStackedWidget(wgt_studentExam);
        stw_studentAnswers->setObjectName(QString::fromUtf8("stw_studentAnswers"));
        wgt_studentProgrammingAnswer = new QWidget();
        wgt_studentProgrammingAnswer->setObjectName(QString::fromUtf8("wgt_studentProgrammingAnswer"));
        verticalLayout_8 = new QVBoxLayout(wgt_studentProgrammingAnswer);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        gbx_studentProgrammingAnswer = new QGroupBox(wgt_studentProgrammingAnswer);
        gbx_studentProgrammingAnswer->setObjectName(QString::fromUtf8("gbx_studentProgrammingAnswer"));
        gridLayout_6 = new QGridLayout(gbx_studentProgrammingAnswer);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        txe_studentProgrammingAnswer = new QTextEdit(gbx_studentProgrammingAnswer);
        txe_studentProgrammingAnswer->setObjectName(QString::fromUtf8("txe_studentProgrammingAnswer"));

        gridLayout_6->addWidget(txe_studentProgrammingAnswer, 0, 0, 1, 1);


        verticalLayout_8->addWidget(gbx_studentProgrammingAnswer);

        gbx_compilerOutput = new QGroupBox(wgt_studentProgrammingAnswer);
        gbx_compilerOutput->setObjectName(QString::fromUtf8("gbx_compilerOutput"));
        gbx_compilerOutput->setMaximumSize(QSize(16777215, 120));
        verticalLayout_12 = new QVBoxLayout(gbx_compilerOutput);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        txe_compilerOutput = new QTextEdit(gbx_compilerOutput);
        txe_compilerOutput->setObjectName(QString::fromUtf8("txe_compilerOutput"));
        txe_compilerOutput->setReadOnly(true);

        verticalLayout_12->addWidget(txe_compilerOutput);


        verticalLayout_8->addWidget(gbx_compilerOutput);

        stw_studentAnswers->addWidget(wgt_studentProgrammingAnswer);
        wgt_alternatives = new QWidget();
        wgt_alternatives->setObjectName(QString::fromUtf8("wgt_alternatives"));
        horizontalLayout_3 = new QHBoxLayout(wgt_alternatives);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gbx_alternatives = new QGroupBox(wgt_alternatives);
        gbx_alternatives->setObjectName(QString::fromUtf8("gbx_alternatives"));

        horizontalLayout_3->addWidget(gbx_alternatives);

        stw_studentAnswers->addWidget(wgt_alternatives);
        wgt_studentDiscursiveAnswer = new QWidget();
        wgt_studentDiscursiveAnswer->setObjectName(QString::fromUtf8("wgt_studentDiscursiveAnswer"));
        verticalLayout_13 = new QVBoxLayout(wgt_studentDiscursiveAnswer);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        gbx_studentDiscursiveAnswer = new QGroupBox(wgt_studentDiscursiveAnswer);
        gbx_studentDiscursiveAnswer->setObjectName(QString::fromUtf8("gbx_studentDiscursiveAnswer"));
        horizontalLayout_2 = new QHBoxLayout(gbx_studentDiscursiveAnswer);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ptx_studentDiscursiveAnswer = new QPlainTextEdit(gbx_studentDiscursiveAnswer);
        ptx_studentDiscursiveAnswer->setObjectName(QString::fromUtf8("ptx_studentDiscursiveAnswer"));

        horizontalLayout_2->addWidget(ptx_studentDiscursiveAnswer);


        verticalLayout_13->addWidget(gbx_studentDiscursiveAnswer);

        stw_studentAnswers->addWidget(wgt_studentDiscursiveAnswer);

        gridLayout_12->addWidget(stw_studentAnswers, 1, 1, 1, 1);

        gbx_examQuestionsList = new QGroupBox(wgt_studentExam);
        gbx_examQuestionsList->setObjectName(QString::fromUtf8("gbx_examQuestionsList"));
        verticalLayout_3 = new QVBoxLayout(gbx_examQuestionsList);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gbx_commands = new QGroupBox(gbx_examQuestionsList);
        gbx_commands->setObjectName(QString::fromUtf8("gbx_commands"));
        gridLayout_8 = new QGridLayout(gbx_commands);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        btn_compile = new QPushButton(gbx_commands);
        btn_compile->setObjectName(QString::fromUtf8("btn_compile"));

        gridLayout_8->addWidget(btn_compile, 0, 0, 1, 1);

        btn_run = new QPushButton(gbx_commands);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));

        gridLayout_8->addWidget(btn_run, 0, 1, 1, 1);

        ltw_examQuestionsList = new QListWidget(gbx_commands);
        ltw_examQuestionsList->setObjectName(QString::fromUtf8("ltw_examQuestionsList"));

        gridLayout_8->addWidget(ltw_examQuestionsList, 2, 0, 1, 2);


        verticalLayout_3->addWidget(gbx_commands);

        btn_finishExam = new QPushButton(gbx_examQuestionsList);
        btn_finishExam->setObjectName(QString::fromUtf8("btn_finishExam"));

        verticalLayout_3->addWidget(btn_finishExam);


        gridLayout_12->addWidget(gbx_examQuestionsList, 0, 0, 3, 1);

        gbx_questionDescription = new QGroupBox(wgt_studentExam);
        gbx_questionDescription->setObjectName(QString::fromUtf8("gbx_questionDescription"));
        gridLayout_7 = new QGridLayout(gbx_questionDescription);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        txe_questionDescription = new QTextEdit(gbx_questionDescription);
        txe_questionDescription->setObjectName(QString::fromUtf8("txe_questionDescription"));
        txe_questionDescription->setReadOnly(true);

        gridLayout_7->addWidget(txe_questionDescription, 0, 0, 1, 1);


        gridLayout_12->addWidget(gbx_questionDescription, 0, 1, 1, 1);

        stw_mainInterface->addWidget(wgt_studentExam);
        p_busca_bd = new QWidget();
        p_busca_bd->setObjectName(QString::fromUtf8("p_busca_bd"));
        gridLayout_10 = new QGridLayout(p_busca_bd);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        stacked_bd = new QStackedWidget(p_busca_bd);
        stacked_bd->setObjectName(QString::fromUtf8("stacked_bd"));
        bd_programacao = new QWidget();
        bd_programacao->setObjectName(QString::fromUtf8("bd_programacao"));
        gridLayout_13 = new QGridLayout(bd_programacao);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        bd_input = new QLabel(bd_programacao);
        bd_input->setObjectName(QString::fromUtf8("bd_input"));

        gridLayout_13->addWidget(bd_input, 1, 1, 1, 1);

        bd_output = new QLabel(bd_programacao);
        bd_output->setObjectName(QString::fromUtf8("bd_output"));

        gridLayout_13->addWidget(bd_output, 1, 2, 1, 1);

        label_bd_numcomp = new QLabel(bd_programacao);
        label_bd_numcomp->setObjectName(QString::fromUtf8("label_bd_numcomp"));

        gridLayout_13->addWidget(label_bd_numcomp, 0, 1, 1, 1);

        bd_numcomp = new QLineEdit(bd_programacao);
        bd_numcomp->setObjectName(QString::fromUtf8("bd_numcomp"));
        bd_numcomp->setReadOnly(true);

        gridLayout_13->addWidget(bd_numcomp, 0, 2, 1, 1);

        bd_ltw_compilationInput = new QListWidget(bd_programacao);
        bd_ltw_compilationInput->setObjectName(QString::fromUtf8("bd_ltw_compilationInput"));

        gridLayout_13->addWidget(bd_ltw_compilationInput, 2, 1, 1, 1);

        bd_l_output = new QListWidget(bd_programacao);
        bd_l_output->setObjectName(QString::fromUtf8("bd_l_output"));

        gridLayout_13->addWidget(bd_l_output, 2, 2, 1, 1);

        stacked_bd->addWidget(bd_programacao);
        bd_mult = new QWidget();
        bd_mult->setObjectName(QString::fromUtf8("bd_mult"));
        horizontalLayout_4 = new QHBoxLayout(bd_mult);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bd_respmult = new QListWidget(bd_mult);
        bd_respmult->setObjectName(QString::fromUtf8("bd_respmult"));

        horizontalLayout_4->addWidget(bd_respmult);

        stacked_bd->addWidget(bd_mult);
        bd_discursiva = new QWidget();
        bd_discursiva->setObjectName(QString::fromUtf8("bd_discursiva"));
        horizontalLayout_5 = new QHBoxLayout(bd_discursiva);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        bd_respdiscursiva = new QTextEdit(bd_discursiva);
        bd_respdiscursiva->setObjectName(QString::fromUtf8("bd_respdiscursiva"));
        bd_respdiscursiva->setFrameShape(QFrame::WinPanel);
        bd_respdiscursiva->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(bd_respdiscursiva);

        stacked_bd->addWidget(bd_discursiva);

        gridLayout_10->addWidget(stacked_bd, 1, 1, 1, 2);

        groupBox_2 = new QGroupBox(p_busca_bd);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        materia = new QComboBox(groupBox_2);
        materia->setObjectName(QString::fromUtf8("materia"));
        materia->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout_9->addWidget(materia, 1, 2, 1, 2);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        assunto = new QComboBox(groupBox_3);
        assunto->setObjectName(QString::fromUtf8("assunto"));

        verticalLayout_7->addWidget(assunto);

        list_questoes = new QListWidget(groupBox_3);
        list_questoes->setObjectName(QString::fromUtf8("list_questoes"));

        verticalLayout_7->addWidget(list_questoes);


        gridLayout_9->addWidget(groupBox_3, 2, 2, 1, 2);

        voltar = new QPushButton(groupBox_2);
        voltar->setObjectName(QString::fromUtf8("voltar"));

        gridLayout_9->addWidget(voltar, 3, 3, 1, 1);

        adicionar_question = new QPushButton(groupBox_2);
        adicionar_question->setObjectName(QString::fromUtf8("adicionar_question"));

        gridLayout_9->addWidget(adicionar_question, 3, 2, 1, 1);


        gridLayout_10->addWidget(groupBox_2, 0, 0, 2, 1);

        enunciado_questao = new QTextEdit(p_busca_bd);
        enunciado_questao->setObjectName(QString::fromUtf8("enunciado_questao"));
        enunciado_questao->setFrameShape(QFrame::WinPanel);
        enunciado_questao->setFrameShadow(QFrame::Sunken);
        enunciado_questao->setReadOnly(true);

        gridLayout_10->addWidget(enunciado_questao, 0, 2, 1, 1);

        stw_mainInterface->addWidget(p_busca_bd);

        gridLayout_11->addWidget(stw_mainInterface, 0, 0, 1, 1);

        MainWindow->setCentralWidget(wgt_centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
        lbl_compilationAmount->setBuddy(spb_compilationAmount);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);
        QObject::connect(ckb_checkUser, SIGNAL(toggled(bool)), lne_loginPassword, SLOT(setEnabled(bool)));

        stw_mainInterface->setCurrentIndex(2);
        tbw_student->setCurrentIndex(0);
        stw_doExam->setCurrentIndex(0);
        tbw_professor->setCurrentIndex(1);
        stw_answers->setCurrentIndex(0);
        cbb_type->setCurrentIndex(0);
        stw_applyExam->setCurrentIndex(0);
        stw_studentAnswers->setCurrentIndex(1);
        stacked_bd->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        gbx_login->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        lne_loginUser->setPlaceholderText(QCoreApplication::translate("MainWindow", "Usu\303\241rio", nullptr));
        lne_loginPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Senha", nullptr));
        ckb_checkUser->setText(QCoreApplication::translate("MainWindow", "Professor", nullptr));
        btn_login->setText(QCoreApplication::translate("MainWindow", "Entrar", nullptr));
        lbl_status->setText(QCoreApplication::translate("MainWindow", "Offline", nullptr));
        btn_studentLogout->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
        tbw_student->setTabText(tbw_student->indexOf(wgt_studentProfile), QCoreApplication::translate("MainWindow", "Perfil", nullptr));
        btn_enterRoom->setText(QCoreApplication::translate("MainWindow", "Entrar na Sala", nullptr));
        lbl_roomDoor->setText(QCoreApplication::translate("MainWindow", "Insira a porta:", nullptr));
        lbl_roomHostName->setText(QCoreApplication::translate("MainWindow", "Insira o endere\303\247o Host:", nullptr));
        btn_startExam->setText(QCoreApplication::translate("MainWindow", "Iniciar Prova", nullptr));
        lbl_doExamMessage->setText(QCoreApplication::translate("MainWindow", "Aguardando recebimento da prova...", nullptr));
        tbw_student->setTabText(tbw_student->indexOf(wgt_exam), QCoreApplication::translate("MainWindow", "Fazer Prova", nullptr));
        gbx_professorProfile->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        lbl_professorImage->setText(QString());
        lbl_professorName->setText(QCoreApplication::translate("MainWindow", "Nome do Professor", nullptr));
        btn_professorLogout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        tbw_professor->setTabText(tbw_professor->indexOf(wgt_professorProfile), QCoreApplication::translate("MainWindow", "Perfil", nullptr));
        gbx_answer->setTitle(QCoreApplication::translate("MainWindow", "Gabarito", nullptr));
        lbl_compilationAmount->setText(QCoreApplication::translate("MainWindow", "N\303\272mero de compila\303\247\303\265es:", nullptr));
        btn_addTest->setText(QCoreApplication::translate("MainWindow", "Adicionar Teste", nullptr));
        btn_removeTest->setText(QCoreApplication::translate("MainWindow", "Remover Teste", nullptr));
        lbl_compilationInput->setText(QCoreApplication::translate("MainWindow", "INPUT", nullptr));
        lbl_compilationOutput->setText(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
        btn_addAlternative->setText(QCoreApplication::translate("MainWindow", "Adicionar Alternativa", nullptr));
        btn_removeAlternative->setText(QCoreApplication::translate("MainWindow", "Remover Alternativa", nullptr));
        txe_discursiveAnswer->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        gbx_setQuestionDescription->setTitle(QCoreApplication::translate("MainWindow", "Enunciado", nullptr));
        gbx_createExam->setTitle(QCoreApplication::translate("MainWindow", "Quest\303\265es", nullptr));
        btn_addToDb->setText(QCoreApplication::translate("MainWindow", "Adicionar quest\303\243o no banco de dados", nullptr));
        btn_searchOnDb->setText(QCoreApplication::translate("MainWindow", "Buscar quest\303\265es no banco de dados", nullptr));
        btn_createExam->setText(QCoreApplication::translate("MainWindow", "Gerar Prova", nullptr));
        gbx_setExamQuestionsList->setTitle(QString());
        btn_removeQuestion->setText(QCoreApplication::translate("MainWindow", "Remover Quest\303\243o", nullptr));
        btn_addQuestion->setText(QCoreApplication::translate("MainWindow", "Nova Quest\303\243o", nullptr));
        cbb_difficulty->setItemText(0, QCoreApplication::translate("MainWindow", "F\303\241cil", nullptr));
        cbb_difficulty->setItemText(1, QCoreApplication::translate("MainWindow", "M\303\251dio", nullptr));
        cbb_difficulty->setItemText(2, QCoreApplication::translate("MainWindow", "Dif\303\255cil", nullptr));

        cbb_type->setItemText(0, QCoreApplication::translate("MainWindow", "Programa\303\247\303\243o", nullptr));
        cbb_type->setItemText(1, QCoreApplication::translate("MainWindow", "M\303\272ltipla escolha", nullptr));
        cbb_type->setItemText(2, QCoreApplication::translate("MainWindow", "Discursiva", nullptr));

        gbx_setQuestionTitle->setTitle(QCoreApplication::translate("MainWindow", "T\303\255tulo", nullptr));
        txe_setTitle->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        tbw_professor->setTabText(tbw_professor->indexOf(wgt_editExam), QCoreApplication::translate("MainWindow", "Criar Prova", nullptr));
        lbl_setRoomDoor->setText(QCoreApplication::translate("MainWindow", "Insira a Porta:", nullptr));
        btn_createRoom->setText(QCoreApplication::translate("MainWindow", "Iniciar Sala", nullptr));
        btn_setExamStarted->setText(QCoreApplication::translate("MainWindow", "Iniciar Prova", nullptr));
        btn_setExamFinished->setText(QCoreApplication::translate("MainWindow", "Encerrar Prova", nullptr));
        btn_closeRoom->setText(QCoreApplication::translate("MainWindow", "Fechar Sala", nullptr));
        lbl_roomLobby->setText(QCoreApplication::translate("MainWindow", "Lobby da Sala:", nullptr));
        lbl_setExamFileDirectory->setText(QCoreApplication::translate("MainWindow", "Diret\303\263rio da Prova:", nullptr));
        btn_loadExamFile->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        tbw_professor->setTabText(tbw_professor->indexOf(wgt_applyExam), QCoreApplication::translate("MainWindow", "Aplicar Prova", nullptr));
        gbx_studentProgrammingAnswer->setTitle(QCoreApplication::translate("MainWindow", "C\303\263digo", nullptr));
        gbx_compilerOutput->setTitle(QCoreApplication::translate("MainWindow", "Output Compilador", nullptr));
        gbx_alternatives->setTitle(QCoreApplication::translate("MainWindow", "Resposta", nullptr));
        gbx_studentDiscursiveAnswer->setTitle(QCoreApplication::translate("MainWindow", "Resposta", nullptr));
        gbx_examQuestionsList->setTitle(QCoreApplication::translate("MainWindow", "Quest\303\265es", nullptr));
        gbx_commands->setTitle(QString());
        btn_compile->setText(QCoreApplication::translate("MainWindow", "Compilar", nullptr));
        btn_run->setText(QCoreApplication::translate("MainWindow", "Executar", nullptr));
        btn_finishExam->setText(QCoreApplication::translate("MainWindow", "Entregar Prova", nullptr));
        gbx_questionDescription->setTitle(QCoreApplication::translate("MainWindow", "Enunciado", nullptr));
        bd_input->setText(QCoreApplication::translate("MainWindow", "INPUT", nullptr));
        bd_output->setText(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
        label_bd_numcomp->setText(QCoreApplication::translate("MainWindow", "Compila\303\247\303\265es", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Busca", nullptr));
        materia->setCurrentText(QString());
        groupBox_3->setTitle(QString());
        voltar->setText(QCoreApplication::translate("MainWindow", "Voltar", nullptr));
        adicionar_question->setText(QCoreApplication::translate("MainWindow", "Adicionar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
