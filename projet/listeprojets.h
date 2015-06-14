
#ifndef LISTEPROJETS_H
#define LISTEPROJETS_H

#include <QWidget>
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QTextEdit>
#include <QDateEdit>
#include <QList>
#include <QLabel>
#include <QSlider>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QVector>
#include "QSignalMapper"
#include "projetmanager.h"

class ListeProjets : public QDialog
{
    Q_OBJECT
public:
    explicit ListeProjets(QWidget *parent = 0);
    QVBoxLayout* layout;
    QPushButton* addPrj;
    QPushButton* bouton;
    QVector<Projet*> prj;

signals:
    void clicked(int);

private:
    QSignalMapper *sm;

private slots:
    void afficherProjet(int i);
    void ajouterProjet();
};

#endif // LISTEPROJETS_H
