#ifndef PROGRAMMATIONACTIVITE_H
#define PROGRAMMATIONACTIVITE_H

#include "programmation.h"

class ProgrammationActivite : public Programmation
{
    friend class ProgrammationManager;
private:
    ProgrammationActivite(QString id, QDate dat, int hd, int hf, QString tit, QString desc);
    virtual ~ProgrammationActivite();

   QString titre;
   QString description;

public:
    QString getTitre()const{return titre;}
    QString getDescritpion()const{return description;}
};


#endif // PROGRAMMATIONACTIVITE_H
