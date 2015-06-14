#include "AjouteTache.h"

AjouteTache::AjouteTache(Projet * proj, bool typ, QWidget *parent) : QDialog(parent)
{
    prj = proj;
    layout= new QGridLayout();
    type = typ;
    valider = new QPushButton(tr("Ajouter la tâche au projet"),this);
    nom = new QLineEdit();
    description= new QTextEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom de la tâche :");
    texteDescription= new QLabel();
    texteDescription->setText("Description de la tâche :");
    int nb=0;
    layout->addWidget(texteNom, 0 ,0);
    layout->addWidget(texteDescription, 1 ,0);
    layout->addWidget(nom, 0 ,1);
    layout->addWidget(description, 1 ,1);
    if(typ==false){
        QLabel* texteDuree= new QLabel();
        duree = new QTimeEdit();
        texteDuree->setText("Durée :");
        button = new QRadioButton("Tâche préemptée", this);
        layout->addWidget(texteDuree, 2 ,0);
        layout->addWidget(button, 3 ,0);
        layout->addWidget(duree, 2 ,1);
        nb=2;
    }
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addTache()));
    layout->addWidget(valider, 2+nb , 0);
    this->setLayout(layout);

}

AjouteTache::AjouteTache(Projet * proj, bool typ, TacheComposite* tacheMere, QWidget *parent) : QDialog(parent)
{
    prj = proj;
    tacheMereComposite = tacheMere;
    layout= new QGridLayout();
    type = typ;
    valider = new QPushButton(tr("Ajouter la tâche au projet"),this);
    nom = new QLineEdit();
    description= new QTextEdit();
    texteNom= new QLabel();
    texteNom->setText("Nom de la tâche :");
    texteDescription= new QLabel();
    texteDescription->setText("Description de la tâche :");
    int nb=0;
    layout->addWidget(texteNom, 0 ,0);
    layout->addWidget(texteDescription, 1 ,0);
    layout->addWidget(nom, 0 ,1);
    layout->addWidget(description, 1 ,1);
    if(typ==false){
        QLabel* texteDuree= new QLabel();
        duree = new QTimeEdit();
        texteDuree->setText("Durée :");
        button = new QRadioButton("Tâche préemptée", this);
        layout->addWidget(texteDuree, 2 ,0);
        layout->addWidget(button, 3 ,0);
        layout->addWidget(duree, 2 ,1);
        nb=2;
    }
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(addTache()));
    layout->addWidget(valider, 2+nb , 0);
    this->setLayout(layout);

}

void AjouteTache::addTache(){
    if(type==false){
    int dureeTache = duree->time().hour();
        TacheUnitaire* tache1=prj->addTacheUnitaire(nom->text(),description->toPlainText(),"Tâche", dureeTache, button->isChecked());
        if(tacheMereComposite)tache1->setTacheMereComposite(tacheMereComposite);
    }
    else {
        TacheComposite* tache1=prj->addTacheComposite(nom->text(),description->toPlainText(),"Tâche");
        if(tacheMereComposite)tache1->setTacheMereComposite(tacheMereComposite);
    }
    this->close();

}

AjouteTache::~AjouteTache()
{
}
