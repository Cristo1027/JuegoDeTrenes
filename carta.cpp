#include "Carta.h"

const std::string coloresStr[] = { "Rojo", "Azul", "Verde", "Morado", "Café", "Naranja" };

Carta::Carta(Color c) : color(c) {}

Color Carta::getColor() const {
    return color;
}

std::string Carta::getNombre() const {
    return coloresStr[static_cast<int>(color)];
}
