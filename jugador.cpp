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

int Jugador::getPuntos() const {
    return puntos;
}

int Jugador::getVagones() const {
    return vagones;
}

int Jugador::contarCartasColor(Color color) const {
    int total = 0;
    for (const auto& carta : mano) {
        if (carta.getColor() == color) {
            total++;
        }
    }
    return total;
}

void Jugador::removerCartasColor(Color color, int cantidad) {
    int removidos = 0;
    for (auto it = mano.begin(); it != mano.end() && removidos < cantidad;) {
        if (it->getColor() == color) {
            it = mano.erase(it);
            removidos++;
        } else {
            ++it;
        }
    }
}

void Jugador::reducirVagones(int cantidad) {
    vagones -= cantidad;
}

void Jugador::sumarPuntos(int cantidad) {
    puntos += cantidad;
}
