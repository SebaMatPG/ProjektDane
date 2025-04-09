#ifndef POGODADZIENNA_H
#define POGODADZIENNA_H
#include <string>
#include "DanePogodowe.h"


class PogodaDzienna : public DanePogodowe
{
    public:
        PogodaDzienna(std::string data, double minTemp, double maxTemp, double srTemp, double minCisnienie, double maxCisnienie, double srCisnienie, double opady);

        bool czyDataJestWPrzedziale(std::string dataPoczatkowa, std::string dataKoncowa);

        double pobierzWartoscPola(std::string nazwaPola);

    protected:

    private:
};

#endif // POGODADZIENNA_H
