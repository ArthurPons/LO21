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

void Tache::addPrecedence(Tache* precedence)
{
    if(checkPrecedence(precedence)){
        listeTachesMeresPrecedence.append(precedence);
        qDebug()<<"La tache"<<precedence->getIdentifiant()<<"precede la tache"<<identifiant;
        return;
    }
    else
    {
        qDebug()<<"La tache"<<precedence->getIdentifiant()<<"ne peut pas preceder"<<identifiant;
    }
}

bool Tache::checkPrecedence(Tache* precedence)
{
    if(listeTachesMeresPrecedence.contains(precedence)||this==precedence){
        return 0;
    }
    for(int i=0;i<precedence->getListeTachesMeresPrecedence().size();i++){
        if(!checkPrecedence(precedence->getListeTachesMeresPrecedence().at(i))){
            return 0;
        }
    }
    return 1;
}

