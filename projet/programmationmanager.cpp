#include<QDebug>
#include "ProgrammationManager.h"

ProgrammationManager ProgrammationManager::instance=ProgrammationManager();

ProgrammationManager::ProgrammationManager()
{

}

ProgrammationManager::~ProgrammationManager()
{

}

ProgrammationManager& ProgrammationManager::Instance()
{
    return instance;
}

ProgrammationTache* ProgrammationManager::addProgrammationTache(QString id, QDate dat, int hd, int hf, Tache *ta)
{
    if(!ta->getDateDispo().isNull() && !ta->getDateEcheance().isNull())
        if(ta->getDateDispo()>dat || dat>ta->getDateEcheance()){
            qDebug()<<"Programmation impossible, les dates ne concordent pas";
            return 0;
        }

    if(hd>hf || hd<0 || hd>23 || hf<1 || hf>24 || hf==hd){
        qDebug()<<"Problème avec les heures de debut et/ou de fin";
        return 0;
    }

    for(int i=0;i<listeProgrammation.size();i++){
        ProgrammationTache* progra=static_cast<ProgrammationTache*>(listeProgrammation.at(i));
        if(progra->getTache()==ta){
            qDebug()<<"La tache est deja programmee";
            return 0;
        }
        if(listeProgrammation.at(i)->getIdentifiant()==id){
            qDebug()<<"La programmation"<<id<<"existe deja";
            return 0;
        }
    }

    ProgrammationTache* prog = new ProgrammationTache(id, dat, hd, hf, ta);
    listeProgrammation.append(prog);
    return prog;
}

void ProgrammationManager::suppProgrammation(Programmation* prog)
{

}
