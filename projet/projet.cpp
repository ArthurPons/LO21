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


Projet::~Projet()
{
    qDebug()<<"Destruction du Projet"<<titre;
    listeTaches.~QVector();
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
    TacheUnitaire* tache = new TacheUnitaire(id, tit, desc, dur, pre, this);

    for(int i=0;i<listeTaches.size();i++)
        if(tache->getIdentifiant()==listeTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache unitaire"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
            return 0;
        }
    listeTaches.append(tache);
    qDebug()<<"La tache unitaire"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}

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
    listeTaches.append(tache);
    qDebug()<<"La tache composite"<<id<<"a ete ajoutee au projet"<<getTitre();
    return tache;
}
