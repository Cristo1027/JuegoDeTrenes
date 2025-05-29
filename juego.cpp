#include "Juego.h"
#include <ctime>
#include <algorithm>
#include <iostream>

void Juego::inicializar(int cantidadJugadores) {
    // Crear baraja con 12 cartas de cada color
    for (int i = 0; i < 12; ++i) {
        for (int c = 0; c < 6; ++c) {
            baraja.emplace_back(static_cast<Color>(c));
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));
    std::random_shuffle(baraja.begin(), baraja.end());

    // Crear jugadores y repartir cartas
    for (int i = 1; i <= cantidadJugadores; ++i) {
        jugadores.emplace_back(i);
        for (int j = 0; j < 5; ++j) {
            jugadores.back().agregarCarta(baraja.back());
            baraja.pop_back();
        }
    }

    // Inicializar tablero con trayectos
    tablero.cargarTrayectos();

    // Iniciar en el primer turno
    turnoActual = 0;
}

void Juego::mostrarManos() const {
    for (const auto& jugador : jugadores) {
        jugador.mostrarMano();
    }
}

void Juego::mostrarTrayectos() const {
    std::cout << "\nTrayectos disponibles:\n";
    tablero.mostrarTrayectos();
}
