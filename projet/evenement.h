#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <iostream>
#include <QString>
#include <QDate>

class Evenement
{
private:
    Evenement(QString tit, QDate dat, int hd, int hf, QString desc);
    QString titre;
    QDate date;
    int heureDebut;
    int heureFin;
    QString description;

public:
    QString getTitre()const{return titre;}
    QDate getDate()const{return date;}
    int getHeureDebut()const{return heureDebut;}
    int getHeureFin()const{return heureFin;}
    QString getDescritpion()const{return description;}
};

#endif // EVENEMENT_H
