#ifndef PROGRAMMATIONACTIVITE_H
#define PROGRAMMATIONACTIVITE_H

#include "programmation.h"

/*! \brief Classe représentant une ProgrammationActivite.
 *
 * Une ProgrammationActivite est un événement et donc une Programmation.
 * ProgrammationActivite hérite donc de Programmation.
 * Elle est la programmation d'une activité donnée.
 */

class ProgrammationActivite : public Programmation
{
    friend class ProgrammationManager;
private:
    ProgrammationActivite(const QString& id, const QDate& dat, const int& hd,
                          const int& hf, const QString& tit, const QString& desc); /*!<Constructeur*/
    virtual ~ProgrammationActivite(); /*!<Destructeur*/

   QString titre; /*!<Titre de l'activite programmée*/
   QString description; /*!<Description de l'activité programmée*/

public:
    QString getTitre()const{return titre;} /*!<Retourne le titre de l'activité programmée*/
    QString getDescription()const{return description;} /*!<Retourne la description de l'activité programmée*/
};


#endif // PROGRAMMATIONACTIVITE_H
