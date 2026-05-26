#ifndef GRADO2_H
#define GRADO2_H

#include "Grado.h"

class Grado2 : public Grado {
public:
    Grado2();
    std::unique_ptr<Pregunta> generarPregunta() override;
};

#endif
