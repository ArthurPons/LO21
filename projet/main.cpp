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

    qDebug()<<projet1->getlisteTaches().size();

    for(int i=0;i<projet1->getlisteTaches().size();i++){
        qDebug()<<projet1->getlisteTaches().at(i)->getIdentifiant();
    }

    //projet1->suppTache(tache1);
    projet1->suppTache(tache4);

    for(int i=0;i<projet1->getlisteTaches().size();i++){
        qDebug()<<projet1->getlisteTaches().at(i)->getIdentifiant();
    }

    qDebug()<<projet1->getlisteTaches().size();

    tache3->addPrecedence(tache2);
    tache3->addPrecedence(tache1);

    qDebug()<<tache3->getListeTachesMeresPrecedence().size();

    projet1->suppTache(tache2);

    qDebug()<<tache3->getListeTachesMeresPrecedence().size();

    for(int i=0;i<tache3->getListeTachesMeresPrecedence().size();i++)
        qDebug()<<tache3->getListeTachesMeresPrecedence().at(i)->getIdentifiant();

    //Question : Est-ce qu'une sous-tâche peut précéder sa tache mêre ?

    /*
    QVector<Tache*> precedencesTache1=tache1->getListeTachesMeresPrecedence();
    for(int i=0;i<precedencesTache1.size();i++)
        qDebug()<<"La tache"<<precedencesTache1.at(i)->getIdentifiant()<<"precede la tache"<<tache1->getIdentifiant();
    */

    return a.exec();
}
