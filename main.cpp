#include <iostream>
#include <filesystem>
#include <vector>
#include "DanePogodowe.h"
#include "Excel.h"
#include "Statystyki.h"
#include "Sortowanie.h"
#include "Menu.h"

int main()
{
    Excel excel;
    Menu menu;
    Sortowanie sorto;
    Statystyki stat;

    DanePogodowe dane[366];
    if(!excel.czyPlikIstnieje()) {
        std::cout << "Plik nie istnieje";
        return 0;
    }

    int licznik = excel.wczytajDane(dane); //na razie jest aby sprawdzac czy dane siê poprawnie zaladowaly
    std::cout << "Wczytano: " << licznik << " rekordow" << std::endl;

    int wybor1 = menu.menuOperacja();
    int wybor2 = menu.menuDane();
    std::string wybor3 = menu.menuPoczatekPrzedzialu();
    std::string wybor4 = menu.menuKoniecPrzedzialu();

    std::vector<double> daneDoPrezentacji;

    switch (wybor2) { //to potem pojdzie do jakiejś klasy, na razie niech działa po prostu
        //switch ma za zadanie wydobycie danych które potem zostana odpowiednio uzyte
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

    int wielkoscTablicy = daneDoPrezentacji.size();
    if (wielkoscTablicy == 0) {
        std::cout << "Nie ma zadnych danych" << std::endl;
        return 0;
    }

    switch(wybor1){
        case 1:
            sorto.sortBabelkowe(daneDoPrezentacji, wielkoscTablicy);
            break;
        case 2:
            std::cout << "Minimalna wartosc: " << stat.obliczMin(daneDoPrezentacji, wielkoscTablicy);
            break;
        case 3:
            std::cout << "Maksymalna wartosc: " << stat.obliczMax(daneDoPrezentacji, wielkoscTablicy);
            break;
        case 4:
            std::cout << "Srednia wartosc: " << stat.obliczSrednia(daneDoPrezentacji, wielkoscTablicy);
            break;
        case 5:
            std::cout << "Mediana: " << stat.obliczMediane(daneDoPrezentacji, wielkoscTablicy);
            break;
        case 6:
            std::cout << "Odchylenie standardowe: " << stat.obliczOdchylenieStandardowe(daneDoPrezentacji, wielkoscTablicy);
            break;

    }

    return 0;
}
