#include<QDebug>
#include<QVector>
#include<QDate>
#include "projet.h"
#include "tache.h"

Projet::Projet(const QString& t, const QString& d):
    titre(t),description(d)
{

}

Projet::Projet(const QString& t, const QString& d, const QDate& dd, const QDate& de):
    titre(t),description(d),datedispo(dd),dateecheance(de)
{

}

Tache* Projet::getTache(const QString& id)
{
    int n=listeTache.size();
    for(int i=0;i<n;i++){
        if(id==listeTache.at(i)->getIdentifiant())
            return listeTache.at(i);
    }
    qDebug()<<"La Tache n'est pas liee au projet"<<getTitre();
    return 0;
}

void Projet::createAddTache(const QString& id, const QString& t,const QString& d, Projet *p)
{
    Tache* tache;
    tache = new Tache(id, t, d, p);

    int n=listeTache.size();
    for(int i=0;i<n;i++)
        if(tache->getIdentifiant()==listeTache.at(i)->getIdentifiant()){
            qDebug()<<"La tache est deja liee au projet"<<getTitre();
            return;
        }
    listeTache.append(tache);

    qDebug()<<"Tache ajoutee au projet"<<getTitre();
}

void Projet::createAddTache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p)
{
    Tache* tache;
    tache = new Tache(id, t, d, dd, de, p);

    int n=listeTache.size();
    for(int i=0;i<n;i++)
        if(tache->getIdentifiant()==listeTache.at(i)->getIdentifiant()){
            qDebug()<<"La tache est deja liee au projet"<<getTitre();
            return;
        }
    listeTache.append(tache);

    qDebug()<<"Tache ajoutee au projet"<<getTitre();
}
