#include "Juego.h"
#include <ctime>
#include <algorithm>
#include <iostream>
#include <random>

void Juego::inicializar(int cantidadJugadores) {
    // Crear baraja con 12 cartas de cada uno de los 6 colores
    for (int i = 0; i < 12; ++i) {
        for (int c = 0; c < 6; ++c) {
            baraja.emplace_back(static_cast<Color>(c));
        }
    }

    // Barajar baraja
    std::shuffle(baraja.begin(), baraja.end(), std::default_random_engine(static_cast<unsigned>(time(nullptr))));

    // Crear jugadores y repartir 6 cartas a cada uno
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
        std::cout << "(🔁 Barajando descarte...)\n";
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
    
    std::cout << "\n============================================\n";
    std::cout << "🎮 TURNO DEL JUGADOR " << jugador.getId() << "\n";
    std::cout << "🧳 Vagones: " << jugador.getVagones()
            << "   🧮 Puntos: " << jugador.getPuntos()
            << "   🃏 Cartas: " << jugador.getCantidadCartas() << "\n";
    std::cout << "============================================\n";

    jugador.mostrarMano();


    std::cout << "\n¿Qué acción deseas realizar?\n";
    std::cout << "1. Robar 2 cartas\n";
    std::cout << "2. Realizar un trayecto\n> ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        barajarSiEsNecesario();

        int robadas = 0;
        for (int i = 0; i < 2 && !baraja.empty(); ++i) {
            Carta carta = baraja.back();
            baraja.pop_back();
            jugador.agregarCarta(carta);
            std::cout << "🃏 Carta robada: " << carta.getNombre() << std::endl;
            robadas++;
        }

        if (robadas == 0) std::cout << "⚠️  No se pudieron robar cartas. Baraja vacía.\n";
        else std::cout << "✅ Jugador " << jugador.getId() << " robó " << robadas << " carta(s).\n";
    }

    else if (opcion == 2) {
        mostrarTrayectos();

        std::string origen, destino;
        std::cout << "Elige trayecto - Ciudad origen: ";
        std::cin >> origen;
        std::cout << "Ciudad destino: ";
        std::cin >> destino;

        Trayecto* trayecto = tablero.buscarTrayecto(origen, destino);
        if (!trayecto) {
            std::cout << "❌ Trayecto no encontrado.\n";
        } else if (trayecto->estaOcupado()) {
            std::cout << "🚫 Este trayecto ya está ocupado.\n";
        } else {
            Color requerido = trayecto->getColor();
            int longitud = trayecto->getLongitud();

            if (jugador.contarCartasColor(requerido) >= longitud && jugador.getVagones() >= longitud) {
                std::vector<Carta> usadas = jugador.removerCartasColorYObtener(requerido, longitud);
                descarte.insert(descarte.end(), usadas.begin(), usadas.end());

                jugador.reducirVagones(longitud);
                jugador.sumarPuntos(trayecto->calcularPuntos());
                trayecto->ocupar(jugador.getId());

                std::cout << "🚂 Trayecto " << trayecto->getOrigen() << " - " << trayecto->getDestino()
                          << " completado por el Jugador " << jugador.getId() << ".\n";
            } else {
                std::cout << "❌ No tienes suficientes cartas del color o vagones.\n";
            }
        }
    }

    else {
        std::cout << "❌ Opción inválida. No se realiza ninguna acción.\n";
    }

    // Verificar fin de juego
    if (jugador.getVagones() <= 2) {
        std::cout << "⚠️  Jugador " << jugador.getId() << " tiene 2 o menos vagones.\n";
        juegoTerminado = true;
    }

    // Avanzar al siguiente jugador
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
    std::cout << "\n🏆 El ganador es el Jugador " << ganadorId << " con " << maxPuntos << " puntos!\n";
}
