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
    qDebug()<<"Prog"<<id;

    if(!ta->getDateDispo().isNull() && !ta->getDateEcheance().isNull())
        if(ta->getDateDispo()>dat || dat>ta->getDateEcheance()){
            qDebug()<<"Programmation impossible, les dates ne concordent pas";
            return 0;
        }

    if(dat<QDate::currentDate()){
        qDebug()<<"Impossible de programmer une tache dans la passe";
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
        if(listeProgrammation.at(i)->getDate()==dat && (listeProgrammation.at(i)->getHeureDebut()==hd ||
                                                        listeProgrammation.at(i)->getHeureFin()==hf ||
                                                        (listeProgrammation.at(i)->getHeureDebut()<hd &&
                                                         listeProgrammation.at(i)->getHeureFin()>hf))){
            qDebug()<<"Le creneau horaire est deja pris";
            return 0;
        }
    }

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

    ProgrammationTache* prog = new ProgrammationTache(id, dat, hd, hf, ta);
    listeProgrammation.append(prog);
    return prog;
}

ProgrammationActivite* ProgrammationManager::addProgrammationActivite(QString id, QDate dat, int hd, int hf, QString tit, QString desc)
{
    qDebug()<<"Prog"<<id;

    if(hd>hf || hd<0 || hd>23 || hf<1 || hf>24 || hf==hd){
        qDebug()<<"Problème avec les heures de debut et/ou de fin";
        return 0;
    }

    if(dat<QDate::currentDate()){
        qDebug()<<"Impossible de programmer une activite dans la passe";
        return 0;
    }

    for(int i=0;i<listeProgrammation.size();i++){
        if(listeProgrammation.at(i)->getIdentifiant()==id){
            qDebug()<<"La programmation"<<id<<"existe deja";
            return 0;
        }
        if(listeProgrammation.at(i)->getDate()==dat && (listeProgrammation.at(i)->getHeureDebut()==hd ||
                                                        listeProgrammation.at(i)->getHeureFin()==hf ||
                                                        (listeProgrammation.at(i)->getHeureDebut()<hd &&
                                                         listeProgrammation.at(i)->getHeureFin()>hf))){
            qDebug()<<"Le creneau horaire est deja pris";
            return 0;
        }
    }

    ProgrammationActivite* prog = new ProgrammationActivite(id, dat, hd, hf, tit, desc);
    listeProgrammation.append(prog);
    return prog;

}

void ProgrammationManager::suppProgrammationTache(ProgrammationTache* prog)
{
    for(int i=0;i<listeProgrammation.size();i++){
        if(listeProgrammation.at(i)==prog)
            listeProgrammation.remove(i);
    }

    if(prog->getTache()->isPreemptee()){
        prog->getTache()->setDureeRestante(prog->getTache()->getDureeRestante()+(prog->getHeureFin()-prog->getHeureDebut()));
    }

    delete prog;
}

void ProgrammationManager::suppProgrammationActivite(ProgrammationActivite* prog)
{
    for(int i=0;i<listeProgrammation.size();i++){
        if(listeProgrammation.at(i)==prog)
            listeProgrammation.remove(i);
    }

    delete prog;
}


