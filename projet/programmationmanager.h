#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include<QVector>
#include "Programmation.h"

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

    Programmation* createProgrammationTache(int id, QDate dat, int hd, int hf, Tache *ta);
    void suppProgrammation(Programmation* prog);
};

#endif // PROGRAMMATIONMANAGER_H
