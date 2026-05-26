#include "Pregunta.h"
#include "Colores.h"
#include <iostream>

Pregunta::Pregunta()
    : respuestaCorrecta(0.0f), tolerancia(0.01f) {}

bool Pregunta::hacerYVerificar() const {
    std::cout << AMARILLO << "\n" << enunciado << " " << RESET;
    float respuesta;
    std::cin >> respuesta;
    return esCorrecta(respuesta);
}

std::string Pregunta::getEnunciado() const { return enunciado; }
float Pregunta::getRespuestaCorrecta() const { return respuestaCorrecta; }

bool Pregunta::esCorrecta(float respuesta) const {
    return respuesta >= respuestaCorrecta - tolerancia &&
           respuesta <= respuestaCorrecta + tolerancia;
}
