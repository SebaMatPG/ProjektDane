#include <iostream>
#include <vector>
#include "Menu.h"
#include "Statystyki.h"
#include "Sortowanie.h"

Menu::Menu()
{
    //ctor
}

//Klasa ma za zadanie zebranie wszystkich wyborów u¿ytkownika oraz ich walidacje

int Menu::menuOperacja(){
    do{
        std::cout << "Wybierz operacje:" << std::endl;
        std::cout << "1. Sortowanie danych" << std::endl;
        std::cout << "2. Minimum" << std::endl;
        std::cout << "3. Maksimum" << std::endl;
        std::cout << "4. Srednia" << std::endl;
        std::cout << "5. Mediana" << std::endl;
        std::cout << "6. Odchylenie standardowe" << std::endl;
        std::cin >> wybor1;
    } while (wybor1 < 1 || wybor1 > 6);

    return wybor1;
}

int Menu::menuDane() {
    do{
        std::cout << "Wybierz zestaw danych: " << std::endl;
        std::cout << "1. Mimimalna temperatura" << std::endl;
        std::cout << "2. Srednia temperatura" << std::endl;
        std::cout << "3. Maksymalna temperatura" << std::endl;
        std::cout << "4. Mimimalne cisnienie" << std::endl;
        std::cout << "5. Srednie cisnienie" << std::endl;
        std::cout << "6. Maksymalne cisnienie" << std::endl;
        std::cout << "7. Opady" << std::endl;
        std::cin >> wybor2;
    } while (wybor2 < 1 || wybor2 > 7);

    return wybor2;
}

std::string Menu::menuPoczatekPrzedzialu() {
    do{
        std::cout << "Podaj poczatek przedzialu w formacie YYYY-MM-DD" << std::endl;
        std::cin >> wybor3;
    } while (!sprawdzFormatDaty(wybor3));

    return wybor3;
}

std::string Menu::menuKoniecPrzedzialu() {
    do{
        std::cout << "Podaj koniec przedzialu w formacie YYYY-MM-DD" << std::endl;
        std::cin >> wybor4;
    } while (!sprawdzFormatDaty(wybor4));

    return wybor4;
}

int Menu::menuPowrot() {
    do{
        std::cout << "Chcesz wrocic do menu?" << std::endl;
        std::cout << "1. Tak" << std::endl;
        std::cout << "2. Nie" << std::endl;
        std::cin >> wybor5;
    } while (wybor5 != 1 && wybor5 != 2);

    return wybor5;
}

void Menu::wyswietlenieDanych(std::vector<double> daneDoPrezentacji, int wielkoscVektora, int wybor1){
    Statystyki stat;
    Sortowanie sorto;

    switch(wybor1){
        case 1:
            sorto.sortBabelkowe(daneDoPrezentacji, wielkoscVektora);
            break;
        case 2:
            std::cout << "Minimalna wartosc: " << stat.obliczMin(daneDoPrezentacji, wielkoscVektora) << std::endl;
            break;
        case 3:
            std::cout << "Maksymalna wartosc: " << stat.obliczMax(daneDoPrezentacji, wielkoscVektora) << std::endl;
            break;
        case 4:
            std::cout << "Srednia wartosc: " << stat.obliczSrednia(daneDoPrezentacji, wielkoscVektora) << std::endl;
            break;
        case 5:
            std::cout << "Mediana: " << stat.obliczMediane(daneDoPrezentacji, wielkoscVektora) << std::endl;
            break;
        case 6:
            std::cout << "Odchylenie standardowe: " << stat.obliczOdchylenieStandardowe(daneDoPrezentacji, wielkoscVektora) << std::endl;
            break;

    }
}

bool Menu::sprawdzFormatDaty(std::string data) { //czy spe³niony jest format YYYY-MM-DD
    if (data.size() < 10) return false;
    if (czyJestCyfra(data[0]) && czyJestCyfra(data[1]) && czyJestCyfra(data[2]) && czyJestCyfra(data[3]) && data[4] == '-' && czyJestCyfra(data[5]) && czyJestCyfra(data[6]) && data[7] == '-' && czyJestCyfra(data[8]) && czyJestCyfra(data[9])) return true;

    return false;
}

bool Menu::czyJestCyfra(char znak) {
    return znak >= '0' && znak <= '9'; //Nawi¹zanie do tablicy ASCII
}
