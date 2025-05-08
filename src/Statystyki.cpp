#include <cmath>
#include "Statystyki.h"
#include "DanePogodowe.h"

Statystyki::Statystyki() {
}

double Statystyki::obliczSrednia(std::vector<double> dane, int wielkosc) {
    double suma = 0.0;
    for (int i = 0; i < wielkosc; i++) {
        suma += dane[i];
    }

    return suma / wielkosc;
}

double Statystyki::obliczMin(std::vector<double> dane, int wielkosc) {
    double minimum = dane[0];
    for (int i = 1; i < wielkosc; i++) {
        if(dane[i] < minimum) {
            minimum = dane[i];
        }
    }

    return minimum;
}

double Statystyki::obliczMax(std::vector<double> dane, int wielkosc) {
    double maximum = dane[0];
    for (int i = 1; i < wielkosc; i++) {
        if(dane[i] > maximum) {
            maximum = dane[i];
        }
    }

    return maximum;
}

double Statystyki::obliczMediane(std::vector<double> dane, int wielkosc) {
    for (int i = 0; i < wielkosc - 1; i++) {
        for (int j = 0; j < wielkosc - i - 1; j++) {
            if (dane[j] > dane[j+1]) {
                std::swap(dane[j], dane[j+1]);
            }
        }
    }

    if (wielkosc % 2 == 1) {
        return dane[wielkosc / 2];
    } else {
        return (dane[wielkosc / 2] + dane[wielkosc / 2 - 1]) / 2.0;
    }
}

double Statystyki::obliczOdchylenieStandardowe(std::vector<double> dane, int wielkosc) {
    double srednia = obliczSrednia(dane, wielkosc);
    double odchylenia = 0.0;
    double odchylenie;

    for (int i = 0; i < wielkosc; i++) {
        odchylenia += pow(dane[i] - srednia, 2);
    }

    odchylenie = sqrt(odchylenia / wielkosc);

    return odchylenie;
}
