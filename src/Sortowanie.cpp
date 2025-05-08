#include "Sortowanie.h"
#include <iostream>
#include <fstream>

Sortowanie::Sortowanie()
{
    //ctor
}

void Sortowanie::sortBabelkowe (std::vector<double> tablica, int rozmiarTablicy) {
    for (int i = 0; i < rozmiarTablicy - 1; i++) {
        for (int j = 0; j < rozmiarTablicy - i - 1; j++) {
            if (tablica[j] > tablica[j+1]) {
                std::swap(tablica[j], tablica[j+1]);
            }
        }
    }

    std::ofstream plik("dane.csv"); //To pewnie bêdzie w innym miejscu

    for (int k = 0; k < rozmiarTablicy; k++) {
        plik << tablica[k] << "\n";
    }

    std::cout << "Dane zostaly zaimportowane do pliku dane.csv" << std::endl;
    plik.close();

}
