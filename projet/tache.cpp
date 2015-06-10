#include<QDebug>
#include<iostream>
#include "tache.h"
#include "projet.h"
#include "tachecomposite.h"

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
    if(precedence->getProjet()!=projet)
        return 0;

    if(precedence->getDateEcheance()>dateDispo)
        return 0;

    if(listeTachesMeresPrecedence.contains(precedence)||this==precedence)
        return 0;

    TacheComposite* tachecompo=dynamic_cast<TacheComposite*>(precedence);

    if(tachecompo!=0){
        for(int i=0;i<tachecompo->getListeSousTaches().size();i++){
            if(!checkPrecedence(tachecompo->getListeSousTaches().at(i)))
                return 0;
        }
    }

    for(int i=0;i<precedence->getListeTachesMeresPrecedence().size();i++){
        TacheComposite* precedenceComposite=dynamic_cast<TacheComposite*>(precedence->getListeTachesMeresPrecedence().at(i));
        if(precedenceComposite!=0){
            for(int j=0;j<precedenceComposite->getListeSousTaches().size();j++){
               if(!checkPrecedence(precedenceComposite->getListeSousTaches().at(j)))
                   return 0;
            }
        }
        if(!checkPrecedence(precedence->getListeTachesMeresPrecedence().at(i))){
            return 0;
        }
    }
    return 1;
}

