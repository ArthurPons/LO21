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
#include <QVector>
#include "projetmanager.h"

class AfficheProjet : public QDialog
{
    Q_OBJECT
public:
    explicit AfficheProjet(Projet* prj, QWidget* parent = 0);
    QLabel* desc;
    QVBoxLayout layout;
    QLabel* tache;
    QPushButton* supprTache;
    QPushButton* addTache;
    QPushButton* supprProjet;
    Projet* proj;
    QVector<Tache*> listeTache;
private:
    ~AfficheProjet();
private slots:
    void supprimerTache(int i);
    void supprimerProjet();
    void ajouteTache();

};

#endif // AFFICHEPROJET_H
