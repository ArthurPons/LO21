#include<QDebug>
#include "ProgrammationTache.h"

ProgrammationTache::ProgrammationTache(const QString &id, const QDate &dat, const int &hd, const int &hf, TacheUnitaire *ta):
    Programmation(id,dat,hd,hf),tache(ta)
{
    qDebug()<<"Construction de la programmation"<<id;
}

ProgrammationTache::~ProgrammationTache()
{
    qDebug()<<"Debut de destruction de la programmation"<<identifiant;
}

