#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include<QVector>
#include "projet.h"

class ProjetManager
{
private:
    ProjetManager();
    ~ProjetManager();
    ProjetManager& operator= (const ProjetManager&){}
    ProjetManager(const ProjetManager&){}
    static ProjetManager instance;
    QVector<Projet*> listeProjets;

public:
    Projet* createProjet(const QString& t, const QString& d);
    Projet* createProjet(const QString& t, const QString& d, const QDate& dd, const QDate& de);
    static ProjetManager& Instance();

};

#endif // PROJETMANAGER_H
