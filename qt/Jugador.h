#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

// Esta clase define al jugador del juego, almacenando su nombre, vida y victorias.
// También permite gestionar acciones como recibir daño, curarse y verificar su estado.
// Nos ayuda a organizar la lógica del jugador dentro del sistema de combate.

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
