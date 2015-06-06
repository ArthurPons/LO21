#ifndef PROJET_H
#define PROJET_H

#include<QVector>
#include<QDate>
#include "tache.h"
#include "tacheunitaire.h"

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
    //QString getDescription()const{return description;}
    //QString getDatedispo()const{return datedispo;}
    Tache* createAddTache(const QString& id, const QString& t,const QString& d);
    Tache* createAddTache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de);
    Tache* getTache(const QString& id);
};

#endif // PROJET_H
