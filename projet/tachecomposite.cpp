#include<QDebug>
#include "tachecomposite.h"

TacheComposite::TacheComposite(const QString &id, const QString &tit, const QString &desc, Projet *p):
    Tache(id, tit, desc, p)
{
    qDebug()<<"Creation de la tache composite"<<id;
}

TacheComposite::TacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                               const QDate& de, Projet *p):
    Tache(id, tit, desc, dd, de, p)
{
    qDebug()<<"Creation de la tache composite"<<id;
}

TacheComposite::~TacheComposite()
{
    qDebug()<<"Suppression de la tache composite"<<identifiant;
}

void TacheComposite::addSousTache(Tache* tache)
{
    Projet* projetTacheAjoutee = tache->getProjet();
    Projet* projetTacheComposite = getProjet();

    if(projetTacheAjoutee!=projetTacheComposite)
    {
        qDebug()<<"La tache composite"<<identifiant<<"et la tache"<<tache->getIdentifiant()
                <<"n'appartiennent pas au meme projet, ajout impossible";
        return;
    }

    if(tache->getTacheMereComposite()!=0)
    {
        qDebug()<<"La tache"<<tache->getIdentifiant()<<"est deja liee a la tache composite"
                <<tache->getTacheMereComposite()->getIdentifiant();
        return;
    }

    for(int i=0;i<listeSousTaches.size();i++)
        if(tache->getIdentifiant()==listeSousTaches.at(i)->getIdentifiant()){
            qDebug()<<"La tache"<<tache->getIdentifiant()<<"est deja une sous tache de"<<getIdentifiant();
            return;
        }
    listeSousTaches.append(tache);
    tache->setTacheMereComposite(this);
    qDebug()<<"La tache"<<tache->getIdentifiant()<<"a ete ajoutee en tant que sous tache de"<<getIdentifiant();
}

