#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include<QVector>
#include "Programmation.h"
#include "ProgrammationTache.h"

class ProgrammationManager
{
private:
    ProgrammationManager();
    ~ProgrammationManager();
    ProgrammationManager& operator= (const ProgrammationManager&){}
    ProgrammationManager(const ProgrammationManager&){}
    static ProgrammationManager instance;
    QVector<Programmation*> listeProgrammation;

public:
    static ProgrammationManager& Instance();

    QVector<Programmation*> getListeProgrammation()const{return listeProgrammation;}

    ProgrammationTache* addProgrammationTache(QString id, QDate dat, int hd, int hf, TacheUnitaire *ta);
    void suppProgrammationTache(ProgrammationTache *prog);
};

#endif // PROGRAMMATIONMANAGER_H
