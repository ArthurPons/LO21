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

class AjouteActivite : public QDialog
{
    Q_OBJECT
public:
    explicit
    AjouteActivite(QWidget* parent=0);
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

private:
    ~AjouteActivite();


signals:

public slots:

private slots:
    void addAct();
};

#endif // AjouteActivite_H

