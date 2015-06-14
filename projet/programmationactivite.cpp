#include<QDebug>
#include "programmationactivite.h"

ProgrammationActivite::ProgrammationActivite(const QString &id, const QDate &dat, const int &hd, const int &hf, const QString &tit, const QString &desc):
    Programmation(id,dat,hd,hf),titre(tit),description(desc)
{
    qDebug()<<"Construction de la programmation d'activite"<<id;
}

ProgrammationActivite::~ProgrammationActivite()
{
    qDebug()<<"Debut de destruction de la programmation d'activite"<<identifiant;
}
