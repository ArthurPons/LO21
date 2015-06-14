#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include<QVector>
#include "programmation.h"
#include "programmationtache.h"
#include "programmationactivite.h"

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
    ProgrammationActivite* addProgrammationActivite(QString id, QDate dat, int hd, int hf, QString tit, QString desc);
    void suppProgrammationTache(ProgrammationTache *prog);
    void suppProgrammationActivite(ProgrammationActivite* prog);
};

#endif // PROGRAMMATIONMANAGER_H
