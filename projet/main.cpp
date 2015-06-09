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
    //Projet* projet2=pm.createProjet("Projet2","DescriptionProjet2");

    TacheUnitaire* tache1=projet1->addTacheUnitaire("t1","titre1","description1",30,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",30,1);
    TacheUnitaire* tache3=projet1->addTacheUnitaire("t3","titre2","description2",30,1);
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre3","desc3");
    TacheComposite* tache5=projet1->addTacheComposite("t5","titre4","desc4");
    TacheComposite* tache6=projet1->addTacheComposite("t6","titre2","description2");

    tache4->addSousTache(tache1);
    tache4->addSousTache(tache3);
    tache5->addSousTache(tache4);
    tache5->addSousTache(tache2);
    tache1->addPrecedence(tache6);
    tache6->addPrecedence(tache5);


    //Question : Est-ce qu'une sous-tâche peut précéder sa tache mêre ?

    /*
    QVector<Tache*> precedencesTache1=tache1->getListeTachesMeresPrecedence();
    for(int i=0;i<precedencesTache1.size();i++)
        qDebug()<<"La tache"<<precedencesTache1.at(i)->getIdentifiant()<<"precede la tache"<<tache1->getIdentifiant();
    */

    return a.exec();
}
