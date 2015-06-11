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
    event.cpp \
    eventmanager.cpp \
    interface.cpp \
    listeprojets.cpp

HEADERS  += mainwindow.h \
    tache.h \
    tachemanager.h \
    projet.h \
    projetmanager.h \
    tacheunitaire.h \
    tachecomposite.h \
    event.h \
    eventmanager.h \
    interface.h \
    listeprojets.h

FORMS    += mainwindow.ui
