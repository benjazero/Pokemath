#ifndef PREGUNTAS_GRADO2_H
#define PREGUNTAS_GRADO2_H

#include "Pregunta.h"

class PreguntaAreaTriangulo : public Pregunta {
public:
    void generar() override;
};

class PreguntaPorcentaje : public Pregunta {
public:
    void generar() override;
};

class PreguntaEcuacionLineal : public Pregunta {
public:
    void generar() override;
};

class PreguntaDivisionDecimal : public Pregunta {
public:
    void generar() override;
};

#endif
