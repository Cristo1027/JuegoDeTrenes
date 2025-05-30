#pragma once
#include <vector>
#include "Trayecto.h"

class Tablero {
private:
    std::vector<Trayecto> trayectos;

public:
    void cargarTrayectos(); // carga trayectos de ejemplo
    void mostrarTrayectos() const;
    std::vector<Trayecto>& getTrayectos();
    Trayecto* buscarTrayecto(std::string origen, std::string destino);
};
