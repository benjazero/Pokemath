#ifndef PREGUNTAS_GRADO2_H
#define PREGUNTAS_GRADO2_H

#include "Pregunta.h"

// Clases que representan las preguntas del Grado 2.
// Incluyen ejercicios de dificultad intermedia,
// como porcentajes, áreas y ecuaciones lineales.

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
