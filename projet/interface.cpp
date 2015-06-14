#include "Interface.h"
#include "listeprojets.h"

Interface::Interface()
{
    QWidget* widget = new QWidget;
    this->setCentralWidget(widget);
    this->setWindowTitle("Project Calendar");

    semaine = new QDateEdit(QDate::currentDate(),this);
    jourCourant = new QDate();
    boucleJour= new QDate();
    dateCourante= new QDate();
    calendar = new QLabel(QString("Calendrier"),this);
    table = new QTableWidget(12,7,this);
    cal = new QCalendarWidget(this);
    menuCote = new QGroupBox(tr("Menu"),this);
    gprojet = new QPushButton(tr("Afficher les projets"),this);
    gevt = new QPushButton(tr("Ajouter un évènement"),this);
    layout = new QVBoxLayout;
    layout1 = new QHBoxLayout;
    layout2 = new QGridLayout;
    layout3 = new QGridLayout;
    layout4 = new QVBoxLayout;
    layout5 = new QVBoxLayout;

    QStringList jours;
    jours << "Lundi" << "Mardi" << "Mercredi" << "Jeudi" << "Vendredi" << "Samedi" << "Dimanche";
    QStringList horaires;
    horaires << "8h" << "9h" << "10h" << "11h" << "12h" << "13h" << "14h" << "15h" << "16h" << "17h" << "18h" << "19h";

    table->setHorizontalHeaderLabels(jours);
    table->setVerticalHeaderLabels(horaires);

    layout2->addWidget(semaine,0,0);
    layout2->addWidget(calendar,0,1);

    cal->setGridVisible(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout4->addWidget(gprojet);
    layout4->addWidget(gevt);
    layout4->addStretch(1);
    menuCote->setLayout(layout4);

    layout3->addWidget(table,0,0,-1,1);
    layout3->addWidget(menuCote,0,4,4,5);
    layout3->addWidget(cal,4,4,3,5);
    layout3->setHorizontalSpacing(15);

    layout->addLayout(layout2);
    layout->addLayout(layout3);

    widget->setLayout(layout);

    ProgrammationManager& progm=ProgrammationManager::Instance();
    prog = progm.getListeProgrammation();

    Interface::getCellulesLigne();

    //Fixation des slots
    QObject::connect(gprojet, SIGNAL(clicked()), this, SLOT(gererProjet()));
    QObject::connect(gevt, SIGNAL(clicked()), this, SLOT(gererEvent()));

    creerActionMenu();
    creerMenu();

}

void Interface::creerActionMenu()
{

    quitte = new QAction("&Quitter",this);
    propos = new QAction("&A propos",this);

    QObject::connect(quitte, SIGNAL(triggered()), this, SLOT(quitter()));
    QObject::connect(propos, SIGNAL(triggered()), this, SLOT(aPropos()));

}

void Interface::creerMenu()
{
    options = menuBar()->addMenu(tr("&Options"));
    aide = menuBar()->addMenu(tr("&Aide"));

    options->addAction(quitte);
    aide->addAction(propos);
}


QList<QTableWidgetItem*> Interface::getCellulesLigne()
{
    QList<QTableWidgetItem*> listIt;
    boucleJour=&boucleJour->currentDate();
    jourCourant=&jourCourant->currentDate();
    *boucleJour=boucleJour->addDays(-jourCourant->dayOfWeek()+1);
    qDebug()<<boucleJour->toString();

    for(int i = 0; i<table->columnCount(); i++)
    {
        for(int j=0;j<table->rowCount();j++)
            {
                for(int k=0; k<prog.size();k++)
                {
                   if(*boucleJour==prog.at(k)->getDate() && (prog.at(k)->getHeureDebut()-8<=j &&
                                                            prog.at(k)->getHeureFin()-8>=j)){
                 qDebug()<<"affichage programmation";
                 QTableWidgetItem* progra = new QTableWidgetItem();
                 QString text=prog.at(k)->getIdentifiant();
                 progra->setText(text);
                 table->setItem(j,i,progra);
                    }
                }
            }
        *boucleJour=boucleJour->addDays(1);
    }
    return listIt;
}


//Définition des slots virtuels

void Interface::quitter()
{
    this->close();
}

void Interface::aPropos()
{
    QMessageBox::information(this,tr("À propos"),tr("Crée par Arthur Pons et Stéphane Louis"),QMessageBox::Close);
}

void Interface::gererProjet()
{
    ListeProjets* fen=new ListeProjets();
    fen->setFixedWidth(300);
    fen->show();
}

void Interface::gererEvent()
{

}

