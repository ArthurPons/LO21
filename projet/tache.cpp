#include<QDebug>
#include<iostream>
#include "tache.h"
#include "projet.h"

Tache::Tache(const QString &id, const QString &t, const QString &d, Projet* p):
    identifiant(id),titre(t),description(d),projet(p),tacheMereComposite(0)
{
    qDebug()<<"Debut de la creation de la Tache"<<id;
}

Tache::Tache(const QString &id, const QString &t, const QString &d, const QDate &dd, const QDate &de, Projet *p):
    identifiant(id),titre(t),description(d),dateDispo(dd),dateEcheance(de),projet(p),tacheMereComposite(0)
{
    qDebug()<<"Debut de la creation de la Tache"<<id;
}

Tache::~Tache()
{
    qDebug()<<"Suppression de la tache"<<identifiant;
}

void Tache::setTacheMereComposite(TacheComposite *mere)
{
    tacheMereComposite=mere;
}

void Tache::addPrecedence(TacheComposite* precedence)
{
    QVector<Tache*> listeSousTachesPrecedence=precedence->getListeSousTaches();

    if(this==precedence){
        qDebug()<<"La tache composite"<<identifiant<<"ne peut etre une precedence"
                <<"d'elle meme";
        return;
    }

    for(int i=0;listeSousTachesPrecedence.size();i++)
        if(this==listeSousTachesPrecedence.at(i)){
            qDebug()<<"La tache composite"<<identifiant<<"ne peut etre une precedence"
                    <<"d'elle meme";
            return;
        }

    for(int i=0;i<listeTachesMeresPrecedence.size();i++){
        if(listeTachesMeresPrecedence.at(i)==precedence){
            qDebug()<<"La tache"<<listeTachesMeresPrecedence.at(i)->getIdentifiant()
                    <<"est deja une precedence de la tache"<<getIdentifiant()
                    <<"impossible de rajouter"<<precedence->getIdentifiant()
                    <<"en tant que precedence";
            return;
        }
        for(int j=0;j<listeSousTachesPrecedence.size();j++){
            if(listeTachesMeresPrecedence.at(i)==listeSousTachesPrecedence.at(j)){
                qDebug()<<"La tache"<<listeSousTachesPrecedence.at(j)->getIdentifiant()
                        <<"est deja une precedence de la tache"<<getIdentifiant()
                        <<"impossible de rajouter"<<precedence->getIdentifiant()
                        <<"en tant que precedence";
                return;
            }
        }
    }

    listeTachesMeresPrecedence.append(precedence);
    qDebug()<<"La tache composite"<<precedence->getIdentifiant()
            <<"a ete ajoute en tant que precedence de"<<identifiant;
    for(int j=0;j<listeSousTachesPrecedence.size();j++){
        listeTachesMeresPrecedence.append(listeSousTachesPrecedence.at(j));
        qDebug()<<"La tache"<<listeSousTachesPrecedence.at(j)->getIdentifiant()
                <<"a ete ajoute en tant que precedence de"<<identifiant;
    }
}

void Tache::addPrecedence(TacheUnitaire* precedence)
{
    if(this==precedence){
        qDebug()<<"La tache"<<identifiant<<"ne peut etre une precedence"
                <<"d'elle meme";
        return;
    }

    for(int i=0;i<listeTachesMeresPrecedence.size();i++)
        if(listeTachesMeresPrecedence.at(i)==precedence){
            qDebug()<<"La tache"<<listeTachesMeresPrecedence.at(i)->getIdentifiant()
                    <<"est deja une precedence de la tache"<<getIdentifiant();
            return;
        }
    listeTachesMeresPrecedence.append(precedence);
    qDebug()<<"La tache unitaire"<<precedence->getIdentifiant()<<"a ete ajoute en tant que precedence de"<<identifiant;
}
