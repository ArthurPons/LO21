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

    Programmation* createProgrammation(const QString& t, const QString& d);
    Programmation* createProgrammation(const QString& t, const QString& d, const QDate& dd, const QDate& de);
    void suppProgrammation(Projet* projet);
};

#endif // PROGRAMMATIONMANAGER_H
