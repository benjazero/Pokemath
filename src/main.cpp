#include <cstdlib>
#include <ctime>
#include "Menu.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Menu menu;
    menu.iniciar();
    return 0;
}
