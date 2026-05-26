#ifndef PREGUNTAS_GRADO3_H
#define PREGUNTAS_GRADO3_H

#include "Pregunta.h"

class PreguntaCuadratica : public Pregunta {
private:
    int raiz1, raiz2;
public:
    void generar() override;
    bool hacerYVerificar() const override;
};

class PreguntaPotencia : public Pregunta {
public:
    void generar() override;
};

class PreguntaSistemaEcuaciones : public Pregunta {
private:
    float solX, solY;
    int a1, b1, c1, a2, b2, c2;
public:
    void generar() override;
    bool hacerYVerificar() const override;
};

class PreguntaRaizCuadrada : public Pregunta {
public:
    void generar() override;
};

class PreguntaLogaritmo : public Pregunta {
public:
    void generar() override;
};

#endif
