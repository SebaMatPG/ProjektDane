#include <iostream>
#ifndef DANEPOGODOWE_H
#define DANEPOGODOWE_H


class DanePogodowe
{
    public:
        DanePogodowe(std::string data, double minTemp, double maxTemp, double srTemp, double minCisnienie, double maxCisnienie, double srCisnienie, double opady);
        DanePogodowe();

        std::string pobierzDate();
        double pobierzMinTemp();
        double pobierzMaxTemp();
        double pobierzSrTemp();
        double pobierzMinCisnienie();
        double pobierzMaxCisnienie();
        double pobierzSrCisnienie();
        double pobierzOpady();

    protected:
        std::string data; //YYYY-MM-DD
        float minTemp;
        float maxTemp;
        float srTemp;
        float minCisnienie;
        float maxCisnienie;
        float srCisnienie;
        float opady;

    private:
};

#endif // DANEPOGODOWE_H
