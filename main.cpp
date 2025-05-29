#include <iostream>
#include "Juego.h"

int main() {
    Juego juego;
    int numJugadores = 2;

    std::cout << "Iniciando Juego de Trenes con " << numJugadores << " jugadores..." << std::endl;
    juego.inicializar(numJugadores);
    juego.mostrarManos();

    return 0;
}
