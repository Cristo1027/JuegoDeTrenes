#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class CartasVisuales {
private:
    std::vector<sf::Color> coloresCartas;

public:
    void setCartas(const std::vector<sf::Color>& colores);
    void dibujar(sf::RenderWindow& ventana);
};
