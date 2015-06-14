#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

#include"tache.h"

/*! \brief Classe représentant une tâche composite.
 *
 * Une tâche composite est une tâche et hérite donc de la classe tâche.
 * Une tâche composite peut être composée de sous tâches.
 * Une sous tâche peut être unitaire ou composite.
 * Pour être finie, une tâche composite doit avoir toutes ses sous-tâches finie.
 */

class TacheComposite : public Tache
{
    friend class Projet;
private:
    TacheComposite(const QString& id, const QString& tit, const QString& desc, Projet *p); /*!<Constructeur*/
    TacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd, /*!<Constructeur surchargé avec les dates*/
                   const QDate& de, Projet *p);
    virtual ~TacheComposite(); /*!<Destructeur*/

    QVector<Tache*> listeSousTaches; /*!<Vecteur des tâches composant une tâche composite*/


public:
    void addSousTache(Tache *tache); /*!<Ajoute une tâche en tant que sous tâche d'une tâche composite*/
    QVector<Tache*> getListeSousTaches() const {return listeSousTaches;} /*!<Retourne un vecteur contenant les sous tâches d'une tâche composite*/

};

#endif // TACHECOMPOSITE_H
