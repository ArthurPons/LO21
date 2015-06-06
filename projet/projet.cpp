#include<QDebug>
#include<QVector>
#include<QDate>
#include "projet.h"
#include "tache.h"

//Deux constructeurs

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

//Le destructeur détruit les tâches qui sont associées au projet

/*
~Projet()
{

}
*/

//Récupère une tâche en fonction de son identifiant

Tache* Projet::getTache(const QString& id)
{
    int n=listeTaches.size();
    for(int i=0;i<n;i++){
        if(id==listeTaches.at(i)->getIdentifiant())
            return listeTaches.at(i);
    }
    qDebug()<<"La Tache n'est pas liee au projet"<<getTitre();
    return 0;
}

//Créer puis ajoute une tâche au projet

Tache* Projet::createAddTache(const QString& id, const QString& t,const QString& d)
{
    Tache* tache;
    tache = new Tache(id, t, d, this);

    int n=listeTaches.size();
    for(int i=0;i<n;i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }
    listeTaches.append(tache);
    qDebug()<<"Tache"<<id<<"ajoutee au projet"<<getTitre();
    return tache;
}

Tache* Projet::createAddTache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de)
{
    Tache* tache;
    tache = new Tache(id, t, d, dd, de, this);

    int n=listeTaches.size();
    for(int i=0;i<n;i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }
    listeTaches.append(tache);
    qDebug()<<"Tache"<<id<<"ajoutee au projet"<<getTitre();
    return tache;
}
