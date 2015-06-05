#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<QString>
#include<qDebug>
#include "tache.h"
#include "projet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Projet projet1("projet1","pdescription1");

    projet1.createAddTache("t1","titre1","description1",&projet1);

    Tache* tache=projet1.getTache("t1");
    qDebug()<<tache->getDescription();
    projet1.createAddTache("t1","titre1","description1",&projet1);

    return a.exec();
}
