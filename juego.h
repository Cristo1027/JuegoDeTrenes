#pragma once
#include <vector>
#include "Jugador.h"

class Juego {
private:
    std::vector<Jugador> jugadores;
    std::vector<Carta> baraja;

public:
    void inicializar(int cantidadJugadores);
    void mostrarManos() const;
};
