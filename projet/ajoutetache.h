#ifndef AjouteTache_H
#define AjouteTache_H

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
/*
class AjouteTache : public QDialog
{
    Q_OBJECT
public:
    AjouteTache(Projet* prj, QWidget* parent=0);
    QPushButton* valider;
    QLineEdit* nom;
    QTextEdit* description;
    QLabel* texteNom;
    QLabel* texteDescription;
    QGridLayout* layout;

private:
    ~AjouteTache();


signals:
    void clicked(int);

private:
    QSignalMapper *sm;

public slots:

private slots:
    void addPrj(QString n, QString d);
};
*/
#endif // AjouteTache_H
