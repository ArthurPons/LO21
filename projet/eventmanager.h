#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QWidget>

class EventManager : public QDialog
{
    Q_OBJECT
public:
    explicit EventManager(QWidget *parent = 0);
    vector<Event> events;
    void addEvent(Event* evt);
    void deleteEvent(Event* evt);

signals:

public slots:
};

#endif // EVENTMANAGER_H
