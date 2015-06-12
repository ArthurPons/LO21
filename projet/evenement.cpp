#include "evenement.h"

Evenement::Evenement(QString tit, QDate dat, int hd, int hf, QString desc):
    titre(tit),date(dat),heureDebut(hd),heureFin(hf),description(desc)
{
    //verif();
}

/*
void Evenement::verif(){
    if(heureDebut<0)heureDebut=0;
    if(heureFin>23)heureFin=23;
}
*/
