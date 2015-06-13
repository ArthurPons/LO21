#include<QDebug>
#include "TacheUnitaire.h"
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

ProgrammationTache* ProgrammationManager::addProgrammationTache(QString id, QDate dat, int hd, int hf, TacheUnitaire *ta)
{
    if(ta->isPreemptee()){
        if(!((hf-hd)>ta->getDureeRestante()))
            ta->setDureeRestante(ta->getDureeRestante()-(hf-hd));
        else{
            qDebug()<<"Problème avec les heures de debut et/ou de fin";
            return 0;
        }
    }
    else
        if(hf-hd!=ta->getDuree()){
            qDebug()<<"Problème avec les heures de debut et/ou de fin";
            return 0;
        }


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
        if(!ta->isPreemptee())
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

void ProgrammationManager::suppProgrammationTache(ProgrammationTache* prog)
{
    for(int i=0;i<listeProgrammation.size();i++){
        if(listeProgrammation.at(i)==prog)
            listeProgrammation.remove(i);
    }

    delete prog;
}
