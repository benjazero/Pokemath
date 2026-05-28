#ifndef MENU_H
#define MENU_H

#include <string>

// Clase encargada de controlar la interfaz del juego.
// Gestiona los menús, la interacción con el usuario,
// la selección de grado y el inicio de las partidas.

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
