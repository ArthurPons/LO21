#ifndef ProgrammationTache_H
#define ProgrammationTache_H

#include "programmation.h"

class ProgrammationTache : public Programmation
{
    friend class ProgrammationManager;
private:
    ProgrammationTache(QString id, QDate dat, int hd, int hf, TacheUnitaire *ta);
    virtual ~ProgrammationTache();

    TacheUnitaire* tache;

public:
    TacheUnitaire* getTache()const{return tache;}
};

#endif // ProgrammationTache_H
