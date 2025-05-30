#include "tablero_visual.h"
#include <cmath>

void TableroVisual::cargarCiudades() {
    float s = 40.0f;
    posiciones = {
        {"A", {1 * s, 7 * s}}, {"B", {3 * s, 5 * s}}, {"C", {1 * s, 14 * s}},
        {"D", {5 * s, 1 * s}}, {"E", {5 * s, 4 * s}}, {"F", {5 * s, 7 * s}},
        {"G", {3 * s, 13 * s}}, {"H", {7 * s, 7 * s}}, {"I", {7 * s, 4 * s}},
        {"J", {11 * s, 1 * s}}, {"K", {9 * s, 7 * s}}, {"L", {9 * s, 10 * s}},
        {"M", {9 * s, 13 * s}}, {"N", {13 * s, 1 * s}}, {"O", {13 * s, 4 * s}},
        {"P", {13 * s, 7 * s}}, {"Q", {13 * s, 10 * s}}, {"R", {16 * s, 4 * s}},
        {"S", {16 * s, 10 * s}}
    };
}

void TableroVisual::cargarTrayectos() {
    std::vector<std::tuple<std::string, std::string, sf::Color, int>> datos = {
        {"A", "B", sf::Color::Red, 4}, {"H", "L", sf::Color::Red, 6}, {"J", "N", sf::Color::Red, 2},
        {"A", "F", sf::Color::Blue, 4}, {"H", "K", sf::Color::Blue, 2}, {"I", "O", sf::Color::Blue, 6},
        {"E", "F", sf::Color::Green, 3}, {"K", "P", sf::Color::Green, 3}, {"P", "Q", sf::Color::Green, 3}, {"N", "O", sf::Color::Green, 3},
        {"I", "K", sf::Color(128, 0, 128), 4}, {"Q", "M", sf::Color(128, 0, 128), 4}, {"O", "R", sf::Color(128, 0, 128), 4},
        {"D", "E", sf::Color(139, 69, 19), 4}, {"G", "C", sf::Color(139, 69, 19), 4}, {"Q", "S", sf::Color(139, 69, 19), 4},
        {"F", "G", sf::Color(255, 165, 0), 3}, {"O", "P", sf::Color(255, 165, 0), 3}, {"F", "H", sf::Color(255, 165, 0), 2}, {"K", "L", sf::Color(255, 165, 0), 3}
    };

    for (auto& [a, b, color, l] : datos) {
        TrayectoVisual t;
        t.origen = a;
        t.destino = b;
        t.color = color;
        t.longitud = l;
        t.linea[0] = sf::Vertex(posiciones[a], color);
        t.linea[1] = sf::Vertex(posiciones[b], color);

        // Zona clicable = rectángulo alrededor de la línea
        sf::Vector2f p1 = posiciones[a];
        sf::Vector2f p2 = posiciones[b];
        float minX = std::min(p1.x, p2.x);
        float minY = std::min(p1.y, p2.y);
        float ancho = std::abs(p1.x - p2.x);
        float alto  = std::abs(p1.y - p2.y);
        t.area = sf::FloatRect(minX - 5, minY - 5, ancho + 10, alto + 10);

        trayectos.push_back(t);
    }
}

void TableroVisual::dibujar(sf::RenderWindow& ventana) {
    // Trayectos
    for (auto& t : trayectos) {
        sf::Color color = t.ocupado ? sf::Color::Black : t.color;
        t.linea[0].color = color;
        t.linea[1].color = color;
        ventana.draw(t.linea, 2, sf::Lines);
    }

    // Ciudades
    for (const auto& [nombre, pos] : posiciones) {
        sf::CircleShape ciudad(15);
        ciudad.setFillColor(sf::Color::White);
        ciudad.setOutlineThickness(2);
        ciudad.setOutlineColor(sf::Color::Black);
        ciudad.setPosition(pos - sf::Vector2f(15, 15));
        ventana.draw(ciudad);

        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"))
            continue;

        sf::Text texto;
        texto.setFont(font);
        texto.setCharacterSize(14);
        texto.setFillColor(sf::Color::Black);
        texto.setString(nombre);
        texto.setPosition(pos - sf::Vector2f(5, 10));
        ventana.draw(texto);
    }
}

void TableroVisual::manejarClick(sf::Vector2f mousePos) {
    for (auto& t : trayectos) {
        if (!t.ocupado && t.area.contains(mousePos)) {
            t.ocupado = true;
            break;
        }
    }
}
