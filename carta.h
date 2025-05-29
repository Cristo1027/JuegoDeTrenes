#pragma once
#include <string>

enum class Color { ROJO, AZUL, VERDE, MORADO, CAFE, NARANJA };

class Carta {
private:
    Color color;

public:
    Carta(Color c);
    Color getColor() const;
    std::string getNombre() const;
};
