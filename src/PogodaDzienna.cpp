#include "PogodaDzienna.h"
#include "DanePogodowe.h"
#include <string>

PogodaDzienna::PogodaDzienna(std::string data, double minTemp, double maxTemp, double srTemp, double minCisnienie, double maxCisnienie, double srCisnienie, double opady): DanePogodowe(data, minTemp, maxTemp, srTemp, minCisnienie, maxCisnienie, srCisnienie, opady) {}

bool czyDataJestWPrzedziale(std::string dataPoczatkowa, std::string dataKoncowa) {
    return data >= dataPoczatkowa && data <= dataKoncowa;
}
