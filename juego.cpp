#include "Juego.h"
#include <ctime>
#include <algorithm>

void Juego::inicializar(int cantidadJugadores) {
    for (int i = 0; i < 12; ++i) {
        for (int c = 0; c < 6; ++c) {
            baraja.emplace_back(static_cast<Color>(c));
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));
    std::random_shuffle(baraja.begin(), baraja.end());

    for (int i = 1; i <= cantidadJugadores; ++i) {
        jugadores.emplace_back(i);
        for (int j = 0; j < 5; ++j) {
            jugadores.back().agregarCarta(baraja.back());
            baraja.pop_back();
        }
    }
}

void Juego::mostrarManos() const {
    for (const auto& jugador : jugadores) {
        jugador.mostrarMano();
    }
}
