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
    Projet* projet2=pm.createProjet("Projet2","DescriptionProjet2");

    QDate dd1(2015,9,6);
    QDate de1(2015,9,6);
    QDate dd2(2015,9,10);
    QDate de2(2015,9,11);

    TacheUnitaire* tache1=projet1->addTacheUnitaire("t1","titre1","description1",30,1);
    TacheUnitaire* tache2=projet1->addTacheUnitaire("t2","titre2","description2",30,1);
    TacheUnitaire* tache3=projet1->addTacheUnitaire("t3","titre2","description2",30,1);
    TacheComposite* tache4=projet1->addTacheComposite("t4","titre3","desc3");
    TacheComposite* tache5=projet1->addTacheComposite("t5","titre4","desc4");
    TacheComposite* tache6=projet1->addTacheComposite("t6","titre2","description2");

    pm.suppProjet(projet1);

    /*
    if(tache5->getTacheMereComposite())
        qDebug()<<tache5->getTacheMereComposite()->getIdentifiant();
    else
        qDebug()<<"vide";
    */
    //Question : Est-ce qu'une sous-tâche peut précéder sa tache mêre ?

    /*
    QVector<Tache*> precedencesTache1=tache1->getListeTachesMeresPrecedence();
    for(int i=0;i<precedencesTache1.size();i++)
        qDebug()<<"La tache"<<precedencesTache1.at(i)->getIdentifiant()<<"precede la tache"<<tache1->getIdentifiant();
    */

    Interface f;
    f.setFixedSize(1300,500);
    //f.show();

    return a.exec();
}
