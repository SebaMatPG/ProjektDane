#ifndef EXCEL_H
#define EXCEL_H
#include <string>
#include "DanePogodowe.h"

class Excel
{
    public:
        Excel();

        bool czyPlikIstnieje();
        std::string zmienFormatDaty(std::string staraData); //TODO: Zmieni� na private jak sko�cz� testowa�
        int wczytajDane(DanePogodowe dane[]);

    protected:

    private:
        const std::string SCIEZKA_PLIKU = "D:\\c++\\15.02.2021\\projektAnalizaDanych\\Excel.csv";
};

#endif // EXCEL_H
