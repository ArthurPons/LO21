#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>
#include <QVector>
#include <QDialog>

class Event;

class EventManager
{
public:
    EventManager();
    QVector<Event*> events;
    void addEvent(Event* evt);
    void deleteEvent(Event* evt);

signals:

public slots:
};

#endif // EVENTMANAGER_H
