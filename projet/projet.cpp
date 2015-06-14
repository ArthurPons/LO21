#include<QDebug>
#include<QVector>
#include<QDate>
#include "projet.h"
#include "tache.h"

Projet::Projet(const QString& t, const QString& d):
    titre(t),description(d)
{
    qDebug()<<"Creation du projet"<<t;
}

Projet::~Projet()
{
    qDebug()<<"Destruction du Projet"<<titre;
}


//Récupère une tâche en fonction de son identifiant

Tache* Projet::getTache(const QString& id)
{
    for(int i=0;i<listeTaches.size();i++){
        if(id==listeTaches.at(i)->getIdentifiant())
            return listeTaches.at(i);
    }
    qDebug()<<"La Tache"<<id<<"n'est pas liee au projet"<<getTitre();
    return 0;
}

//Créer puis ajoute une tâche au projet

TacheUnitaire* Projet::addTacheUnitaire(const QString& id, const QString& tit,const QString& desc,
                                        const int dur, const bool pre)
{
    //On ne souhaite pas avoir deux tâches possédants les même identifiants

    for(int i=0;i<listeTaches.size();i++)
        if(id==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache unitaire"<<id<<"est deja liee au projet"<<getTitre();
            return 0;
        }

    //On vérifie que la durée de la tâche soit supérieure à 0

    if(dur<=0){
        qDebug()<<"La durée doit être supérieure à 0";
        return 0;
    }

    //Si c'est bon on l'ajoute à la liste des taches


    TacheUnitaire* tache = new TacheUnitaire(id, tit, desc, dur, pre, this);
    listeTaches.append(tache);
    qDebug()<<"La tache unitaire"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

//Idem pour le constructeur surchargé

TacheUnitaire* Projet::addTacheUnitaire(const QString& id, const QString& tit, const QString& desc,
                                        const QDate& dd, const QDate& de, const int dur, const bool pre)
{
    for(int i=0;i<listeTaches.size();i++)
        if(id==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache unitaire "<<id<<"est deja liee au projet"<<getTitre();
           return 0;
        }

    if(dd>de){
        qDebug()<<"La date de dispo doit être inférieure à celle d'echeance";
        return 0;
    }

    if(dur<=0){
        qDebug()<<"La durée doit être supérieure à 0";
        return 0;
    }

    if(de>dateEcheance)
        dateEcheance=de;

    if(dd<dateDispo)
        dateDispo=dd;

    TacheUnitaire* tache = new TacheUnitaire(id, tit, desc, dd, de, dur, pre, this);
    listeTaches.append(tache);
    qDebug()<<"La tache unitaire"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

TacheComposite* Projet::addTacheComposite(const QString &id, const QString &tit, const QString &desc)
{
    for(int i=0;i<listeTaches.size();i++)
        if(id==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache composite"<<id<<"est deja liee au projet"<<getTitre();
            return 0;
        }

    TacheComposite* tache = new TacheComposite(id, tit, desc, this);
    listeTaches.append(tache);
    qDebug()<<"La tache composite"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

TacheComposite* Projet::addTacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                                          const QDate& de)
{
    for(int i=0;i<listeTaches.size();i++)
        if(id==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache composite"<<id<<"est deja liee au projet"<<getTitre();
            return 0;
        }

    if(dd>de){
        qDebug()<<"La date de dispo doit être inférieure à celle d'echeance";
        return 0;
    }

    if(de>dateEcheance)
        dateEcheance=de;

    TacheComposite* tache = new TacheComposite(id, tit, desc, dd, de, this);
    listeTaches.append(tache);
    qDebug()<<"La tache composite"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

void Projet::suppTache(TacheUnitaire* tache)
{
    for(int i=0;i<listeTaches.size();i++){

        //Suppression de tous les endroits où elle est marquée comme une précédence

        for(int j=0;j<listeTaches.at(i)->getListeTachesMeresPrecedence().size();j++)
            if(listeTaches.at(i)->getListeTachesMeresPrecedence().at(j)==tache)
                listeTaches.at(i)->suppPrecedence(tache);

        //Suppression dans le projet

        if(listeTaches.at(i)==tache)
            listeTaches.remove(i);

    }

    QDate de=tache->getDateEcheance();

    delete tache;

    if(de==dateEcheance){
        QDate newDe=listeTaches.at(0)->getDateEcheance();
        for(int i=1;i<listeTaches.size();i++){
            if(listeTaches.at(i)->getDateEcheance()>newDe)
                newDe=listeTaches.at(i)->getDateEcheance();
        }
        dateEcheance=newDe;
    }
}

void Projet::suppTache(TacheComposite* tache)
{
    tache->getListeSousTaches().clear();

    for(int i=0;i<listeTaches.size();i++){

        //Suppression de tous les endroits où il est marqué comme une précédence

        for(int j=0;j<listeTaches.at(i)->getListeTachesMeresPrecedence().size();j++)
            if(listeTaches.at(i)->getListeTachesMeresPrecedence().at(j)==tache)
                listeTaches.at(i)->suppPrecedence(tache);

        //Suppression de toutes les sous-taches

        if(listeTaches.at(i)->getTacheMereComposite()==tache)
            delete listeTaches.at(i);

        //Suppression dans le projet

        if(listeTaches.at(i)==tache)
            listeTaches.remove(i);
    }

    QDate de=tache->getDateEcheance();

    delete tache;

    if(de==dateEcheance && listeTaches.size()!=0){
        QDate newDe=listeTaches.at(0)->getDateEcheance();
        for(int i=1;i<listeTaches.size();i++){
            if(listeTaches.at(i)->getDateEcheance()>newDe)
                newDe=listeTaches.at(i)->getDateEcheance();
        }
        dateEcheance=newDe;
    }
}
