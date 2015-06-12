#ifndef PROJET_H
#define PROJET_H

#include<QVector>
#include<QDate>
#include "tache.h"
#include "tacheunitaire.h"
#include "tachecomposite.h"

//Composition entre projet et Tache, projet endosse le rôle d'un TacheManager

class Projet
{
    friend class ProjetManager;
private:
    QString titre;
    QString description;
    QDate datedispo;
    QDate dateecheance;
    QVector<Tache*> listeTaches;
    Projet(const QString& t, const QString& d);
    Projet(const QString& t, const QString& d, const QDate& dd, const QDate& de);
    ~Projet();

public:
    QString getTitre()const{return titre;}
    QString getDescription()const{return description;}
    QVector<Tache*> getListeTaches()const{return listeTaches;}
    QDate getDatedispo()const{return datedispo;}
    QDate getDateecheance()const{return dateecheance;}
    Tache* getTache(const QString& id);

    TacheUnitaire* addTacheUnitaire(const QString& id, const QString& tit,const QString& desc,
                                    const int dur, const bool pre);
    TacheUnitaire* addTacheUnitaire(const QString& id, const QString& tit, const QString& desc, const QDate& dd, const QDate& de,
                                    const int dur, const bool pre);
    TacheComposite* addTacheComposite(const QString &id, const QString &tit, const QString &desc);
    TacheComposite* addTacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                                      const QDate& de);
    void suppTache(TacheUnitaire* tache);
    void suppTache(TacheComposite* tache);

};

#endif // PROJET_H
