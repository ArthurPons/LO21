#include "AjouteProjet.h"

AjouteProjet::AjouteProjet(QWidget *parent) : QDialog(parent)
{
    layout= new QGridLayout();
    valider = new QPushButton(tr("Créer l'évènement"),this);
    nom = new QLineEdit();
    description= new QTextEdit();
    sm = new QSignalMapper(this);
    texteNom= new QLabel();
    texteNom->setText("Nom du projet :");
    texteDescription= new QLabel();
    texteDescription->setText("Description du projet :");
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addPrj()));
    //sm->setMapping(valider,nom->toPlainText(),description->toPlainText());
    //connect(sm, SIGNAL(mapped(QString,QString)),this, SLOT(afficherProjet(QString, QString)));
    layout->addWidget(texteNom, 0 ,0);
    layout->addWidget(texteDescription, 1 ,0);
    layout->addWidget(nom, 0 ,1);
    layout->addWidget(description, 1 ,1);
    layout->addWidget(valider, 2 , 0);
    this->setLayout(layout);

}

AjouteProjet::~AjouteProjet()
{
}

void AjouteProjet::addPrj(){
    ProjetManager& projm=ProjetManager::Instance();
    Projet* prj=projm.addProjet(nom->text(),description->toPlainText());
    this->close();
}

void AjouteProjet::addTache(){

}
