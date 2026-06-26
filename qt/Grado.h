#ifndef GRADO_H
#define GRADO_H

#include <string>
#include <memory>
#include "Pregunta.h"

// Declaración de la clase base Grado para los niveles de dificultad.
// Define la estructura principal que generará las preguntas matemáticas.

class Grado {
protected:
    std::string nombre;
    int numeroPosible;

public:
    explicit Grado(const std::string& nombre, int numeroPosible);
    virtual ~Grado() = default;

    virtual std::unique_ptr<Pregunta> generarPregunta() = 0;
    std::string getNombre() const;
};

#endif
