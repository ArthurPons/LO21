#ifndef AjouteProjet_H
#define AjouteProjet_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QDateEdit>
#include <QList>
#include <QLabel>
#include <QSlider>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QSignalMapper>
#include <QLineEdit>
#include "projetmanager.h"

class AjouteProjet : public QDialog
{
    Q_OBJECT
public:
    AjouteProjet(QWidget* parent=0);
    QPushButton* valider;
    QLineEdit* nom;
    QTextEdit* description;
    QLabel* texteNom;
    QLabel* texteDescription;
    QGridLayout* layout;

private:
    ~AjouteProjet();


signals:
    void clicked(int);

private:
    QSignalMapper *sm;

public slots:

private slots:
    void addTache();
    void addPrj();
};

#endif // AjouteProjet_H
