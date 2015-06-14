#include "AjoutePrecedence.h"
#include "afficheprojet.h"
#include "ajouteprojet.h"

AjoutePrecedence::AjoutePrecedence(Projet* prj, Tache* tache, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Choisir précédence");
    QLabel* label = new QLabel();
    label->setText("Choisir la tâche fille");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label);
    proj = prj;
    tacheMere=tache;
    listeTaches = proj->getListeTaches();
    QList<QPushButton*>addPrecedence;
    int j=0;
    for(int i=0;i<listeTaches.size();i++){
        if(listeTaches.at(i)->getIdentifiant()!=tacheMere->getIdentifiant())
        {
        sm=new QSignalMapper(this);
        addPrecedence.append(new QPushButton(listeTaches.at(i)->getIdentifiant(), this));
        QObject::connect(addPrecedence[j], SIGNAL(clicked()), sm, SLOT(map()));
        sm->setMapping(addPrecedence[j], i);
        connect(sm, SIGNAL(mapped(int)),this, SLOT(addPrec(int)));
        layout->addWidget(addPrecedence[j]);
        j++;
        }
    }
    this->setLayout(layout);
}

void AjoutePrecedence::addPrec(int i)
{
    Tache* tach = listeTaches.at(i);
    tach->addPrecedence(tacheMere);
    this->close();
}
