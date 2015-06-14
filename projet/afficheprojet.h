#ifndef AFFICHEPROJET_H
#define AFFICHEPROJET_H
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
#include <QHBoxLayout>
#include <QVector>
#include <QSignalMapper>
#include <QMessageBox>
#include <QDebug>
#include "projetmanager.h"
#include "ajoutetache.h"
#include "ajouteprecedence.h"
#include "ajouteprogrammationtache.h"

class AfficheProjet : public QDialog
{
    Q_OBJECT
public:
    explicit AfficheProjet(Projet* prj, QWidget* parent = 0);
    QLabel* desc;
    QVBoxLayout layout;
    QLabel* tache;
    QPushButton* addPrecedence;
    QPushButton* supprTache;
    QPushButton* addTacheU;
    QPushButton* addTacheC;
    QPushButton* supprProjet;
    Projet* proj;
    QVector<Tache*> listeTache;

private:
    ~AfficheProjet();

private slots:
    void supprimerTache(int i);
    void addPrec(int i);
    void addSTacheU(int i);
    void addSTacheC(int i);
    void addProgTache(int i);
    void supprimerProjet();
    void ajouteTacheUnitaire();
    void ajouteTacheComposite();

};

#endif // AFFICHEPROJET_H
