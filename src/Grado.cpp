#include "Grado.h"

// Implementa la lógica de los niveles de dificultad en Pokemath.
// Se encarga de generar y gestionar las preguntas matemáticas aleatorias según el grado.
Grado::Grado(const std::string& nombre, int numeroPosible)
    : nombre(nombre), numeroPosible(numeroPosible) {}

std::string Grado::getNombre() const { return nombre; }
