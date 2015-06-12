#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QDate>
#include "Tache.h"

class Programmation
{
    friend class ProgrammationManager;

private:
    Programmation(int id, QDate dat, int hd, int hf);
    ~Programmation();

    int identifiant;
    QDate date;
    int heureDebut;
    int heureFin;


public:
    int getIdentifiant() const {return identifiant;}
    QDate getDate() const {return date;}
    int getHeureDebut() const {return heureDebut;}
    int getHeureFin() const {return heureFin;}

};

#endif // PROGRAMMATION_H
