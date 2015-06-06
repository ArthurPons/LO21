#include "tacheunitaire.h"

TacheUnitaire::TacheUnitaire(const QString& id, const QString& tit,const QString& desc,
              const int& dur, const bool& pre, Projet *p):
    Tache(id, tit, desc, p), duree(dur), preemptee(pre)
{
    qDebug()<<"Debut de la creation de la tache unitaire"<<id;
}

TacheUnitaire::TacheUnitaire(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
              const QDate& de, const int& dur, const bool& pre, Projet *p):
    Tache(id, tit, desc, dd, de, p), duree(dur), preemptee(pre)
{
    qDebug()<<"Debut de la creation de la tache unitaire"<<id;
}

TacheUnitaire::~TacheUnitaire()
{

}
