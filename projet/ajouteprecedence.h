
#ifndef AjoutePrecedence_H
#define AjoutePrecedence_H

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

class AjoutePrecedence : public QDialog
{
    Q_OBJECT
public:
    explicit AjoutePrecedence(Projet* prj, Tache* tache, QWidget *parent = 0);
    QVBoxLayout* layout;
    QPushButton* addPrecedence;
    Projet* proj;
    Tache* tacheMere;
    QVector<Tache*> listeTaches;

signals:
    void clicked(int);

private:
    QSignalMapper *sm;

private slots:
    void addPrec(int i);
};

#endif // AjoutePrecedence_H
