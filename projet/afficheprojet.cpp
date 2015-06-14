#include "afficheprojet.h"

AfficheProjet::AfficheProjet(Projet* prj, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(prj->getTitre());
    Projet* proj = prj;
    listeTache=proj->getListeTaches();
    QVBoxLayout* layout = new QVBoxLayout();
    QPushButton* addTache= new QPushButton(tr("Ajouter une tâche"),this);
    QPushButton* supprProjet= new QPushButton(tr("Supprimer le projet"),this);
    QObject::connect(addTache, SIGNAL(clicked()), this, SLOT(ajouteTache()));
    QObject::connect(supprProjet, SIGNAL(clicked()), this, SLOT(supprimerProjet()));
    desc = new QLabel();
    desc->setText("Nom : "+prj->getTitre()+"\nDescription : "+prj->getDescription()/*+"\nDate début : "+prj->getDateDispo()->toString()+" | Date échéance : "+prj->getDateDispo()->toString()*/);
    layout->addWidget(desc);
    for(int i=0; i<listeTache.size();i++){
       tache = new QLabel();
       tache->setText("*******************************\nTâche : "+listeTache.at(i)->getIdentifiant() +"\nDescription : "+listeTache.at(i)->getDescription());
       QPushButton* supprTache= new QPushButton(tr("Supprimer"),this);
       QObject::connect(supprTache, SIGNAL(clicked()), this, SLOT(supprimerTache())); //faudra sûrement faire un signal mapper
       layout->addWidget(tache);
       layout->addWidget(supprTache);
    }
    layout->addWidget(addTache);
    layout->addWidget(supprProjet);
    this->setLayout(layout);
}

void AfficheProjet::supprimerTache(int i){
}

void AfficheProjet::supprimerProjet()
{
    ProjetManager& prjmg = ProjetManager::Instance();
    prjmg.suppProjet(proj);
    this->close();
}

void AfficheProjet::ajouteTache()
{
    /*AjouteTache* add= new AjouteTache(proj);
    add->setFixedWidth(300);
    add->show();*/
}

AfficheProjet::~AfficheProjet(){

}
