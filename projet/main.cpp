#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<QString>
#include<qDebug>
#include "tache.h"
#include "projet.h"
#include "projetmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ProjetManager& pm=ProjetManager::Instance();

    Projet* projet1=pm.createProjet("Projet1","DescriptionProjet1");

    qDebug()<<projet1->getTitre();

    Tache* tache1=projet1->createAddTache("t1","titre1","description1");

    qDebug()<<tache1->getProjet()->getDescription();




    return a.exec();
}
