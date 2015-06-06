#include<QDebug>
#include "projetmanager.h"
#include "projet.h"

ProjetManager ProjetManager::instance=ProjetManager();

ProjetManager::ProjetManager()
{
    qDebug()<<"Creation de ProjetManager";
}

ProjetManager::~ProjetManager()
{
    qDebug()<<"Destruction de ProjetManager";
}

ProjetManager& ProjetManager::Instance()
{
    return instance;
}

Projet* ProjetManager::createProjet(const QString& t, const QString& d)
{
    Projet* projet;
    projet = new Projet(t, d);

    int n=listeProjets.size();
    for(int i=0;i<n;i++)
        if(projet->getTitre()==listeProjets.at(i)->getTitre()){
            qDebug()<<"Le projet"<<t<<"existe deja";
            delete projet;
            return 0;
        }
    listeProjets.append(projet);
    qDebug()<<"Projet"<<t<<"ajoutee";
    return projet;
}

Projet* ProjetManager::createProjet(const QString& t, const QString& d, const QDate& dd, const QDate& de)
{
    Projet* projet;
    projet = new Projet(t, d, dd, de);;

    int n=listeProjets.size();
    for(int i=0;i<n;i++)
        if(projet->getTitre()==listeProjets.at(i)->getTitre()){
            qDebug()<<"Le projet"<<t<<"existe deja";
            delete projet;
            return 0;
        }
    listeProjets.append(projet);
    qDebug()<<"Projet"<<t<<"ajoutee";
    return projet;
}
