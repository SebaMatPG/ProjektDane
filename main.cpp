#include <iostream>
#include <filesystem>
#include "DanePogodowe.h"
#include "Excel.h"
#include "Statystyki.h"

int main()
{
    Excel excel;
    DanePogodowe dane[366];
    if(!excel.czyPlikIstnieje()) {
        std::cout << "Plik nie istnieje";
        return 0;
    }

    int licznik = excel.wczytajDane(dane);
    std::cout << "Wczytano: " << licznik << " rekordow" << std::endl;

    Statystyki stat;
    std::cout << stat.obliczSredniaOpadow(dane) << std::endl;
    std::cout << stat.obliczMax(dane) << std::endl;
    std::cout << stat.obliczMin(dane) << std::endl;


    return 0;
}
