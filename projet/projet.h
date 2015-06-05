#ifndef PROJET_H
#define PROJET_H

#include<QVector>
#include<QDate>
#include "tache.h"

class Projet
{
private:
    QString titre;
    QString description;
    QDate datedispo;
    QDate dateecheance;
    QVector<Tache*> listeTache;

public:
    Projet(const QString& t, const QString& d);
    Projet(const QString& t, const QString& d, const QDate& dd, const QDate& de);

    QString getTitre()const{return titre;}
    QString getDescription()const{return description;}
    //QString getDatedispo()const{return datedispo;}
    void createAddTache(const QString& id, const QString& t,const QString& d, Projet *p);
    void createAddTache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p);
    Tache *getTache(const QString& id);
};

#endif // PROJET_H
