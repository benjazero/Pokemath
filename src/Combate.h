#ifndef COMBATE_H
#define COMBATE_H

#include "Jugador.h"
#include "Grado.h"
#include <memory>

class Combate {
private:
    Jugador& jugador;
    Jugador& rival;
    Grado&   grado;

    static const float DANIO_POR_RONDA;
    static const float DANIO_RACHA;
    int rachaActual;

    void mostrarBarra(float vida, float vidaMax) const;
    void mostrarEstados() const;
    void mostrarRacha() const;

public:
    Combate(Jugador& jugador, Jugador& rival, Grado& grado);

    void iniciar();
    const Jugador* obtenerGanador() const;
};

#endif
