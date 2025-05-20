#include "Excel.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

Excel::Excel()
{
    //ctor
}

bool Excel::czyPlikIstnieje() {
    std::ifstream plik(SCIEZKA_PLIKU);

    return plik.good();
}

std::string Excel::zmienFormatDaty(std::string staraData) {
    std::string nowaData = staraData.substr(0, 10);

    return nowaData;
}

int Excel::wczytajDane(DanePogodowe dane[]) {
    std::ifstream plik(SCIEZKA_PLIKU);

    std::string linia;
    int licznik = 0;

    for (int i = 0; i < 10; i++) { //Pierwsze 10 wierszy Excela to nag³ówki
        std::getline(plik, linia);
    }

    while (std::getline(plik, linia)) {
        std::replace(linia.begin(), linia.end(), ',', '.'); //zmiana formatu danych
        std::stringstream ss(linia);
        std::string data;
        double minTemp, maxTemp, srTemp, minCisnienie, maxCisnienie, srCisnienie, opady;

        std::getline(ss, data, ';'); //wprowadzenie danych do obiektow
        data = zmienFormatDaty(data);
        ss >> minTemp; ss.ignore();
        ss >> maxTemp; ss.ignore();
        ss >> srTemp; ss.ignore();
        ss >> minCisnienie; ss.ignore();
        ss >> maxCisnienie; ss.ignore();
        ss >> srCisnienie; ss.ignore();
        ss >> opady;

        dane[licznik] = DanePogodowe(data, minTemp, maxTemp, srTemp, minCisnienie, maxCisnienie, srCisnienie, opady);
        licznik++;
    }
    plik.close();
    return licznik;
}
