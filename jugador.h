#pragma once
#include <vector>
#include "Carta.h"

class Jugador {
private:
    int id;
    std::vector<Carta> mano;
    int vagones;
    int puntos;

public:
    Jugador(int idJugador);
    void agregarCarta(const Carta& carta);
    void mostrarMano() const;
    int getId() const;
};
