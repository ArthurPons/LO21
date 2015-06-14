#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

#include"tache.h"

/*! \brief Classe représentant une TacheComposite.
 *
 * Une TacheComposite est une Tache et hérite donc de la classe Tache.
 * Une TacheComposite peut être composée de sous-Taches.
 * Une sous-Tache peut être une TacheUnitaire ou TacheComposite.
 * Pour être finie, une TacheComposite doit avoir toutes ses sous-Taches finie.
 */

class TacheComposite : public Tache
{
    friend class Projet;
private:
    TacheComposite(const QString& id, const QString& tit, const QString& desc, Projet *p); /*!<Constructeur*/
    TacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd, /*!<Constructeur surchargé avec les dates*/
                   const QDate& de, Projet *p);
    virtual ~TacheComposite(); /*!<Destructeur*/

    QVector<Tache*> listeSousTaches; /*!<Vecteur des Tache composant une TacheComposite*/


public:
    void addSousTache(Tache *tache); /*!<Ajoute une Tache en tant que sous-tache d'une TacheComposite*/
    QVector<Tache*> getListeSousTaches() const {return listeSousTaches;} /*!<Retourne un vecteur contenant les sous-taches d'une TacheComposite*/

};

#endif // TACHECOMPOSITE_H
