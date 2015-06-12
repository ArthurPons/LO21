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

Projet::Projet(const QString& t, const QString& d, const QDate& dd, const QDate& de):
    titre(t),description(d),datedispo(dd),dateecheance(de)
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
    //On créer une instance de la classe pour faire des tests dessus

    TacheUnitaire* tache = new TacheUnitaire(id, tit, desc, dur, pre, this);

    //On ne souhaite pas avoir deux tâches possédants les même identifiants
    //Si ça ne va pas on supprime l'instance temporaire

    for(int i=0;i<listeTaches.size();i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache unitaire"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }

    //Si c'est bon on l'ajoute à la liste des taches

    if(dur<=0){
        qDebug()<<"La durée doit être supérieure à 0";
        return 0;
    }

    listeTaches.append(tache);
    qDebug()<<"La tache unitaire"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

//Idem pour le constructeur surchargé

TacheUnitaire* Projet::addTacheUnitaire(const QString& id, const QString& tit, const QString& desc,
                                        const QDate& dd, const QDate& de, const int dur, const bool pre)
{
    TacheUnitaire* tache = new TacheUnitaire(id, tit, desc, dd, de, dur, pre, this);

    for(int i=0;i<listeTaches.size();i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache unitaire "<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
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

    listeTaches.append(tache);
    qDebug()<<"La tache unitaire"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

TacheComposite* Projet::addTacheComposite(const QString &id, const QString &tit, const QString &desc)
{
    TacheComposite* tache = new TacheComposite(id, tit, desc, this);

    for(int i=0;i<listeTaches.size();i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache composite"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }

    listeTaches.append(tache);
    qDebug()<<"La tache composite"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

TacheComposite* Projet::addTacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                                          const QDate& de)
{
    TacheComposite* tache = new TacheComposite(id, tit, desc, dd, de, this);

    for(int i=0;i<listeTaches.size();i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache composite"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }

    if(dd>de){
        qDebug()<<"La date de dispo doit être inférieure à celle d'echeance";
        return 0;
    }

    listeTaches.append(tache);
    qDebug()<<"La tache composite"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

void Projet::suppTache(TacheUnitaire* tache)
{
    for(int i=0;i<listeTaches.size();i++){

        //Suppression de tous les endroits où il est marqué comme une précédence

        for(int j=0;j<listeTaches.at(i)->getListeTachesMeresPrecedence().size();j++)
            if(listeTaches.at(i)->getListeTachesMeresPrecedence().at(j)==tache)
                listeTaches.at(i)->suppPrecedence(tache);

        //Suppression dans le projet

        if(listeTaches.at(i)==tache)
            listeTaches.remove(i);

    }
    delete tache;
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
    delete tache;
}
