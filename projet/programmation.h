#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QDate>
#include<QString>
#include "tache.h"

class ProgrammationManager;
class ProgrammationTache;

class Programmation
{
    friend class ProgrammationManager;
protected:
    Programmation(QString id, QDate dat, int hd, int hf);
    virtual ~Programmation();

    QString identifiant;
    QDate date;
    int heureDebut;
    int heureFin;


public:
    QString getIdentifiant() const {return identifiant;}
    QDate getDate() const {return date;}
    int getHeureDebut() const {return heureDebut;}
    int getHeureFin() const {return heureFin;}

};

#endif // PROGRAMMATION_H
