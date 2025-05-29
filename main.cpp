#include <iostream>
#include "Juego.h"

int main() {
    Juego juego;

    std::cout << "Iniciando Juego de Trenes..." << std::endl;
    juego.inicializar(2); // 2 jugadores para pruebas

    std::cout << "\nManos de los jugadores:\n";
    juego.mostrarManos();

    std::cout << "\nTrayectos disponibles:\n";
    juego.mostrarTrayectos();

    return 0;
}
