#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int idJugador) : id(idJugador), vagones(18), puntos(0) {}

void Jugador::agregarCarta(const Carta& carta) {
    mano.push_back(carta);
}

void Jugador::mostrarMano() const {
    std::cout << "Jugador " << id << " tiene: ";
    for (const Carta& carta : mano) {
        std::cout << carta.getNombre() << " ";
    }
    std::cout << std::endl;
}

int Jugador::getId() const {
    return id;
}
