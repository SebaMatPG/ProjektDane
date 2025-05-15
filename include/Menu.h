#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>

class Menu
{
    public:
        Menu();
        int menuOperacja();
        int menuDane();
        std::string menuPoczatekPrzedzialu();
        std::string menuKoniecPrzedzialu();
        int menuPowrot();
        void wyswietlenieDanych(std::vector<double> daneDoPrezentacji, int wielkoscVektora, int wybor1);

    protected:

    private:
        int wybor1;
        int wybor2;
        std::string wybor3;
        std::string wybor4;
        int wybor5;
        bool sprawdzFormatDaty(std::string data);
        bool czyJestCyfra(char znak);
};

#endif // MENU_H
