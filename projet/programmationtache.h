#ifndef ProgrammationTache_H
#define ProgrammationTache_H

#include "programmation.h"

/*! \brief Classe représentant une ProgrammationTache.
 *
 * Une ProgrammationTache est un événement et donc une Programmation.
 * ProgrammationTache hérite donc de Programmation.
 * Elle est la programmation d'une Tache donnée.
 */

class ProgrammationTache : public Programmation
{
    friend class ProgrammationManager;
private:
    ProgrammationTache(QString id, QDate dat, int hd, int hf, TacheUnitaire *ta); /*!<Constructeur*/
    virtual ~ProgrammationTache(); /*!<Destructeur*/

    TacheUnitaire* tache; /*!<Tache programmée par une ProgrammationTache*/

public:
    TacheUnitaire* getTache()const{return tache;} /*!<Renvoie la Tache programmée par une ProgrammationTache*/
};

#endif // ProgrammationTache_H
