#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    float vida;
    float vidaMax;
    int victorias;

public:
    Jugador(const std::string& nombre, float vidaMax = 100.0f);

    std::string getNombre() const;
    float getVida() const;
    float getVidaMax() const;
    int getVictorias() const;

    void recibirDanio(float danio);
    void curar(float cantidad);
    void resetearVida();
    void agregarVictoria();

    bool estaVivo() const;
    bool estaEnPeligro() const;
};

#endif
