#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QStringList>
#include <QDateEdit>
#include <QDate>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
#include <QCalendarWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QPushButton>


class Interface : public QMainWindow
{
    Q_OBJECT

    //Creation de deux menu dans la barre de menu
    QMenu* options;
    QMenu* aide;

    QAction* quitte;
    QAction* propos;

    QDateEdit* semaine;
    QDate* jourCourant;
    QLabel* calendar;
    QVBoxLayout* layout;
    QHBoxLayout* layout1;
    QGridLayout* layout2;
    QGridLayout* layout3;
    QVBoxLayout* layout4;
    QVBoxLayout* layout5;
    QTableWidget* table;

    QCalendarWidget* cal;

    QGroupBox* menuCote;
    QPushButton* gprojet;
    QPushButton* gtache;
    QPushButton* gevt;



public:

    //Interface(TacheManager& tm, QWidget* parent = 0); //La vrai qui prend un TM et qui affiche les tâches de la semaine
    explicit Interface();
    void creerMenu();
    void creerActionMenu();

    QList<QTableWidgetItem*> getCellulesLigne();


private slots:

    void quitter();
    void aPropos();
    void gererProjet();
    void gererTache();
    void gererEvent();

};


#endif // INTERFACE_H
