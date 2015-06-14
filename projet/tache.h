#ifndef TACHE_H
#define TACHE_H

#include<QDate>
#include<QString>
#include<QVector>

class Projet;
class TacheUnitaire;
class TacheComposite;

/*! \brief Classe représentant une tâche
 *
 * Une tâche est forcément associée à un Projet.
 */

class Tache
{
    friend class Projet;
private:

protected:
    Tache(const QString& id, const QString& t,const QString& d, Projet *p); /*!<Constructeur*/
    Tache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p); /*<Constructeur surchargé avec les dates*/
    virtual ~Tache(); /*!<Destructeur*/

    bool checkPrecedence(Tache* precedence); /*!<Vérifie si la tâche passée en argument peut précéder une autre tâche*/
    void suppPrecedence(Tache* precedence); /*!<Supprime la tâche passée en argument comme précédence d'une autre tâche*/

    QString identifiant; /*!< Identifiant d'une tâche. Il est unique au sein d'un même projet. */
    QString titre; /*!< Titre d'une tâche. */
    QString description; /*!<Description d'une tâche */
    QDate dateDispo; /*!<Date de disponibilité d'une tâche. Une tâche ne peut être commencé que lorsque sa date de disponibilité est passée. */
    QDate dateEcheance; /*!<Date d'échéance d'une tâche. Une tâche doit être terminée avant sa date d'échéance. */
    QVector<Tache*> listeTachesMeresPrecedence; /*!<Vecteur des tâches précédant une tâche. */
    TacheComposite* tacheMereComposite; /*!<Pointe vers une tâche dont une autre est composition. Une tâche ne peut composer qu'en seule autre tâche. */
    Projet* projet; /*!<Pointe vers le projet dont une tâche fait partie.*/

public:
    Projet* getProjet() const {return projet;} /*!<Retourne le projet d'une tâche.*/
    QString getIdentifiant() const {return identifiant;} /*!<Retourne l'identifiant d'une tâche.*/
    QString getTitre() const {return titre;} /*!<Retourne le titre d'une tâche.*/
    QString getDescription() const {return description;} /*!<Retourne la description d'une tâche.*/
    QDate getDateDispo() const {return dateDispo;} /*!<Retourne ldate de disponibilité d'une tâche.*/
    QDate getDateEcheance() const {return dateEcheance;} /*!<Retourne la date d'échéance d'une tâche.*/
    TacheComposite* getTacheMereComposite() const {return tacheMereComposite;} /*!<Retourne la tâche dont une tâche est composition.*/
    QVector<Tache*> getListeTachesMeresPrecedence() const {return listeTachesMeresPrecedence;} /*!<Retourne un vecteur de tâche précédant une autre tâche.*/
    void setTacheMereComposite(TacheComposite* mere); /*!<Affecte une tâche en tant que tâche dont une autre tâche est composition.*/
    void addPrecedence(Tache* precedence); /*!<Ajoute une tâche comme précédence d'une autre tâche.*/
};

#endif // TACHE_H
