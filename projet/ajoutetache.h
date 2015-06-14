#ifndef AjouteTache_H
#define AjouteTache_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QSignalMapper>
#include <QLineEdit>
#include <QMessageBox>
#include <QTimeEdit>
#include <QRadioButton>
#include "interface.h"
#include "projetmanager.h"

class AjouteTache : public QDialog
{
    Q_OBJECT
public:
    explicit
    AjouteTache(Projet* proj, bool typ, QWidget* parent=0);
    AjouteTache(Projet* proj, bool typ, TacheComposite* tacheMere, QWidget* parent=0);
    Projet* prj;
    QPushButton* valider;
    QLineEdit* nom;
    QTextEdit* description;
    QLabel* texteNom;
    QLabel* texteDescription;
    QGridLayout* layout;
    bool type;
    QTimeEdit* duree;
    QRadioButton *button;
    TacheComposite* tacheMereComposite;

private:
    ~AjouteTache();


signals:

public slots:

private slots:
    void addTache();
};

#endif // AjouteTache_H
