#include<QDebug>
#include<iostream>
#include "tache.h"
#include "projet.h"

Tache::Tache(const QString &id, const QString &t, const QString &d, Projet* p):
    identifiant(id),titre(t),description(d),projet(p)
{
    qDebug()<<"Creation Tache"<<id;
}

Tache::Tache(const QString &id, const QString &t, const QString &d, const QDate &dd, const QDate &de, Projet *p):
    identifiant(id),titre(t),description(d),datedispo(dd),dateecheance(de),projet(p)
{
    qDebug()<<"Creation Tache"<<id;
}

Tache::~Tache()
{
    qDebug()<<"Suppression Tache"<<identifiant;
}
