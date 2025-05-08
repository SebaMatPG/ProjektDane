#ifndef STATYSTYKI_H
#define STATYSTYKI_H
#include <vector>


class Statystyki
{
    public:
        Statystyki();
        double obliczSrednia(std::vector<double> dane, int wielkosc);
        double obliczMediane(std::vector<double> dane, int wielkosc);
        double obliczOdchylenieStandardowe(std::vector<double> dane, int wielkosc);
        double obliczMin(std::vector<double> dane, int wielkosc);
        double obliczMax(std::vector<double> dane, int wielkosc);

    protected:

    private:
};

#endif // STATYSTYKI_H
