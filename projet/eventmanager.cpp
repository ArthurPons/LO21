#include "eventmanager.h"

EventManager::EventManager()
{

}

void EventManager::addEvent(Event* evt){
    events.push_back(evt);
}
