#include "afficheprojet.h"

AfficheProjet::AfficheProjet(Projet* prj, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(prj->getTitre());
    proj = prj;
    listeTache=proj->getListeTaches();
    sm = new QSignalMapper(this);
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
       QObject::connect(supprTache, SIGNAL(clicked()), sm, SLOT(map()));
       sm->setMapping(supprTache,i);
       connect(sm, SIGNAL(mapped(int)),this, SLOT(supprimerTache(int)));
       layout->addWidget(tache);
       layout->addWidget(supprTache);
    }
    layout->addWidget(addTache);
    layout->addWidget(supprProjet);
    this->setLayout(layout);
}

void AfficheProjet::supprimerTache(int i){
    TacheUnitaire* tach=dynamic_cast<TacheUnitaire*>(listeTache.at(i));
    qDebug()<<listeTache.at(i)->getIdentifiant();
    if(tach){
        qDebug()<<tach->getIdentifiant()<<"Tache unitaire";
        proj->suppTache(tach);
    } else {
        TacheComposite* tach1=dynamic_cast<TacheComposite*>(listeTache.at(i));
        qDebug()<<tach1->getIdentifiant()<<"Tache composite";
        proj->suppTache(tach1);
    }
}

void AfficheProjet::supprimerProjet()
{
    if(!proj) qDebug() << "projet inexistant";
    ProjetManager& prjmg = ProjetManager::Instance();
    prjmg.suppProjet(proj);
    this->close();
}

void AfficheProjet::ajouteTache()
{
    /*AjouteTache* add= new AjouteTache(proj);
    add->setFixedWidth(300);
    add->exec();*/
}

AfficheProjet::~AfficheProjet(){

}
