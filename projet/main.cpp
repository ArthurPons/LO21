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
    Projet* projet2=pm.createProjet("Projet2","DescriptionProjet2");

    TacheUnitaire* tache1=projet2->addTacheUnitaire("t1","titre1","description1",30,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",30,1);
    TacheComposite* tache3=projet1->addTacheComposite("t3","titre3","desc3");
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre4","desc4");

    tache3->addSousTache(tache2);
    tache4->addSousTache(tache3);

    return a.exec();
}
