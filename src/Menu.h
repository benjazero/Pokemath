#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    std::string nombreJugador;
    std::string nombreRival;

    void limpiarPantalla() const;
    void pantallaBienvenida() const;
    void pedirNombres();
    void mostrarInstrucciones() const;
    void seleccionarGrado() const;
    void mostrarMenuPrincipal() const;

public:
    Menu() = default;
    void iniciar();
};

#endif
