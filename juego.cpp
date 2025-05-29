#include "Juego.h"
#include <ctime>
#include <algorithm>
#include <iostream>

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

    tablero.cargarTrayectos();
    turnoActual = 0;
    juegoTerminado = false;
}

void Juego::mostrarManos() const {
    for (const auto& jugador : jugadores) {
        jugador.mostrarMano();
    }
}

void Juego::mostrarTrayectos() const {
    tablero.mostrarTrayectos();
}

void Juego::jugarTurno() {
    Jugador& jugador = jugadores[turnoActual];
    std::cout << "\nTurno del jugador " << jugador.getId() << ":\n";
    jugador.mostrarMano();

    std::cout << "Elige acción:\n1. Robar 2 cartas\n2. Realizar un trayecto\n> ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        for (int i = 0; i < 2; ++i) {
            barajarSiEsNecesario();
            if (!baraja.empty()) {
                jugador.agregarCarta(baraja.back());
                baraja.pop_back();
            }
        }
    } else if (opcion == 2) {
        mostrarTrayectos();
        std::string origen, destino;
        std::cout << "Origen: "; std::cin >> origen;
        std::cout << "Destino: "; std::cin >> destino;

        Trayecto* trayecto = tablero.buscarTrayecto(origen, destino);
        if (trayecto && !trayecto->estaOcupado()) {
            // Verificar si tiene suficientes cartas del color requerido
            Color requerido = trayecto->getColor();
            int necesarios = trayecto->getLongitud();
            int disponibles = jugador.contarCartasColor(requerido);

            if (disponibles >= necesarios) {
                jugador.removerCartasColor(requerido, necesarios);
                trayecto->ocupar(jugador.getId());
                jugador.sumarPuntos(trayecto->calcularPuntos());
                jugador.reducirVagones(trayecto->getLongitud());

                std::cout << "Trayecto completado con éxito.\n";
            } else {
                std::cout << "No tienes suficientes cartas del color requerido.\n";
            }
        } else {
            std::cout << "Trayecto inválido u ocupado.\n";
        }
    } else {
        std::cout << "Opción inválida.\n";
    }

    // Condición de fin
    if (jugador.getVagones() < 5) {
        juegoTerminado = true;
    }

    turnoActual = (turnoActual + 1) % jugadores.size();
}

bool Juego::estaTerminado() const {
    return juegoTerminado;
}

void Juego::mostrarGanador() const {
    int maxPuntos = -1;
    int ganador = -1;

    for (const auto& j : jugadores) {
        std::cout << "Jugador " << j.getId() << ": " << j.getPuntos() << " puntos.\n";
        if (j.getPuntos() > maxPuntos) {
            maxPuntos = j.getPuntos();
            ganador = j.getId();
        }
    }

    std::cout << "🏆 Ganador: Jugador " << ganador << " con " << maxPuntos << " puntos!\n";
}

void Juego::barajarSiEsNecesario() {
    if (baraja.empty() && !descarte.empty()) {
        std::cout << "(Barajando descarte...)\n";
        baraja = descarte;
        descarte.clear();
        std::random_shuffle(baraja.begin(), baraja.end());
    }
}
