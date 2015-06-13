#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "tache.h"

class TacheUnitaire : public Tache
{
    friend class Projet;
private:
    TacheUnitaire(const QString& id, const QString& tit,const QString& desc,
                  const int& dur, const bool& pre, Projet *p);
    TacheUnitaire(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                  const QDate& de, const int& dur, const bool& pre, Projet *p);
    virtual ~TacheUnitaire();

    int duree;
    int dureeRestante;
    bool preemptee;

public:
    int getDuree()const{return duree;}
    int getDureeRestante()const{return dureeRestante;}
    void setDureeRestante(int dur){dureeRestante=dur;}
    bool isPreemptee()const{return preemptee;}

};

#endif // TACHEUNITAIRE_H
