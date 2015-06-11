#include "eventmanager.h"

EventManager::EventManager(QWidget *parent) : QWidget(parent)
{

}

void addEvent(Event* evt){
    events.push_back(evt);
}
