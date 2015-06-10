#ifndef TACHE_H
#define TACHE_H

#include<QDate>
#include<QString>
#include<QVector>

class Projet;
class TacheUnitaire;
class TacheComposite;

class Tache
{
    friend class Projet;
private:
    // Rajouter constructeur par recopie et opérateur =

protected:
    Tache(const QString& id, const QString& t,const QString& d, Projet *p);
    Tache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p);
    virtual ~Tache();

    bool checkPrecedence(Tache* precedence);
    void suppPrecedence(Tache* precedence);

    QString identifiant;
    QString titre;
    QString description;
    QDate dateDispo;
    QDate dateEcheance;
    QVector<Tache*> listeTachesMeresPrecedence;
    Projet* projet;
    TacheComposite* tacheMereComposite;

public:
    Projet* getProjet() const {return projet;}
    QString getIdentifiant() const {return identifiant;}
    QString getTitre() const {return titre;}
    QString getDescription() const {return description;}
    QDate getDateDispo() const {return dateDispo;}
    QDate getDateEcheance() const {return dateEcheance;}
    TacheComposite* getTacheMereComposite() const {return tacheMereComposite;}
    QVector<Tache*> getListeTachesMeresPrecedence() const {return listeTachesMeresPrecedence;}
    void setTacheMereComposite(TacheComposite* mere);
    void addPrecedence(Tache* precedence);
};

#endif // TACHE_H
