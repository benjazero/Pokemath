#include "PreguntasGrado1.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

// Archivo que implementa las preguntas del Grado 1.
// Genera ejercicios matemáticos básicos y verifica
// las respuestas del jugador.

void PreguntaSuma::generar() {
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    respuestaCorrecta = static_cast<float>(a + b);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es " << a << " + " << b << "?";
    enunciado = ss.str();
}

void PreguntaResta::generar() {
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    respuestaCorrecta = static_cast<float>(a - b);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es " << a << " - " << b << "?";
    enunciado = ss.str();
}

void PreguntaMultiplicacion::generar() {
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    respuestaCorrecta = static_cast<float>(a * b);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es " << a << " * " << b << "?";
    enunciado = ss.str();
}

void PreguntaDivision::generar() {
    float a = rand() % 10 + 1;
    float b = rand() % 10 + 1;
    respuestaCorrecta = a / b;
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Cuanto es " << static_cast<int>(a) << " / " << static_cast<int>(b) << "?";
    enunciado = ss.str();
}

bool PreguntaDivision::hacerYVerificar() const {
    float respuesta;
    std::cin >> respuesta;
    if (esCorrecta(respuesta)) return true;
    return false;
}
