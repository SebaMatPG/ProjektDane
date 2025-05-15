#ifndef SORTOWANIE_H
#define SORTOWANIE_H
#include "DanePogodowe.h"
#include <vector>
#include <string>


class Sortowanie
{
    public:
        Sortowanie();
        void sortBabelkowe(std::vector<double> tablica, int rozmiarTablicy);
        std::vector<double> filtrowanie (DanePogodowe dane[], int wybor2, std::string wybor3, std::string wybor4);

    protected:

    private:
};

#endif // SORTOWANIE_H
