#ifndef TACHE_H
#define TACHE_H

#include<QDate>
#include<QString>
#include<QVector>

class Projet;

class Tache
{
    friend class Projet;
private:
    Tache(const QString& id, const QString& t,const QString& d, Projet *p);
    Tache(const QString& id, const QString& t, const QString& d, const QDate& dd, const QDate& de, Projet *p);
    ~Tache();
    // Rajouter constructeur par recopie et opérateur =

protected:
    QString identifiant;
    QString titre;
    QString description;
    QDate datedispo;
    QDate dateecheance;
    QVector<Tache*> precedence;
    Projet* projet;

public:
    Projet* getProjet() const {return projet;}
    QString getIdentifiant() const {return identifiant;}
    QString getTitre() const {return titre;}
    QString getDescription() const {return description;}
};

#endif // TACHE_H
