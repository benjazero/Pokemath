#include "Menu.h"
#include "Combate.h"
#include "Grado1.h"
#include "Grado2.h"
#include "Grado3.h"
#include "Colores.h"
#include <iostream>
#include <limits>

// Archivo que implementa las funciones de la clase Menu.
// Se encarga de mostrar pantallas, pedir datos al jugador,
// manejar opciones e iniciar los combates.

void Menu::limpiarPantalla() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::pantallaBienvenida() const {
    limpiarPantalla();
    std::cout << AMARILLO;
    std::cout << "  ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ █████╗ ████████╗██╗  ██╗\n";
    std::cout << "  ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔══██╗╚══██╔══╝██║  ██║\n";
    std::cout << "  ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║███████║   ██║   ███████║\n";
    std::cout << "  ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██╔══██║   ██║   ██╔══██║\n";
    std::cout << "  ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║██║  ██║   ██║   ██║  ██║\n";
    std::cout << "  ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝\n";
    std::cout << RESET;
    std::cout << VERDE << "\n        Aprende matematicas batallando contra rivales!\n" << RESET;
    std::cout << AMARILLO << "  ════════════════════════════════════════════════════════════════════\n" << RESET;
    std::cout << "\n  Presiona Enter para comenzar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::pedirNombres() {
    limpiarPantalla();
    std::cout << VERDE << NEGRITA << "Hola! Cual es tu nombre?: " << RESET;
    std::cin >> nombreJugador;
    std::cout << VERDE << NEGRITA << "Cual es el nombre de tu rival?: " << RESET;
    std::cin >> nombreRival;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::mostrarMenuPrincipal() const {
    std::cout << AMARILLO << "╔══════════════════════════╗\n";
    std::cout <<             "║        POKEMATH          ║\n";
    std::cout <<             "╠══════════════════════════╣\n" << RESET;
    std::cout <<             "║  1. Jugar                ║\n";
    std::cout <<             "║  2. Instrucciones        ║\n";
    std::cout <<             "║  3. Salir                ║\n";
    std::cout << AMARILLO << "╚══════════════════════════╝\n" << RESET;
    std::cout << "Elige una opcion: ";
}

void Menu::mostrarInstrucciones() const {
    std::cout << AMARILLO << "\n╔══════════════════════════════════════╗\n";
    std::cout <<             "║           INSTRUCCIONES              ║\n";
    std::cout <<             "╠══════════════════════════════════════╣\n" << RESET;
    std::cout << "║ - Responde correctamente para atacar ║\n";
    std::cout << "║ - Si fallas, recibes danio           ║\n";
    std::cout << "║ - Gana quien deje al otro en 0 HP    ║\n";
    std::cout << "║ - Grado 1: Operaciones basicas       ║\n";
    std::cout << "║ - Grado 2: Operaciones intermedias   ║\n";
    std::cout << "║ - Grado 3: Operaciones avanzadas     ║\n";
    std::cout << AMARILLO << "╚══════════════════════════════════════╝\n" << RESET;
    std::cout << "\nPresiona Enter para volver...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::seleccionarGrado() const {
    std::cout << AMARILLO << "\n╔══════════════════════════╗\n";
    std::cout <<             "║   SELECCIONA TU GRADO   ║\n";
    std::cout <<             "╠══════════════════════════╣\n" << RESET;
    std::cout << "║  1. Grado 1 - Basico    ║\n";
    std::cout << "║  2. Grado 2 - Medio     ║\n";
    std::cout << "║  3. Grado 3 - Avanzado  ║\n";
    std::cout << AMARILLO << "╚══════════════════════════╝\n" << RESET;
    std::cout << "Tu grado: ";

    int eleccion;
    std::cin >> eleccion;

    Jugador jugador(nombreJugador);
    Jugador rival(nombreRival);

    std::unique_ptr<Grado> grado;
    switch (eleccion) {
        case 1: grado = std::make_unique<Grado1>(); break;
        case 2: grado = std::make_unique<Grado2>(); break;
        case 3: grado = std::make_unique<Grado3>(); break;
        default:
            std::cout << ROJO << "Grado invalido\n" << RESET;
            return;
    }

    Combate combate(jugador, rival, *grado);
    combate.iniciar();

    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::iniciar() {
    pantallaBienvenida();
    pedirNombres();

    int opcion = 0;
    do {
        limpiarPantalla();
        mostrarMenuPrincipal();
        std::cin >> opcion;

        switch (opcion) {
            case 1: seleccionarGrado();     break;
            case 2: mostrarInstrucciones(); break;
            case 3:
                std::cout << VERDE << "\nHasta luego " << nombreJugador << "!\n" << RESET;
                break;
            default:
                std::cout << ROJO << "Opcion invalida\n" << RESET;
        }
    } while (opcion != 3);
}
