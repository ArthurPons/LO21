#ifndef PROJETMANAGER_H
#define PROJETMANAGER_H

#include<QVector>
#include "projet.h"

/*! \brief Classe représentant le manager de projet.
 *
 * Le manager de projet est unique et ne doit être instancié qu'une seule fois.
 * Il utilise donc le design pattern singleton.
 * Il y a une composition entre ProjetManager et Projet.
 * En effet, ProjetManager détermine la durée de vie d'un Projet.
 */

class ProjetManager
{
private:
    ProjetManager(); /*!<Constructeur*/
    ~ProjetManager(); /*!<Destructeur*/
    ProjetManager& operator= (const ProjetManager&){} /*!<Opérateur de recopie*/
    ProjetManager(const ProjetManager&){} /*!<Constructeur par recopie*/
    static ProjetManager instance; /*!<Instance unique de ProjetManager*/
    QVector<Projet*> listeProjets; /*!<Vecteur de tous les Projet*/

public:
    static ProjetManager& Instance(); /*!<Instancie ProjetManager*/

    QVector<Projet*> getListeProjet()const{return listeProjets;} /*!<Renvoie un vecteur contenant tous les projets*/

    Projet* addProjet(const QString& t, const QString& d); /*!<Créer et ajoute un Projet*/
    void suppProjet(Projet* projet); /*!<Détruit un Projet*/
};

#endif // PROJETMANAGER_H
