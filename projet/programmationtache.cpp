#include "ProgrammationTache.h"

ProgrammationTache::ProgrammationTache(int id, QDate dat, int hd, int hf, Tache* ta):
    Programmation(id,dat,hd,hf),tache(ta)
{
    qDebug()<<"Construction de la programmation"<<id;
}

ProgrammationTache::~ProgrammationTache()
{
    qDebug()<<"Debut de destruction de la programmation"<<identifiant;
}

