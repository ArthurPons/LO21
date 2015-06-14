#include<QDebug>
#include "programmation.h"

Programmation::Programmation(const QString &id, const QDate &dat, const int &hd, const int &hf):
    identifiant(id),date(dat),heureDebut(hd),heureFin(hf)
{
    qDebug()<<"Debut de creation de la programmation"<<identifiant;
}

Programmation::~Programmation()
{
    qDebug()<<"Suppression de la programmation"<<identifiant;
}

