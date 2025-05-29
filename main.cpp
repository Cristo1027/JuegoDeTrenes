#include <iostream>
#include "Juego.h"

int main() {
    Juego juego;
    juego.inicializar(2);

    while (!juego.estaTerminado()) {
        juego.jugarTurno();
    }

    std::cout << "\nJuego terminado.\n";
    juego.mostrarGanador();

    return 0;
}
