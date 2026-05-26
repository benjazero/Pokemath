#ifndef GRADO1_H
#define GRADO1_H

#include "Grado.h"

class Grado1 : public Grado {
public:
    Grado1();
    std::unique_ptr<Pregunta> generarPregunta() override;
};

#endif
