#include<QDebug>
#include "programmation.h"

Programmation::Programmation(int id, QDate dat, int hd, int hf):
    identifiant(id),date(dat),heureDebut(hd),heureFin(hf)
{
    qDebug()<<"Debut de creation de la programmation"<<identifiant;
}

Programmation::~Programmation()
{
    qDebug()<<"Suppression de la programmation"<<identifiant;
}
