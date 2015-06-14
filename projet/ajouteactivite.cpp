#include "AjouteActivite.h"

AjouteActivite::AjouteActivite(QWidget *parent) : QDialog(parent)
{
    layout= new QGridLayout();
    valider = new QPushButton(tr("Créer l'évènement"),this);
    nom = new QLineEdit();
    date = new QDateEdit(QDate::currentDate(),this);
    description= new QTextEdit();
    heureDebut = new QTimeEdit();
    heureFin = new QTimeEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom de l'évèmenement' :");
    texteDescription= new QLabel();
    texteDescription->setText("Description de l'évènement :");
    texteDate= new QLabel();
    texteDate->setText("Date :");
    texteHd= new QLabel();
    texteHd->setText("Heure de début :");
    texteHf= new QLabel();
    texteHf->setText("Heure de fin :");
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addAct()));
    layout->addWidget(texteNom, 0 ,0);
    layout->addWidget(texteDescription, 1 ,0);
    layout->addWidget(nom, 0 ,1);
    layout->addWidget(description, 1 ,1);
    layout->addWidget(texteDate, 2 ,0);
    layout->addWidget(texteHd, 3 ,0);
    layout->addWidget(texteHf, 4 ,0);
    layout->addWidget(date, 2 , 1);
    layout->addWidget(heureDebut, 3 , 1);
    layout->addWidget(heureFin, 4 , 1);
    layout->addWidget(valider, 5 , 0);
    this->setLayout(layout);

}

AjouteActivite::~AjouteActivite()
{
}

void AjouteActivite::addAct(){
    ProgrammationManager& progm=ProgrammationManager::Instance();
    int heureD = heureDebut->time().hour();
    int heureF = heureFin->time().hour();
    Programmation* proga = progm.addProgrammationActivite(nom->text(), date->date(), heureD, heureF, "Activité", description->toPlainText());
    QMessageBox::information(this,tr("Info"),tr("l'évènement a été crée"),QMessageBox::Close);
    this->close();
}
