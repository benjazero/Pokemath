#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, float vidaMax)
    : nombre(nombre), vida(vidaMax), vidaMax(vidaMax), victorias(0) {}

std::string Jugador::getNombre() const { return nombre; }
float Jugador::getVida() const { return vida; }
float Jugador::getVidaMax() const { return vidaMax; }
int Jugador::getVictorias() const { return victorias; }

void Jugador::recibirDanio(float danio) {
    vida -= danio;
    if (vida < 0) vida = 0;
}

void Jugador::curar(float cantidad) {
    vida += cantidad;
    if (vida > vidaMax) vida = vidaMax;
}

void Jugador::resetearVida() { vida = vidaMax; }
void Jugador::agregarVictoria() { victorias++; }

bool Jugador::estaVivo() const { return vida > 0; }
bool Jugador::estaEnPeligro() const { return vida <= (vidaMax * 0.5f); }
