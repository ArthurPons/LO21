#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T15:43:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tache.cpp \
    projet.cpp \
    projetmanager.cpp \
    tacheunitaire.cpp \
    tachecomposite.cpp \
    interface.cpp \
    listeprojets.cpp \
    programmationmanager.cpp \
    programmation.cpp \
    programmationtache.cpp

HEADERS  += mainwindow.h \
    tache.h \
    tachemanager.h \
    projet.h \
    projetmanager.h \
    tacheunitaire.h \
    tachecomposite.h \
    interface.h \
    listeprojets.h \
    programmationmanager.h \
    programmation.h \
    programmationtache.h

FORMS    += mainwindow.ui
