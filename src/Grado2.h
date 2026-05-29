#ifndef GRADO2_H
#define GRADO2_H

#include "Grado.h"

// Define la estructura para generar operaciones matemáticas de nivel intermedio.

class Grado2 : public Grado {
public:
    Grado2();
    std::unique_ptr<Pregunta> generarPregunta() override;
};

#endif
