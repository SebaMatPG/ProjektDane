#ifndef MENU_H
#define MENU_H
#include <string>


class Menu
{
    public:
        Menu();
        int menuOperacja();
        int menuDane();
        std::string menuPoczatekPrzedzialu();
        std::string menuKoniecPrzedzialu();


    protected:

    private:
        int wybor1;
        int wybor2;
        std::string wybor3;
        std::string wybor4;
        bool sprawdzFormatDaty(std::string data);
        bool czyJestCyfra(char znak);
};

#endif // MENU_H
