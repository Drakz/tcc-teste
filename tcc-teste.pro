#-------------------------------------------------
#
# Project created by QtCreator 2020-03-02T10:18:34
#
#-------------------------------------------------

QT       += core gui sql network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcc-teste
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        aluno.cpp \
        mainwindow.cpp \
        student.cpp \
        bancodedados.cpp \
        main.cpp \
        MainWindow.cpp \
        myserver.cpp \
        mysocket.cpp \
        professor.cpp \
        question.cpp \
        xml.cpp

HEADERS += \
        aluno.h \
        mainwindow.h \
        student.h \
        bancodedados.h \
        MainWindow.h \
        myserver.h \
        mysocket.h \
        professor.h \
        question.h \
        xml.h

FORMS += \
        mainwindow.ui \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    foto_perfil.qrc
