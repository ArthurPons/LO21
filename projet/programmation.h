#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QDate>
#include<QString>
#include "tache.h"

class ProgrammationManager;
class ProgrammationTache;

/*! \brief Classe représentant une Programmation.
 *
 * Une Programmation est un événement.
 * Elle peut être soit une ProgrammationTache soit une ProgrammationActivite.
 */

class Programmation
{
    friend class ProgrammationManager;
protected:
    Programmation(QString id, QDate dat, int hd, int hf); /*!<Constructeur*/
    virtual ~Programmation(); /*!<Destructeur*/

    QString identifiant; /*!<Identifiant d'une Programmation. Il est unique*/
    QDate date; /*!<Date d'une programmation au format yyyy-mm-dd*/
    int heureDebut; /*!<Heure de début d'une Programmation*/
    int heureFin; /*!<Heure de fin d'une Programmation*/


public:
    QString getIdentifiant() const {return identifiant;} /*!<Retourne l'identifiant d'une Programmation*/
    QDate getDate() const {return date;} /*!<Retourne la date d'une Programmation*/
    int getHeureDebut() const {return heureDebut;} /*!<Retourne l'heure de début d'une Programmation*/
    int getHeureFin() const {return heureFin;} /*!<Retourne l'ehure de fin d'une Programmation*/

};

#endif // PROGRAMMATION_H
