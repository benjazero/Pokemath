#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>

class Pregunta {
protected:
    std::string enunciado;
    float respuestaCorrecta;
    float tolerancia;

public:
    Pregunta();
    virtual ~Pregunta() = default;

    virtual void generar() = 0;
    virtual bool hacerYVerificar() const;

    std::string getEnunciado() const;
    float getRespuestaCorrecta() const;

protected:
    bool esCorrecta(float respuesta) const;
};

#endif
