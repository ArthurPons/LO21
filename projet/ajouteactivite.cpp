#include "AjouteActivite.h"

AjouteActivite::AjouteActivite(Interface* inter, QWidget *parent) : QDialog(parent)
{

    Interface* f=inter;
    layout= new QGridLayout();
    valider = new QPushButton(tr("Créer l'évènement"),this);
    nom = new QLineEdit();
    date = new QDateEdit(QDate::currentDate(),this);
    description= new QTextEdit();
    heureDebut = new QTimeEdit();
    heureFin = new QTimeEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom de l'évènement :");
    texteDescription= new QLabel();
    texteDescription->setText("Description de l'évènement :");
    texteDate= new QLabel();
    texteDate->setText("Date :");
    texteHd= new QLabel();
    texteHd->setText("Heure de début :");
    texteHf= new QLabel();
    texteHf->setText("Heure de fin :");
    hmin=QTime::fromString("8.00", "h.mm");
    hmax=QTime::fromString("9.00", "h.mm");
    hmin2=QTime::fromString("18.00", "hh.mm");
    hmax2=QTime::fromString("19.00", "hh.mm");
    heureDebut->setMinimumTime(hmin);
    heureFin->setMinimumTime(hmax);
    heureDebut->setMaximumTime(hmin2);
    heureFin->setMaximumTime(hmax2);
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
    f->mettreAJour();
    this->close();
}
