#include<QDebug>
#include "programmationactivite.h"

ProgrammationActivite::ProgrammationActivite(QString id, QDate dat, int hd, int hf, QString tit, QString desc):
    Programmation(id,dat,hd,hf),titre(tit),description(desc)
{
    qDebug()<<"Construction de la programmation d'activite"<<id;
}

ProgrammationActivite::~ProgrammationActivite()
{
    qDebug()<<"Debut de destruction de la programmation d'activite"<<identifiant;
}
