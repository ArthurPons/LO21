#ifndef AjouteActivite_H
#define AjouteActivite_H

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
#include "interface.h"

class AjouteActivite : public QDialog
{
    Q_OBJECT
public:
    explicit
    AjouteActivite(Interface* inter, QWidget* parent=0);
    QPushButton* valider;
    QLineEdit* nom;
    QTextEdit* description;
    QDateEdit* date;
    QTimeEdit* heureDebut;
    QTimeEdit* heureFin;
    QLabel* texteNom;
    QLabel* texteDescription;
    QLabel* texteHd;
    QLabel* texteDate;
    QLabel* texteHf;
    QGridLayout* layout;
    Interface* f;
    QTime hmin;
    QTime hmax;
    QTime hmin2;
    QTime hmax2;

private:
    ~AjouteActivite();


signals:

public slots:

private slots:
    void addAct();
};

#endif // AjouteActivite_H
