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
    for(int i=0;i<listeProjets.size();i++){
        suppProjet(listeProjets.at(i));
    }
}

ProjetManager& ProjetManager::Instance()
{
    return instance;
}

Projet* ProjetManager::addProjet(const QString& t, const QString& d)
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

void ProjetManager::suppProjet(Projet* projet)
{
    while(!projet->getListeTaches().empty()){
        TacheUnitaire* tache=dynamic_cast<TacheUnitaire*>(projet->getListeTaches().at(0));
        qDebug()<<projet->getListeTaches().at(0)->getIdentifiant();
        if(tache){
            qDebug()<<tache->getIdentifiant()<<"Tache unitaire";
            projet->suppTache(tache);
        } else {
            TacheComposite* tache1=dynamic_cast<TacheComposite*>(projet->getListeTaches().at(0));
            qDebug()<<tache1->getIdentifiant()<<"Tache composite";
            projet->suppTache(tache1);
        }
    }

    for(int i=0;i<listeProjets.size();i++)
        if(listeProjets.at(i)==projet)
            listeProjets.remove(i);

    delete projet;
}

