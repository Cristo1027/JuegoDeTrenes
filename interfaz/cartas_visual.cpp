#include "cartas_visual.h"

void CartasVisuales::setCartas(const std::vector<sf::Color>& colores) {
    coloresCartas = colores;
}

void CartasVisuales::dibujar(sf::RenderWindow& ventana) {
    float cartaAncho = 60;
    float cartaAlto = 90;
    float espacio = 15;
    float inicioX = 40;
    float baseY = ventana.getSize().y - cartaAlto - 20;

    for (size_t i = 0; i < coloresCartas.size(); ++i) {
        sf::RectangleShape carta(sf::Vector2f(cartaAncho, cartaAlto));
        carta.setFillColor(coloresCartas[i]);
        carta.setOutlineThickness(2);
        carta.setOutlineColor(sf::Color::Black);
        carta.setPosition(inicioX + i * (cartaAncho + espacio), baseY);
        ventana.draw(carta);
    }
}
