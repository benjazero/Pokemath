#include "Pregunta.h"
#include <iostream>

// Archivo que implementa las funciones de la clase Pregunta.
// Se encarga de mostrar preguntas, recibir respuestas
// y comprobar si son correctas.

Pregunta::Pregunta()
    : respuestaCorrecta(0.0f), tolerancia(0.01f) {}

bool Pregunta::hacerYVerificar() const {
    float respuesta;
    std::cin >> respuesta;
    return esCorrecta(respuesta);
}

int Pregunta::cantidadRespuestas() const {
    return 1;
}

bool Pregunta::verificarRespuestas(float respuesta1, float) const {
    return esCorrecta(respuesta1);
}

std::string Pregunta::getEnunciado() const { return enunciado; }
float Pregunta::getRespuestaCorrecta() const { return respuestaCorrecta; }

bool Pregunta::esCorrecta(float respuesta) const {
    return respuesta >= respuestaCorrecta - tolerancia &&
           respuesta <= respuestaCorrecta + tolerancia;
}
