#ifndef GRADO3_H
#define GRADO3_H

#include "Grado.h"

// Define la estructura para generar operaciones matemáticas de nivel avanzado.

class Grado3 : public Grado {
public:
    Grado3();
    std::unique_ptr<Pregunta> generarPregunta() override;
};

#endif
