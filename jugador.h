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
    int getPuntos() const;
    int getVagones() const;
    int getCantidadCartas() const;

    int contarCartasColor(Color color) const;
    void removerCartasColor(Color color, int cantidad);
    std::vector<Carta> removerCartasColorYObtener(Color color, int cantidad);

    void reducirVagones(int cantidad);
    void sumarPuntos(int cantidad);
};
