#include "event.h"

Event::Event(QString n, QDate d, int hd, int hf, QString desc):nom(n),date(d),heureDebut(hd),heureFin(hf),description(desc){
    verif();
}

void Event::verif(){
    if(heureDebut<0)heureDebut=0;
    if(heureFin>23)heureFin=23;
}

