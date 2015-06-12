#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QDate>
#include "Tache.h"
#include "Evenement.h"

class Programmation
{
    friend class ProgrammationManager;

private:
    int identifiant;
    Evenement* evenement;
    Tache* tache;
    QDate date;
    int heureDebut;
    int heureFin;


public:
    Programmation(int id, Evenement* eve, QDate dat, int hd, int hf);
    Programmation(int id, Tache* ta, QDate dat, int hd, int hf);
    ~Programmation();

    int getIdentifiant() const {return identifiant;}
    Evenement* getEvenement() const {return evenement;}
    Tache* getTache() const {return tache;}
    QDate getDate() const {return date;}
    int getHeureDebut() const {return heureDebut;}
    int getHeureFin() const {return heureFin;}

};

#endif // PROGRAMMATION_H
