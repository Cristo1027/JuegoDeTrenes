#pragma once
#include <string>
#include <iostream>
#include "Carta.h" // Asegura que se incluya la definición de Color

class Trayecto {
private:
    std::string origen;
    std::string destino;
    Color colorRequerido;
    int longitud;
    int ocupadoPor; // -1 = libre, otro = id del jugador

public:
    Trayecto(std::string o, std::string d, Color c, int l);

    std::string getOrigen() const;
    std::string getDestino() const;
    Color getColor() const;
    int getLongitud() const;
    int getOcupadoPor() const;
    bool estaOcupado() const;
    int calcularPuntos() const;
    void ocupar(int jugadorId);
};

inline std::ostream& operator<<(std::ostream& os, const Color& color) {
    switch (color) {
        case Color::ROJO:    os << "Rojo"; break;
        case Color::AZUL:    os << "Azul"; break;
        case Color::VERDE:   os << "Verde"; break;
        case Color::MORADO:  os << "Morado"; break;
        case Color::CAFE:    os << "Café"; break;
        case Color::NARANJA: os << "Naranja"; break;
        default:             os << "Desconocido"; break;
    }
    return os;
}
