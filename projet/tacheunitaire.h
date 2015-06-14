#ifndef TACHEUNITAIRE_H
#define TACHEUNITAIRE_H

#include "tache.h"

/*! \brief Classe représentant une TacheUnitaire.
 *
 * Une TacheUnitaire est une Tache et hérite donc de la classe Tache.
 * Une TacheUnitaire possède une durée qui représente le temps de travail nécéssaire pour qu'elle soit achevée.
 * Une TacheUnitaire peut être préemptée.
 * Une TacheUnitaire préemptée peut être programmée plusieurs fois.
 * Pour être finie, une TacheUnitaire doit avoir été programmée pour aussi longtemps que sa durée.
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

    int duree; /*!<La durée d'une TacheUnitaire, en heure*/
    int dureeRestante; /*!<La durée restante d'une TacheUnitaire en heure*/
    bool preemptee; /*!<Représente si une TacheUnitaire est préemptée ou pas*/

public:
    int getDuree()const{return duree;} /*!<Renvoie la durée d'une TacheUnitaire*/
    int getDureeRestante()const{return dureeRestante;} /*!<Renvoie la durée restante d'une TacheUnitaire*/
    void setDureeRestante(int dur){dureeRestante=dur;} /*!<Affecte l'argument à la durée restante d'une TacheUnitaire*/
    bool isPreemptee()const{return preemptee;} /*!<Renvoie si une TacheUnitaire est préemptée ou pas*/
};

#endif // TACHEUNITAIRE_H
