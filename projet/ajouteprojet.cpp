#include "AjouteProjet.h"

AjouteProjet::AjouteProjet(QWidget *parent) : QDialog(parent)
{
    layout= new QGridLayout();
    valider = new QPushButton(tr("Créer le projet"),this);
    nom = new QLineEdit();
    description= new QTextEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom du projet :");
    texteDescription= new QLabel();
    texteDescription->setText("Description du projet :");
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addPrj()));
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
    QMessageBox::information(this,tr("Info"),tr("le projet a été crée"),QMessageBox::Close);
    this->close();
}

void AjouteProjet::addTache(){

}
