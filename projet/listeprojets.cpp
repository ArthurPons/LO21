#include <QApplication>
#include "listeprojets.h"
#include "afficheprojet.h"
#include "ajouteprojet.h"

ListeProjets::ListeProjets(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Liste de projets");
    QVBoxLayout* layout = new QVBoxLayout();
    QPushButton* addPrj= new QPushButton(tr("Ajouter un projet"), this);
    ProjetManager& projm=ProjetManager::Instance();

    prj = projm.getListeProjet();
    sm=new QSignalMapper(this);

    for(int i=0;i<prj.size();i++){
        qDebug()<<prj.size();
        QString text = prj.at(i)->getTitre();
        bouton=new QPushButton(text,this);
        QObject::connect(bouton, SIGNAL(clicked()), sm, SLOT(map()));
        sm->setMapping(bouton, i);
        connect(sm, SIGNAL(mapped(int)),this, SLOT(afficherProjet(int)));
        layout->addWidget(bouton);
    }

    QObject::connect(addPrj, SIGNAL(clicked()), this, SLOT(ajouterProjet()));

    layout->addWidget(addPrj);
    this->setLayout(layout);
}

void ListeProjets::ajouterProjet()
{
    AjouteProjet* add= new AjouteProjet();
    add->setFixedWidth(300);
    add->exec();
    qDebug()<<5;
}

void ListeProjets::afficherProjet(int i)
{
    ProjetManager& projm=ProjetManager::Instance();
    prj = projm.getListeProjet();
    Projet * proj =prj.at(i);
    AfficheProjet* aff= new AfficheProjet(proj);
    aff->exec();
}
