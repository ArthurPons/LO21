#ifndef TACHE_H
#define TACHE_H

#include<QString>
#include<QVector>
#include "tache.cpp"

class Tache
{
protected:
    QString titre;
    QString description;
    QVector<Tache*> precedence;

public:
    Tache(QString t,QString d);
    //~Tache();
    QString getTitre() const {return titre;}
    QString getDescription() const {return description;}
};

#endif // TACHE_H
