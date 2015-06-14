#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include<QVector>
#include "programmation.h"
#include "programmationtache.h"
#include "programmationactivite.h"

/*! \brief Classe représentant le manager de Programmation.
 *
 * Le manager de Programmation est unique et ne doit être instancié qu'une seule fois.
 * Il utilise donc le design pattern singleton.
 * Il y a une composition entre ProgrammationManager et Programmation.
 * En effet, ProgrammationManager détermine la durée de vie d'un Programmation.
 */

class ProgrammationManager
{
private:
    ProgrammationManager(); /*!<Constructeur*/
    ~ProgrammationManager(); /*!<Destructeur*/
    ProgrammationManager& operator= (const ProgrammationManager&){} /*!<Opérateur d'affectation*/
    ProgrammationManager(const ProgrammationManager&){} /*!<Constructeur par recopie*/
    static ProgrammationManager instance; /*!<Instance unique de ProgrammationManager*/
    QVector<Programmation*> listeProgrammation; /*!<Vecteur de l'ensemble des Programmation*/

public:
    static ProgrammationManager& Instance(); /*!<Instancie ProgrammationManager*/

    QVector<Programmation*> getListeProgrammation()const{return listeProgrammation;} /*!<Renvoie le vecteur de l'ensemble des Programmation*/

    ProgrammationTache* addProgrammationTache(QString id, QDate dat, int hd, int hf, TacheUnitaire *ta); /*!<Créer et ajoute une ProgrammationTache*/
    ProgrammationActivite* addProgrammationActivite(QString id, QDate dat, int hd, int hf, QString tit, QString desc); /*!<Créer et ajoute une ProgrammationActivite*/
    void suppProgrammationTache(ProgrammationTache *prog); /*!<Supprime une ProgrammationTache*/
    void suppProgrammationActivite(ProgrammationActivite* prog); /*!<Supprime une ProgrammationActivite*/
};

#endif // PROGRAMMATIONMANAGER_H
