#include "Tablero.h"
#include <iostream>

void Tablero::cargarTrayectos() {
    trayectos.emplace_back("A", "B", Color::ROJO, 4);
    trayectos.emplace_back("B", "C", Color::AZUL, 3);
    trayectos.emplace_back("C", "D", Color::VERDE, 2);
    trayectos.emplace_back("D", "E", Color::MORADO, 5);
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
