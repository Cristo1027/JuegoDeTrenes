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

public:
    void inicializar(int cantidadJugadores);
    void mostrarManos() const;
    void mostrarTrayectos() const;
};
