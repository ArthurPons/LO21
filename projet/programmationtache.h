#ifndef ProgrammationTache_H
#define ProgrammationTache_H

#include "programmation.h"

class ProgrammationTache : public Programmation
{
private:
    ProgrammationTache(int id, QDate dat, int hd, int hf, Tache *ta);
    ~ProgrammationTache();

    Tache* tache;

public:
    Tache* getTache()const{return tache;}
};

#endif // ProgrammationTache_H
