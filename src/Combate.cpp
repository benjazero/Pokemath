#include "Combate.h"
#include "Colores.h"
#include <iostream>

// Bucle principal de batallas de Pokemath (Jugador vs Rival).
// Gestiona las preguntas por Grado, el daño por respuestas y la victoria.

const float Combate::DANIO_POR_RONDA = 20.0f;
const float Combate::DANIO_RACHA     = 40.0f;

Combate::Combate(Jugador& jugador, Jugador& rival, Grado& grado)
    : jugador(jugador), rival(rival), grado(grado), rachaActual(0) {}

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
    // Alerta visual: el nombre se pinta de rojo si la vida está en un nivel crítico
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

void Combate::mostrarRacha() const {
    if (rachaActual == 2)
        std::cout << AMARILLO << "  Racha x2! Una mas para golpe doble!\n" << RESET;
    else if (rachaActual >= 3)
        std::cout << AMARILLO << NEGRITA << "  RACHA x" << rachaActual << "! GOLPE DOBLE!\n" << RESET;
}

void Combate::iniciar() {
    std::cout << AMARILLO << "Comienza el combate en " << grado.getNombre() << "!\n" << RESET;
    // Bucle principal: el enfrentamiento continúa hasta que los puntos de salud de uno lleguen a 0
    while (jugador.estaVivo() && rival.estaVivo()) {
        auto pregunta = grado.generarPregunta();
        bool acerto = pregunta->hacerYVerificar();

        if (acerto) {
            rachaActual++;
            mostrarRacha();
            // Mecánica de combos: 3 o más aciertos consecutivos duplican el daño infligido
            if (rachaActual >= 3) {
                std::cout << VERDE << NEGRITA << "Correcto! GOLPE DOBLE! Atacas con " << DANIO_RACHA << " de danio!\n" << RESET;
                rival.recibirDanio(DANIO_RACHA);
            } else {
                std::cout << VERDE << "Correcto! Atacas al rival con " << DANIO_POR_RONDA << " de danio!\n" << RESET;
                rival.recibirDanio(DANIO_POR_RONDA);
            }
        } else {
            // Penalización por fallar: se reinicia el contador de combos y el jugador recibe el golpe
            std::cout << ROJO << "Incorrecto! La respuesta correcta era "
                      << pregunta->getRespuestaCorrecta() << "\n" << RESET;
            if (rachaActual > 0)
                std::cout << ROJO << "  Perdiste tu racha de " << rachaActual << "!\n" << RESET;
            rachaActual = 0;
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
    // Retorna la dirección de memoria del sobreviviente para que sepa quién ganó
    if (!jugador.estaVivo()) return &rival;
    if (!rival.estaVivo())   return &jugador;
    return nullptr;
}
