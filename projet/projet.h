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
    QDate dateDispo;
    QDate dateEcheance;
    QVector<Tache*> listeTaches;
    Projet(const QString& t, const QString& d);
    ~Projet();

public:
    QString getTitre()const{return titre;}
    QString getDescription()const{return description;}
    QVector<Tache*> getListeTaches()const{return listeTaches;}
    QDate getDateDispo()const{return dateDispo;}
    QDate getDateEcheance()const{return dateEcheance;}
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
