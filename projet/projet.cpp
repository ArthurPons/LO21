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
        if(tache==listeTaches.at(i)){
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
        if(tache==listeTaches.at(i)){
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
        if(tache==listeTaches.at(i)){
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
        if(tache==listeTaches.at(i)){
            qDebug()<<"La tache composite"<<id<<"est deja liee au projet"<<getTitre();
            delete tache;
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
    //tache=NULL;
}

void Projet::suppTache(TacheComposite* tache)
{
    for(int i=0;i<listeTaches.size();i++){

        //Suppression de tous les endroits où il est marqué comme une précédence

        for(int j=0;j<listeTaches.at(i)->getListeTachesMeresPrecedence().size();j++)
            if(listeTaches.at(i)->getListeTachesMeresPrecedence().at(j)==tache)
                listeTaches.at(i)->suppPrecedence(tache);

        //Suppression dans le projet

        if(listeTaches.at(i)==tache)
            listeTaches.remove(i);

        if(listeTaches.at(i)->getTacheMereComposite()==tache->getTacheMereComposite())
            delete listeTaches.at(i)->getTacheMereComposite();

    }
    delete tache;
    tache=NULL;
}
