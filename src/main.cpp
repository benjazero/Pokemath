#include <cstdlib>
#include <ctime>
#include "Menu.h"

// Archivo principal del programa.
// Inicializa valores aleatorios y ejecuta
// el menú principal del juego.

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Menu menu;
    menu.iniciar();
    return 0;
}
