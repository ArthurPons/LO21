#ifndef TACHECOMPOSITE_H
#define TACHECOMPOSITE_H

#include"tache.h"

class TacheComposite : public Tache
{
    friend class Projet;
private:
    TacheComposite(const QString& id, const QString& tit, const QString& desc, Projet *p);
    TacheComposite(const QString& id, const QString& tit, const QString& desc, const QDate& dd,
                   const QDate& de, Projet *p);
    ~TacheComposite();

    QVector<Tache*> listeSousTaches;


public:


};

#endif // TACHECOMPOSITE_H
