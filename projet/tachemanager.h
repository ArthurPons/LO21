#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H

#include<QVector>
#include "tachemanager.cpp"
#include "tache.h"

//Design pattern Singleton

class TacheManager
{
private:
    TacheManager();
    ~TacheManager();
    TacheManager& operator=(const TacheManager&){}
    TacheManager (const TacheManager&){}
    static TacheManager instance;
    QVector<Tache*> listeTache;

public:
    static TacheManager& getInstance()
    {
        static TacheManager instance;
        return instance;
    }

    Tache& getTache(QString titre);
};

#endif // TACHEMANAGER_H
