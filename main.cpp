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

    DanePogodowe dane[366];
    if(!excel.czyPlikIstnieje()) {
        std::cout << "Plik nie istnieje";
        return 0;
    }

    int licznik = excel.wczytajDane(dane);
    std::cout << "Wczytano: " << licznik << " rekordow" << std::endl;

    bool czyProgramMaPowtorzyc = true;

    do{
        int wybor1 = menu.menuOperacja();
        int wybor2 = menu.menuDane();
        std::string wybor3 = menu.menuPoczatekPrzedzialu();
        std::string wybor4 = menu.menuKoniecPrzedzialu();
        std::vector<double> daneDoPrezentacji = sorto.filtrowanie(dane ,wybor2, wybor3, wybor4);

        int wielkoscVektora = daneDoPrezentacji.size();
        if (wielkoscVektora == 0) {
            std::cout << "Nie ma zadnych danych, prosze ponownie uzupelnic menu" << std::endl;
            return 0;
        }

        menu.wyswietlenieDanych(daneDoPrezentacji, wielkoscVektora, wybor1);

        if (menu.menuPowrot() == 2) czyProgramMaPowtorzyc = false;
    } while (czyProgramMaPowtorzyc);


    return 0;
}
