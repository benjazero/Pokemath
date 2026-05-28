#include "PreguntasGrado2.h"
#include <cstdlib>
#include <sstream>

// Archivo que implementa las preguntas del Grado 2.
// Genera ejercicios matemáticos intermedios
// y calcula sus respuestas correctas.

void PreguntaAreaTriangulo::generar() {
    float base   = rand() % 10 + 1;
    float altura = rand() % 10 + 1;
    respuestaCorrecta = (base * altura) / 2.0f;
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Cual es el area de un triangulo con base " << static_cast<int>(base)
       << " y altura " << static_cast<int>(altura) << "?";
    enunciado = ss.str();
}

void PreguntaPorcentaje::generar() {
    float porcentaje = rand() % 90 + 1;
    float numero     = rand() % 100 + 10;
    respuestaCorrecta = (porcentaje / 100.0f) * numero;
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Cuanto es el " << static_cast<int>(porcentaje)
       << "% de " << static_cast<int>(numero) << "?";
    enunciado = ss.str();
}

void PreguntaEcuacionLineal::generar() {
    int a = rand() % 9 + 1;
    int b = a * (rand() % 10 + 1);
    respuestaCorrecta = static_cast<float>(b) / static_cast<float>(a);
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Cual es el valor de x en " << a << "x - " << b << " = 0?";
    enunciado = ss.str();
}

void PreguntaDivisionDecimal::generar() {
    float a = rand() % 10 + 1;
    float b = rand() % 10 + 1;
    respuestaCorrecta = a / b;
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Cuanto es " << static_cast<int>(a) << " / " << static_cast<int>(b) << "?";
    enunciado = ss.str();
}
