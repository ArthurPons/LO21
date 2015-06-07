#ifndef TACHE_H
#define TACHE_H

#include<QDate>
#include<QString>
#include<QVector>

class Projet;
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
    QDate datedispo;
    QDate dateecheance;
    QVector<Tache*> precedence;
    Projet* projet;
    TacheComposite* tachemere;

public:
    Projet* getProjet() const {return projet;}
    QString getIdentifiant() const {return identifiant;}
    QString getTitre() const {return titre;}
    QString getDescription() const {return description;}
    TacheComposite* getTachemere() const {return tachemere;}
    void setTachemere(TacheComposite *mere);

};

#endif // TACHE_H
