#ifndef TACHE_H
#define TACHE_H

#include<QDate>
#include<QString>
#include<QVector>

class Projet;
class TacheUnitaire;
class TacheComposite;

/*! \brief Classe représentant une Tache
 *
 * Une Tache est forcément associée à un Projet.
 */

class Tache
{
    friend class Projet;
private:

protected:
    Tache(const QString& id, const QString& t,const QString& d, Projet *p); /*!<Constructeur*/
    Tache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p); /*<Constructeur surchargé avec les dates*/
    virtual ~Tache(); /*!<Destructeur*/

    bool checkPrecedence(Tache* precedence); /*!<Vérifie si la Tache passée en argument peut précéder une autre Tache*/
    void suppPrecedence(Tache* precedence); /*!<Supprime la Tache passée en argument comme précédence d'une autre Tache*/

    QString identifiant; /*!< Identifiant d'une Tache. Il est unique au sein d'un même Projet. */
    QString titre; /*!< Titre d'une Tache. */
    QString description; /*!<Description d'une Tache */
    QDate dateDispo; /*!<Date de disponibilité d'une Tache. Une Tache ne peut être commencé que lorsque sa date de disponibilité est passée. */
    QDate dateEcheance; /*!<Date d'échéance d'une Tache. Une Tache doit être terminée avant sa date d'échéance. */
    QVector<Tache*> listeTachesMeresPrecedence; /*!<Vecteur des Taches précédant une Tache. */
    TacheComposite* tacheMereComposite; /*!<Pointe vers une Tache dont une autre est composition. Une Tache ne peut composer qu'en seule autre Tache. */
    Projet* projet; /*!<Pointe vers le Projet dont une Tache fait partie.*/

public:
    Projet* getProjet() const {return projet;} /*!<Retourne le Projet d'une Tache.*/
    QString getIdentifiant() const {return identifiant;} /*!<Retourne l'identifiant d'une Tache.*/
    QString getTitre() const {return titre;} /*!<Retourne le titre d'une Tache.*/
    QString getDescription() const {return description;} /*!<Retourne la description d'une Tache.*/
    QDate getDateDispo() const {return dateDispo;} /*!<Retourne ldate de disponibilité d'une Tache.*/
    QDate getDateEcheance() const {return dateEcheance;} /*!<Retourne la date d'échéance d'une Tache.*/
    TacheComposite* getTacheMereComposite() const {return tacheMereComposite;} /*!<Retourne la Tache dont une Tache est composition.*/
    QVector<Tache*> getListeTachesMeresPrecedence() const {return listeTachesMeresPrecedence;} /*!<Retourne un vecteur de Tache précédant une autre Tache.*/
    void setTacheMereComposite(TacheComposite* mere); /*!<Affecte une Tache en tant que Tache dont une autre Tache est composition.*/
    void addPrecedence(Tache* precedence); /*!<Ajoute une Tache comme précédence d'une autre Tache.*/
};

#endif // TACHE_H
