#ifndef GRADO3_H
#define GRADO3_H

#include "Grado.h"

class Grado3 : public Grado {
public:
    Grado3();
    std::unique_ptr<Pregunta> generarPregunta() override;
};

#endif
