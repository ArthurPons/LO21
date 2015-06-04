#ifndef TACHE_H
#define TACHE_H

class Tache
{
protected:
    Qstring titre;
    Qstring description;
    std::vector<*Tache> precedence;

public:
    Tache();
    ~Tache();
};

#endif // TACHE_H
