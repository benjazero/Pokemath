#include "Grado.h"

Grado::Grado(const std::string& nombre, int numeroPosible)
    : nombre(nombre), numeroPosible(numeroPosible) {}

std::string Grado::getNombre() const { return nombre; }
