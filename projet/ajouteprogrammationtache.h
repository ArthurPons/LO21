#ifndef AjouteProgrammationTache_H
#define AjouteProgrammationTache_H

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
#include <QMessageBox>
#include <QTimeEdit>
#include "programmationmanager.h"
#include "tache.h"
#include "tacheunitaire.h"

class AjouteProgrammationTache : public QDialog
{
    Q_OBJECT
public:
    explicit
    AjouteProgrammationTache(Tache* tache, QWidget* parent=0);
    QPushButton* valider;
    QDateEdit* date;
    QTimeEdit* heureDebut;
    QTimeEdit* heureFin;
    QLabel* texteNom;
    QLabel* texteDescription;
    QLabel* texteHd;
    QLabel* texteDate;
    QLabel* texteHf;
    QGridLayout* layout;
    QTime hmin;
    QTime hmax;
    QTime hmin2;
    QTime hmax2;
    Tache* t;
    TacheUnitaire* tach;

private:
    ~AjouteProgrammationTache();


signals:

public slots:

private slots:
    void addProgTache();
};

#endif // AjouteProgrammationTache_H
