#include "AjouteProgrammationTache.h"

AjouteProgrammationTache::AjouteProgrammationTache(Tache* tache, QWidget *parent) : QDialog(parent)
{

    t=tache;
    layout= new QGridLayout();
    valider = new QPushButton(tr("Programmer la tâche"),this);
    date = new QDateEdit(QDate::currentDate(),this);
    heureDebut = new QTimeEdit();
    heureFin = new QTimeEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom de la tâche : "+t->getIdentifiant());
    texteDescription= new QLabel();
    texteDescription->setText("Description de la tâche : "+t->getDescription());
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
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addProgTache()));
    layout->addWidget(texteNom, 0 ,0);
    layout->addWidget(texteDescription, 1 ,0);
    layout->addWidget(texteDate, 2 ,0);
    layout->addWidget(texteHd, 3 ,0);
    layout->addWidget(texteHf, 4 ,0);
    layout->addWidget(date, 2 , 1);
    layout->addWidget(heureDebut, 3 , 1);
    layout->addWidget(heureFin, 4 , 1);
    layout->addWidget(valider, 5 , 0);
    this->setLayout(layout);

}

AjouteProgrammationTache::~AjouteProgrammationTache()
{
}

void AjouteProgrammationTache::addProgTache(){
    ProgrammationManager& progm=ProgrammationManager::Instance();
    TacheUnitaire* tach=dynamic_cast<TacheUnitaire*>(t);
    int heureD = heureDebut->time().hour();
    int heureF = heureFin->time().hour();
    Programmation* progt = progm.addProgrammationTache(t->getIdentifiant(), date->date(), heureD, heureF, tach);
    this->close();
}
