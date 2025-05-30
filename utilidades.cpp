#include "utilidades.h"

std::string obtenerColorANSI(Color color) {
    switch (color) {
        case Color::ROJO: return "\033[1;31m🟥 Rojo\033[0m";
        case Color::AZUL: return "\033[1;34m🟦 Azul\033[0m";
        case Color::VERDE: return "\033[1;32m🟩 Verde\033[0m";
        case Color::MORADO: return "\033[1;35m🟪 Morado\033[0m";
        case Color::CAFE: return "\033[0;33m🟫 Café\033[0m";
        case Color::NARANJA: return "\033[1;33m🟧 Naranja\033[0m";
        default: return "⬜";
    }
}
