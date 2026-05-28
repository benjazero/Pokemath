#ifndef MENU_H
#define MENU_H

#include <string>

// Esta clase administra la interfaz del juego.
// Permite mostrar menús, pedir datos al usuario,
// seleccionar el grado e iniciar los combates.

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
