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

    Projet* projet1=projm.createProjet("Projet1","DescriptionProjet1");

    QDate dd1(2015,9,6);
    QDate de1(2015,9,10);
    QDate dd2(2015,9,10);
    QDate de2(2015,9,11);
    QDate dprog1(2015,9,10);

    TacheUnitaire* tache1=projet1->addTacheUnitaire("t1","titre1","description1",10,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",20,1);
    TacheUnitaire* tache3=projet1->addTacheUnitaire("t3","titre2","description2",dd1,de1,30,1);
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre3","desc3",dd2,de2);
    TacheComposite* tache5=projet1->addTacheComposite("t5","titre4","desc4");
    TacheComposite* tache6=projet1->addTacheComposite("t6","titre2","description2");

    ProgrammationTache* prog1=progm.addProgrammationTache("p1",dprog1,13,20,tache2);
    ProgrammationTache* prog2=progm.addProgrammationTache("p2",dprog1,10,11,tache1);

    ProgrammationActivite* prog3=progm.addProgrammationActivite("p3",dprog1,0,2,"act1","desc1");
    ProgrammationActivite* prog4=progm.addProgrammationActivite("p4",dprog1,2,3,"act2","desc2");

    Interface f;
    f.setFixedSize(1300,500);
    f.show();

    return a.exec();
}
