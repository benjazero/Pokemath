#ifndef GRADO_H
#define GRADO_H

#include <string>
#include <memory>
#include "Pregunta.h"

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
