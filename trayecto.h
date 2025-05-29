#pragma once
#include <string>
#include "Carta.h"

class Trayecto {
private:
    std::string origen;
    std::string destino;
    Color colorRequerido;
    int longitud;
    int ocupadoPor; // -1 = libre, otro = id del jugador

public:
    Trayecto(std::string o, std::string d, Color c, int l);

    std::string getOrigen() const;
    std::string getDestino() const;
    Color getColor() const;
    int getLongitud() const;
    int getOcupadoPor() const;
    bool estaOcupado() const;
    int calcularPuntos() const;
    void ocupar(int jugadorId);
};
