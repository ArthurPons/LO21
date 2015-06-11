#ifndef LISTEPROJETS_H
#define LISTEPROJETS_H

#include <QObject>
#include <QWidget>
#include <QDialog>

class ListeProjets : public QDialog
{
    Q_OBJECT
public:
    explicit ListeProjets(QWidget *parent = 0);
    //ListeProjets(QWidget *parent,ProjectManager& pm);

signals:

public slots:
};

#endif // LISTEPROJETS_H
