#include "Combate.h"
#include "Colores.h"
#include <iostream>

const float Combate::DANIO_POR_RONDA = 20.0f;

Combate::Combate(Jugador& jugador, Jugador& rival, Grado& grado)
    : jugador(jugador), rival(rival), grado(grado) {}

void Combate::mostrarBarra(float vida, float vidaMax) const {
    int bloques = static_cast<int>((vida / vidaMax) * 10);
    std::cout << "[";
    for (int i = 0; i < 10; i++) {
        if (i < bloques) std::cout << VERDE << "█" << RESET;
        else             std::cout << ROJO  << "░" << RESET;
    }
    std::cout << "] " << static_cast<int>(vida) << " HP";
}

void Combate::mostrarEstados() const {
    std::cout << "\n ";
    if (!jugador.estaEnPeligro()) std::cout << VERDE;
    else                          std::cout << ROJO;
    std::cout << jugador.getNombre() << " " << RESET;
    mostrarBarra(jugador.getVida(), jugador.getVidaMax());

    std::cout << "  |  ";

    if (!rival.estaEnPeligro()) std::cout << VERDE;
    else                        std::cout << ROJO;
    std::cout << rival.getNombre() << " " << RESET;
    mostrarBarra(rival.getVida(), rival.getVidaMax());
    std::cout << "\n";
}

void Combate::iniciar() {
    std::cout << AMARILLO << "Comienza el combate en " << grado.getNombre() << "!\n" << RESET;

    while (jugador.estaVivo() && rival.estaVivo()) {
        auto pregunta = grado.generarPregunta();
        bool acerto = pregunta->hacerYVerificar();

        if (acerto) {
            std::cout << VERDE << "Correcto! Atacas al rival\n" << RESET;
            rival.recibirDanio(DANIO_POR_RONDA);
        } else {
            std::cout << ROJO << "Incorrecto! La respuesta correcta era "
                      << pregunta->getRespuestaCorrecta() << "\n" << RESET;
            jugador.recibirDanio(DANIO_POR_RONDA);
        }

        mostrarEstados();
    }

    if (!jugador.estaVivo()) {
        std::cout << ROJO << NEGRITA
                  << "\n " << rival.getNombre() << ": Yo sabia que te ganaria "
                  << jugador.getNombre() << "\n" << RESET;
        std::cout << ROJO << "\n Debes repasar para mejorar...\n" << RESET;
    } else {
        std::cout << VERDE << NEGRITA
                  << "\n " << rival.getNombre() << ": Me ganaste "
                  << jugador.getNombre() << "!\n" << RESET;
        std::cout << VERDE << "\n Felicidades maestro de Pokemath!\n" << RESET;
        jugador.agregarVictoria();
    }
}

const Jugador* Combate::obtenerGanador() const {
    if (!jugador.estaVivo()) return &rival;
    if (!rival.estaVivo())   return &jugador;
    return nullptr;
}
