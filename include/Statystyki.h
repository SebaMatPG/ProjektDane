#ifndef STATYSTYKI_H
#define STATYSTYKI_H
#include "DanePogodowe.h"


class Statystyki
{
    public:
        Statystyki();
        double obliczSredniaOpadow(DanePogodowe dane[]);
        double obliczMediane();
        double obliczOdchylenieStandardowe();
        double obliczMin(DanePogodowe dane[]);
        double obliczMax(DanePogodowe dane[]);

    protected:

    private:
        DanePogodowe dane[366];
};

#endif // STATYSTYKI_H
