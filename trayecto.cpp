#include "Trayecto.h"

Trayecto::Trayecto(std::string o, std::string d, Color c, int l)
    : origen(o), destino(d), colorRequerido(c), longitud(l), ocupadoPor(-1) {}

std::string Trayecto::getOrigen() const { return origen; }
std::string Trayecto::getDestino() const { return destino; }
Color Trayecto::getColor() const { return colorRequerido; }
int Trayecto::getLongitud() const { return longitud; }
int Trayecto::getOcupadoPor() const { return ocupadoPor; }

bool Trayecto::estaOcupado() const {
    return ocupadoPor != -1;
}

int Trayecto::calcularPuntos() const {
    switch (longitud) {
        case 2: return 1;
        case 3: return 2;
        case 4: return 4;
        case 5: return 6;
        case 6: return 9;
        default: return longitud; // por defecto
    }
}

void Trayecto::ocupar(int jugadorId) {
    ocupadoPor = jugadorId;
}
