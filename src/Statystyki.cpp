#include "Statystyki.h"
#include "DanePogodowe.h"

Statystyki::Statystyki() {
}

double Statystyki::obliczSredniaOpadow(DanePogodowe dane[]) {
    double suma = 0.0;
    for (int i = 0; i < 366; i++) {
        suma += dane[i].pobierzOpady();
    }
    return suma / 366;
}

double Statystyki::obliczMin(DanePogodowe dane[]) {
    double minimum = dane[0].pobierzOpady();
    for (int i = 1; i < 366; i++) {
        if(dane[i].pobierzOpady() < minimum) {
            minimum = dane[i].pobierzOpady();
        }
    }

    return minimum;
}

double Statystyki::obliczMax(DanePogodowe dane[]) {
    double maximum = dane[0].pobierzOpady();
    for (int i = 1; i < 366; i++) {
        if(dane[i].pobierzOpady() > maximum) {
            maximum = dane[i].pobierzOpady();
        }
    }

    return maximum;
}
