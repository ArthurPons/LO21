#include "afficheprojet.h"

AfficheProjet::AfficheProjet(Projet* prj, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(prj->getTitre());
    proj = prj;
    listeTache=proj->getListeTaches();
    QVBoxLayout* layout = new QVBoxLayout();
    addTacheU= new QPushButton(tr("Ajouter une tâche unitaire"),this);
    addTacheC= new QPushButton(tr("Ajouter une tâche composite"),this);
    QPushButton* supprProjet= new QPushButton(tr("Supprimer le projet"),this);
    QObject::connect(supprProjet, SIGNAL(clicked()), this, SLOT(supprimerProjet()));
    QObject::connect(addTacheU, SIGNAL(clicked()), this, SLOT(ajouteTacheUnitaire()));
    QObject::connect(addTacheC, SIGNAL(clicked()), this, SLOT(ajouteTacheComposite()));
    desc = new QLabel();
    desc->setText("Nom : "+prj->getTitre()+"\nDescription : "+prj->getDescription()/*+"\nDate début : "+prj->getDateDispo()->toString()+" | Date échéance : "+prj->getDateDispo()->toString()*/);
    layout->addWidget(desc);
    QList<QPushButton*>supprTache;
    QList<QPushButton*>addPrecedence;
    QList<QPushButton*>addSousTacheU;
    QList<QPushButton*>addSousTacheC;
    QList<QPushButton*>addProg;
    int j=0;
    int k=0;
    for(int i=0; i<listeTache.size();i++){
        QSignalMapper* sm4 = new QSignalMapper(this);
        QSignalMapper* sm2 = new QSignalMapper(this);
        QSignalMapper* sm3 = new QSignalMapper(this);
        QSignalMapper* sm = new QSignalMapper(this);
        QSignalMapper* sm5 = new QSignalMapper(this);
       QHBoxLayout* layout2 = new QHBoxLayout();
       tache = new QLabel();
       tache->setText("*******************************\nTâche : "+listeTache.at(i)->getIdentifiant() +"\nDescription : "+listeTache.at(i)->getDescription());
       TacheUnitaire* tach=dynamic_cast<TacheUnitaire*>(listeTache.at(i));
       qDebug()<<listeTache.at(i)->getIdentifiant();
       addPrecedence.append(new QPushButton(tr("Ajouter précédence"),this));
       supprTache.append(new QPushButton(tr("Supprimer"),this));
       layout->addWidget(tache);
       if(tach){
           addProg.append(new QPushButton(tr("Programmer la tâche"), this));
           QObject::connect(addProg[k], SIGNAL(clicked()), sm5, SLOT(map()));
           sm5->setMapping(addProg[k],i);
           connect(sm5, SIGNAL(mapped(int)),this, SLOT(addProgTache(int)));
           qDebug()<<tach->getIdentifiant()<<"Tache unitaire";
           layout2->addWidget(addProg[k]);
           k++;
       } else {
           TacheComposite* tach1=dynamic_cast<TacheComposite*>(listeTache.at(i));
           qDebug()<<tach1->getIdentifiant()<<"Tache composite";
           addSousTacheU.append(new QPushButton(tr("Ajouter sous-tâche unitaire"), this));
           addSousTacheC.append(new QPushButton(tr("Ajouter sous-tâche composite"), this));
           QObject::connect(addSousTacheU[j], SIGNAL(clicked()), sm2, SLOT(map()));
           QObject::connect(addSousTacheC[j], SIGNAL(clicked()), sm3, SLOT(map()));
           sm2->setMapping(addSousTacheU[j],i);
           sm3->setMapping(addSousTacheC[j],i);
           connect(sm2, SIGNAL(mapped(int)),this, SLOT(addSTacheU(int)));
           connect(sm3, SIGNAL(mapped(int)),this, SLOT(addSTacheC(int)));
           layout2->addWidget(addSousTacheU[j]);
           layout2->addWidget(addSousTacheC[j]);
           j++;
       }
       QObject::connect(addPrecedence[i], SIGNAL(clicked()), sm, SLOT(map()));
       connect(sm, SIGNAL(mapped(int)),this,SLOT(addPrec(int)));
       sm->setMapping(addPrecedence[i],i);
       layout2->addWidget(addPrecedence[i]);
       QObject::connect(supprTache[i], SIGNAL(clicked()), sm4, SLOT(map()));
       connect(sm4, SIGNAL(mapped(int)),this, SLOT(supprimerTache(int)));
       sm4->setMapping(supprTache[i],i);
       layout2->addWidget(supprTache[i]);
       layout->addLayout(layout2);
    }
    QLabel* espace= new QLabel();
    espace->setText("*******************************");
    layout->addWidget(espace);
    layout->addWidget(addTacheU);
    layout->addWidget(addTacheC);
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
    this->close();
}

void AfficheProjet::addSTacheU(int i){
    TacheComposite* tacheMere=dynamic_cast<TacheComposite*>(listeTache.at(i));
    AjouteTache* add= new AjouteTache(proj, false, tacheMere);
    add->setFixedWidth(300);
    add->show();
}

void AfficheProjet::addSTacheC(int i){
    TacheComposite* tacheMere=dynamic_cast<TacheComposite*>(listeTache.at(i));
    AjouteTache* add= new AjouteTache(proj, true, tacheMere);
    add->setFixedWidth(300);
    add->show();
}

void AfficheProjet::supprimerProjet()
{
    ProjetManager& prjmg = ProjetManager::Instance();
    prjmg.suppProjet(proj);
    this->close();
}

void AfficheProjet::ajouteTacheUnitaire()
{
    AjouteTache* add= new AjouteTache(proj, false);
    add->setFixedWidth(300);
    add->show();
}

void AfficheProjet::ajouteTacheComposite()
{
    AjouteTache* add= new AjouteTache(proj, true);
    add->setFixedWidth(300);
    add->show();
}

void AfficheProjet::addPrec(int i)
{
   Tache* tach=listeTache.at(i);
   AjoutePrecedence* addPrec = new AjoutePrecedence(proj,tach);
   addPrec->exec();
}

void AfficheProjet::addProgTache(int i){
    Tache* tach=listeTache.at(i);
    AjouteProgrammationTache* addProg = new AjouteProgrammationTache(tach);
    addProg->exec();
}

AfficheProjet::~AfficheProjet(){

}
