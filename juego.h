#pragma once
#include <vector>
#include "Jugador.h"
#include "Carta.h"
#include "Tablero.h"

class Juego {
private:
    std::vector<Jugador> jugadores;
    std::vector<Carta> baraja;
    std::vector<Carta> descarte;
    Tablero tablero;
    int turnoActual;
    bool juegoTerminado;

    void barajarSiEsNecesario();

public:
    void inicializar(int cantidadJugadores);
    void mostrarManos() const;
    void mostrarTrayectos() const;
    void jugarTurno();
    bool estaTerminado() const;
    void mostrarGanador() const;
};
