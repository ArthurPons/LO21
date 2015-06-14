#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<QString>
#include<qDebug>
#include "tache.h"
#include "projet.h"
#include "projetmanager.h"
#include "programmationmanager.h"
#include "interface.h"
#include "listeprojets.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    ProjetManager& projm=ProjetManager::Instance();
    ProgrammationManager& progm=ProgrammationManager::Instance();

    Projet* projet1=projm.addProjet("Projet1","DescriptionProjet1");

    //Projet* projet2=projm.addProjet("Projet2","DescriptionProjet2");
    //Projet* projet3=projm.addProjet("Projet3","DescriptionProjet3");
    //Projet* projet4=projm.addProjet("Projet4","DescriptionProjet4");


    QDate dd1(2015,9,6);
    QDate de1(2015,9,10);
    QDate dd2(2015,9,10);
    QDate de2(2015,9,11);
    QDate dprog1(2015,6,14);
    QDate dprog2(2015,9,10);

    TacheUnitaire* tache1=projet1->addTacheUnitaire("t1","titre1","description1",10,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",2,0);
    TacheUnitaire* tache3=projet1->addTacheUnitaire("t3","titre2","description2",dd1,de1,30,1);
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre3","desc3",dd2,de2);
    TacheComposite* tache5=projet1->addTacheComposite("t5","titre4","desc4");
    TacheComposite* tache6=projet1->addTacheComposite("t6","titre2","description2");

    Programmation* prog1=progm.addProgrammationActivite("Truc à faire", dprog1, 10, 12, "lourd", "lo21");

    Interface f;
    f.setFixedSize(1300,500);
    f.show();

    return a.exec();
}
