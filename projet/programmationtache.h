#ifndef ProgrammationTache_H
#define ProgrammationTache_H

#include "programmation.h"

class ProgrammationTache : public Programmation
{
    friend class ProgrammationManager;
private:
    ProgrammationTache(QString id, QDate dat, int hd, int hf, Tache *ta);
    virtual ~ProgrammationTache();

    Tache* tache;

public:
    Tache* getTache()const{return tache;}
};

#endif // ProgrammationTache_H
