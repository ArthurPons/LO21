#ifndef ProjetMANAGER_H
#define ProjetMANAGER_H

#include<QVector>
#include "Projet.h"

/*! \brief Classe représentant le manager de Projet.
 *
 * Le manager de Projet est unique et ne doit être instancié qu'une seule fois.
 * Il utilise donc le design pattern singleton.
 * Il y a une composition entre ProjetManager et Projet.
 * En effet, ProjetManager détermine la durée de vie d'un Projet.
 */

class ProjetManager
{
private:
    ProjetManager(); /*!<Constructeur*/
    ~ProjetManager(); /*!<Destructeur*/
    ProjetManager& operator= (const ProjetManager&){} /*!<Opérateur d'affectation*/
    ProjetManager(const ProjetManager&){} /*!<Constructeur par recopie*/
    static ProjetManager instance; /*!<Instance unique de ProjetManager*/
    QVector<Projet*> listeProjets; /*!<Vecteur de tous les Projet*/

public:
    static ProjetManager& Instance(); /*!<Instancie ProjetManager*/

    QVector<Projet*> getListeProjet()const{return listeProjets;} /*!<Renvoie un vecteur contenant tous les Projets*/

    Projet* addProjet(const QString& t, const QString& d); /*!<Créer et ajoute un Projet*/
    void suppProjet(Projet* Projet); /*!<Détruit un Projet*/
};

#endif // ProjetMANAGER_H
