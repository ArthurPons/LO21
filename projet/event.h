#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <QList>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QStringList>
#include <QDateEdit>
#include <QDate>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
#include <QCalendarWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QPushButton>

class Event
{
public:
    Event(QString n, QDate d, int hd, int hf, QString desc);
    QString nom;
    QDate date;
    int heureDebut;
    int heureFin;
    QString description;
    void verif();
};

#endif // EVENT_H
