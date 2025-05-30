#include "Tablero.h"
#include <iostream>

void Tablero::cargarTrayectos() {
    trayectos.emplace_back("A", "B", Color::ROJO, 4);
    trayectos.emplace_back("H", "L", Color::ROJO, 6);
    trayectos.emplace_back("J", "N", Color::ROJO, 2);
    trayectos.emplace_back("A", "F", Color::AZUL, 4);
    trayectos.emplace_back("H", "K", Color::AZUL, 2);
    trayectos.emplace_back("I", "O", Color::AZUL, 6);
    trayectos.emplace_back("E", "F", Color::VERDE, 3);
    trayectos.emplace_back("K", "P", Color::VERDE, 3);
    trayectos.emplace_back("P", "Q", Color::VERDE, 3);
    trayectos.emplace_back("N", "O", Color::VERDE, 3);
    trayectos.emplace_back("I", "K", Color::MORADO, 4);
    trayectos.emplace_back("Q", "M", Color::MORADO, 4);
    trayectos.emplace_back("O", "R", Color::MORADO, 4);
    trayectos.emplace_back("D", "E", Color::CAFE, 4);
    trayectos.emplace_back("G", "C", Color::CAFE, 4);
    trayectos.emplace_back("Q", "S", Color::CAFE, 4);
    trayectos.emplace_back("F", "G", Color::NARANJA, 3);
    trayectos.emplace_back("O", "P", Color::NARANJA, 3);
    trayectos.emplace_back("F", "H", Color::NARANJA, 2);
    trayectos.emplace_back("K", "L", Color::NARANJA, 3);
    
}

void Tablero::mostrarTrayectos() const {
    for (const auto& t : trayectos) {
        std::cout << t.getOrigen() << " - " << t.getDestino()
                  << " | Color: " << t.getColor()
                  << " | Longitud: " << t.getLongitud()
                  << " | Ocupado por: " << (t.estaOcupado() ? std::to_string(t.getOcupadoPor()) : "Libre")
                  << std::endl;
    }
}

std::vector<Trayecto>& Tablero::getTrayectos() {
    return trayectos;
}

Trayecto* Tablero::buscarTrayecto(std::string origen, std::string destino) {
    for (auto& t : trayectos) {
        if ((t.getOrigen() == origen && t.getDestino() == destino) ||
            (t.getOrigen() == destino && t.getDestino() == origen)) {
            return &t;
        }
    }
    return nullptr;
}
