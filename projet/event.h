#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <QString>
#include <QDate>

class Event
{
public:
    Event(QString n, QDate d, int hd, int hf, QString desc);
    QString nom;
    QDate date;
    int heureDebut;
    int heureFin;
    QString description;
    void verif();
};

#endif // EVENT_H
