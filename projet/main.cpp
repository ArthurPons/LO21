#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<QString>
#include<qDebug>
#include "tache.h"
#include "projet.h"
#include "projetmanager.h"
#include "event.h"
#include "eventmanager.h"
#include "interface.h"
#include "listeprojets.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    ProjetManager& pm=ProjetManager::Instance();

    Projet* projet1=pm.createProjet("Projet1","DescriptionProjet1");

    QDate dd1(2015,9,6);
    QDate de1(2015,9,6);
    QDate dd2(2015,9,10);
    QDate de2(2015,9,11);


    TacheUnitaire* tache3=projet1->addTacheUnitaire("t3","titre2","description2",30,1);
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre3","desc3");
    TacheComposite* tache5=projet1->addTacheComposite("t5","titre4","desc4");
    TacheComposite* tache6=projet1->addTacheComposite("t6","titre2","description2");
    TacheUnitaire* tache1=projet1->addTacheUnitaire("t1","titre1","description1",30,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",30,1);

    tache4->addSousTache(tache1);
    tache4->addSousTache(tache2);

    projet1->suppTache(tache4);

    //pm.suppProjet(projet1);

    //qDebug()<<tache2->getTacheMereComposite()->getIdentifiant();

    //qDebug()<<projet1->getListeTaches().size();

    Interface f;
    f.setFixedSize(1300,500);
    f.show();

    return a.exec();
}
