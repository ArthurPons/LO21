#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "tache.h"

/*! \brief Classe représentant une tâche unitaire.
 *
 * Une tâche unitaire est une tâche et hérite donc de la classe tâche.
 * Une tâche unitaire possède une durée qui représente le temps de travail nécéssaire pour qu'elle soit achevée.
 * Une sous-tâche peut être unitaire ou composite.
 * Pour être finie, une tâche composite doit avoir toutes ses sous-tâches finie.
 */

class TacheUnitaire : public Tache
{
    friend class Projet;
private:
    TacheUnitaire(const QString& id, const QString& tit,const QString& desc,
                  const int& dur, const bool& pre, Projet *p); /*!<Constructeur*/
    TacheUnitaire(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                  const QDate& de, const int& dur, const bool& pre, Projet *p); /*!<Constructeur surchargé avec les dates*/
    virtual ~TacheUnitaire(); /*!<Destructeur*/

    int duree; /*!<La durée d'une tâche unitaire, en heure*/
    int dureeRestante; /*!<La durée restante d'une tâche unitaire en heure*/
    bool preemptee; /*!<Représente si une tâche unitaire est préemptée ou pas*/

public:
    int getDuree()const{return duree;}
    int getDureeRestante()const{return dureeRestante;}
    void setDureeRestante(int dur){dureeRestante=dur;}
    bool isPreemptee()const{return preemptee;}

};

#endif // TACHEUNITAIRE_H
