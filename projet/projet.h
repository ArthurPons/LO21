#ifndef PROJET_H
#define PROJET_H

#include<QVector>
#include<QDate>
#include "tache.h"
#include "tacheunitaire.h"
#include "tachecomposite.h"

/*! \brief Classe représentant un Projet.
 *
 * Un Projet a pour responsabilité la durée de vie d'une Tache.
 * En effet, une Tache ne peut pas exister sans faire partie dans Projet.
 * Il y a donc une composition entre Projet et Tache.
 */

class Projet
{
    friend class ProjetManager;
private:
    Projet(const QString& t, const QString& d); /*!<Constructeur*/
    ~Projet(); /*!<Destructeur*/
    QString titre; /*!<Titre d'un Projet, il est unique*/
    QString description; /*!<Description d'un Projet*/
    QDate dateDispo; /*!<Date de disponibilité d'un Projet. Est égale à la borne inférieure des dates de disponiblités des Tache composants ce Projet.*/
    QDate dateEcheance; /*!<Date d'échéance d'un Projet. Est égale à la borne supérieure des dates d'échéance des Tache composants ce Projet.*/
    QVector<Tache*> listeTaches; /*!<Vecteur de l'ensemble des Tache composants un Projet*/

public:
    QString getTitre()const{return titre;} /*!<Renvoie le titre d'un Projet*/
    QString getDescription()const{return description;} /*!<Renvoie la description d'un Projet*/
    QVector<Tache*> getListeTaches()const{return listeTaches;} /*!<Renvoie le vecteur de Tache composants un Projet*/
    QDate getDateDispo()const{return dateDispo;} /*!<Renvoie la date de disponiblité d'un Projet*/
    QDate getDateEcheance()const{return dateEcheance;} /*!<Renvoie la date d'échéance d'un Projet*/
    Tache* getTache(const QString& id); /*!<Renvoie un pointeur vers la Tache identifiée par l'argument si celle-ci est dans le Projet*/

    TacheUnitaire* addTacheUnitaire(const QString& id, const QString& tit,const QString& desc,
                                    const int dur, const bool pre); /*!<Créer puis ajoute une TacheUnitaire au projet*/
    TacheUnitaire* addTacheUnitaire(const QString& id, const QString& tit, const QString& desc, const QDate& dd, const QDate& de,
                                    const int dur, const bool pre); /*!<Créer puis ajoute une TacheUnitaire au projet. Surchargée avec les dates*/
    TacheComposite* addTacheComposite(const QString &id, const QString &tit, const QString &desc); /*!<Créer puis ajoute une TacheComposite au projet*/
    TacheComposite* addTacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                                      const QDate& de); /*!<Créer puis ajoute une TacheComposite au projet. Surchargée avec les dates*/
    void suppTache(TacheUnitaire* tache); /*!<Supprime la TacheUnitaire passée en argument*/
    void suppTache(TacheComposite* tache); /*!<Supprime la TacheComposite passée en argument*/
};

#endif // PROJET_H
