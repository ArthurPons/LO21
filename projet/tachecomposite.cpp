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

