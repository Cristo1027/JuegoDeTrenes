#include "Juego.h"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <random>

void Juego::inicializar(int cantidadJugadores) {
    for (int i = 0; i < 12; ++i) {
        for (int c = 0; c < 6; ++c) {
            baraja.emplace_back(static_cast<Color>(c));
        }
    }

    std::shuffle(baraja.begin(), baraja.end(), std::default_random_engine(static_cast<unsigned>(time(nullptr))));

    for (int i = 1; i <= cantidadJugadores; ++i) {
        jugadores.emplace_back(i);
        for (int j = 0; j < 6; ++j) {
            jugadores.back().agregarCarta(baraja.back());
            baraja.pop_back();
        }
    }

    tablero.cargarTrayectos();
    turnoActual = 0;
    juegoTerminado = false;
}

void Juego::barajarSiEsNecesario() {
    if (baraja.empty() && !descarte.empty()) {
        std::cout << "(Barajando descarte...)\n";
        baraja = descarte;
        descarte.clear();
        std::shuffle(baraja.begin(), baraja.end(), std::default_random_engine(static_cast<unsigned>(time(nullptr))));
    }
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
    std::cout << "\n🕹️  Turno del Jugador " << jugador.getId() << ":\n";
    jugador.mostrarMano();

    std::cout << "\n¿Qué acción deseas realizar?\n";
    std::cout << "1. Robar 2 cartas\n";
    std::cout << "2. Realizar un trayecto\n> ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        barajarSiEsNecesario();
        for (int i = 0; i < 2 && !baraja.empty(); ++i) {
            jugador.agregarCarta(baraja.back());
            baraja.pop_back();
        }
    } else if (opcion == 2) {
        mostrarTrayectos();
        std::string origen, destino;
        std::cout << "Elige trayecto - Ciudad origen: ";
        std::cin >> origen;
        std::cout << "Ciudad destino: ";
        std::cin >> destino;

        Trayecto* trayecto = tablero.buscarTrayecto(origen, destino);
        if (!trayecto) {
            std::cout << "Trayecto no encontrado.\n";
        } else if (trayecto->estaOcupado()) {
            std::cout << "Este trayecto ya está ocupado.\n";
        } else {
            Color requerido = trayecto->getColor();
            int longitud = trayecto->getLongitud();

            if (jugador.contarCartasColor(requerido) >= longitud && jugador.getVagones() >= longitud) {
                std::vector<Carta> usadas = jugador.removerCartasColorYObtener(requerido, longitud);
                descarte.insert(descarte.end(), usadas.begin(), usadas.end());

                jugador.reducirVagones(longitud);
                jugador.sumarPuntos(trayecto->calcularPuntos());
                trayecto->ocupar(jugador.getId());
                std::cout << "✅ Trayecto completado con éxito.\n";
            } else {
                std::cout << "❌ No tienes suficientes cartas o vagones.\n";
            }
        }
    } else {
        std::cout << "Opción inválida.\n";
    }

    if (jugador.getVagones() <= 2) {
        juegoTerminado = true;
    }

    turnoActual = (turnoActual + 1) % jugadores.size();
}

bool Juego::estaTerminado() const {
    return juegoTerminado;
}

void Juego::mostrarGanador() const {
    int maxPuntos = -1;
    int ganadorId = -1;
    for (const auto& jugador : jugadores) {
        std::cout << "Jugador " << jugador.getId() << ": " << jugador.getPuntos() << " puntos.\n";
        if (jugador.getPuntos() > maxPuntos) {
            maxPuntos = jugador.getPuntos();
            ganadorId = jugador.getId();
        }
    }
    std::cout << "🏆 El ganador es el Jugador " << ganadorId << " con " << maxPuntos << " puntos!\n";
}
