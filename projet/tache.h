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
private:
    // Rajouter constructeur par recopie et opérateur =

protected:
    Tache(const QString& id, const QString& t,const QString& d, Projet *p);
    Tache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p);
    virtual ~Tache()=0;

    QString identifiant;
    QString titre;
    QString description;
    QDate dateDispo;
    QDate dateEcheance;
    QVector<Tache*> listeTachesMeresPrecedence;
    QVector<Tache*> listeTachesFillesPrecedence;
    Projet* projet;
    TacheComposite* tacheMereComposite;

public:
    Projet* getProjet() const {return projet;}
    QString getIdentifiant() const {return identifiant;}
    QString getTitre() const {return titre;}
    QString getDescription() const {return description;}
    TacheComposite* getTacheMereComposite() const {return tacheMereComposite;}
    QVector<Tache*> getListeTachesMeresPrecedence() const {return listeTachesMeresPrecedence;}
    QVector<Tache*> getListeTachesFillesPrecedence() const {return listeTachesFillesPrecedence;}
    void setTacheMereComposite(TacheComposite* mere);

    bool checkPrecedence(Tache* precedence);
    void addPrecedence(Tache* precedence);
};

#endif // TACHE_H
