#include<QDebug>
#include "programmation.h"

Programmation::Programmation(int id, Tache *ta, QDate dat, int hd, int hf):
    identifiant(id),tache(ta),evenement(0),date(dat),heureDebut(hd),heureFin(hf)
{
    qDebug()<<"Creation de la programmation"<<identifiant;
}

Programmation::Programmation(int id, Evenement *eve, QDate dat, int hd, int hf):
    identifiant(id),tache(0),evenement(eve),date(dat),heureDebut(hd),heureFin(hf)
{
    qDebug()<<"Creation de la programmation"<<identifiant;
}

Programmation::~Programmation()
{
    qDebug()<<"Suppression de la programmation"<<identifiant;
}
