#ifndef PREGUNTAS_GRADO1_H
#define PREGUNTAS_GRADO1_H

#include "Pregunta.h"

class PreguntaSuma : public Pregunta {
public:
    void generar() override;
};

class PreguntaResta : public Pregunta {
public:
    void generar() override;
};

class PreguntaMultiplicacion : public Pregunta {
public:
    void generar() override;
};

class PreguntaDivision : public Pregunta {
public:
    void generar() override;
    bool hacerYVerificar() const override;
};

#endif
