#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include<QVector>
#include "projet.h"

//Composition entre ProjetManager et Projet
//Design Pattern Singleton

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
    static ProjetManager& Instance();

    Projet* addProjet(const QString& t, const QString& d);
    void suppProjet(Projet* projet);
};

#endif // PROJETMANAGER_H
