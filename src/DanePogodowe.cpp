#include "DanePogodowe.h"

DanePogodowe::DanePogodowe(std::string data, double minTemp, double maxTemp, double srTemp, double minCisnienie, double maxCisnienie, double srCisnienie, double opady): data(data), minTemp(minTemp), maxTemp(maxTemp), srTemp(srTemp), minCisnienie(minCisnienie), maxCisnienie(maxCisnienie), srCisnienie(srCisnienie), opady(opady)   {}
DanePogodowe::DanePogodowe() : data(""), minTemp(0), maxTemp(0), srTemp(0),
                                minCisnienie(0), maxCisnienie(0), srCisnienie(0), opady(0) {}

//gettery
std::string DanePogodowe::pobierzDate() {
    return data;
}

double DanePogodowe::pobierzMinTemp() {
    return minTemp;
}

double DanePogodowe::pobierzMaxTemp() {
    return maxTemp;
}

double DanePogodowe::pobierzSrTemp() {
    return srTemp;
}

double DanePogodowe::pobierzMinCisnienie() {
    return minCisnienie;
}

double DanePogodowe::pobierzMaxCisnienie() {
    return maxCisnienie;
}

double DanePogodowe::pobierzSrCisnienie() {
    return srCisnienie;
}

double DanePogodowe::pobierzOpady() {
    return opady;
}
