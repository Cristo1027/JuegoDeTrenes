#include <SFML/Graphics.hpp>
#include "tablero_visual.h"
#include "cartas_visual.h"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(840, 640), "Juego de Trenes - Interfaz gráfica");

    TableroVisual tablero;
    CartasVisuales cartas;

    tablero.cargarCiudades();
    tablero.cargarTrayectos();

    cartas.setCartas({
        sf::Color::Red, sf::Color::Blue, sf::Color::Green,
        sf::Color(255,165,0), // Naranja
        sf::Color(139,69,19), // Café
        sf::Color(128,0,128)  // Morado
    });

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();

            // Detección de clics
            if (evento.type == sf::Event::MouseButtonPressed) {
                if (evento.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f clickPos(evento.mouseButton.x, evento.mouseButton.y);
                    tablero.manejarClick(clickPos);
                }
            }
        }

        ventana.clear(sf::Color(240, 240, 240)); // Fondo gris claro

        tablero.dibujar(ventana);
        cartas.dibujar(ventana);

        ventana.display();
    }

    return 0;
}
