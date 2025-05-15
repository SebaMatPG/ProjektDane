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

std::vector<double> Sortowanie::filtrowanie(DanePogodowe dane[], int wybor2, std::string wybor3, std::string wybor4) {
    std::vector<double> daneDoPrezentacji;

    switch (wybor2) {   //switch ma za zadanie wydobycie danych które potem zostana odpowiednio uzyte
    case 1:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzMinTemp());
            }
        }
        break;
    case 2:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzSrTemp());
            }
        }
        break;
    case 3:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzMaxTemp());
            }
        }
        break;
    case 4:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzMinCisnienie());
            }
        }
        break;
    case 5:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzSrCisnienie());
            }
        }
        break;
    case 6:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzMaxCisnienie());
            }
        }
        break;
    case 7:
        for (int i = 0; i < 366; i++) {
            if(dane[i].pobierzDate() >= wybor3 && dane[i].pobierzDate() <= wybor4){
                daneDoPrezentacji.push_back(dane[i].pobierzOpady());
            }
        }
        break;
    }

    return daneDoPrezentacji;
}
