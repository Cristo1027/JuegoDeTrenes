#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>
#include <tuple>

class TableroVisual {
private:
    std::map<std::string, sf::Vector2f> posiciones;
    struct TrayectoVisual {
        std::string origen;
        std::string destino;
        sf::Color color;
        int longitud;
        bool ocupado = false;
        sf::Vertex linea[2];
        sf::FloatRect area; // zona clicable
    };

    std::vector<TrayectoVisual> trayectos;

public:
    void cargarCiudades();
    void cargarTrayectos();
    void dibujar(sf::RenderWindow& ventana);
    void manejarClick(sf::Vector2f mousePos); // 🖱️ nuevo
};
