#include "PreguntasGrado3.h"
#include "Colores.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

void PreguntaCuadratica::generar() {
    raiz1 = rand() % 7 + 1;
    raiz2 = rand() % 7 + 1;
    int b  = -(raiz1 + raiz2);
    int c  = raiz1 * raiz2;
    respuestaCorrecta = static_cast<float>(raiz1 > raiz2 ? raiz1 : raiz2);
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Ecuacion cuadratica: x^2 + (" << b << ")x + (" << c << ") = 0\nIngresa la raiz mayor:";
    enunciado = ss.str();
}

bool PreguntaCuadratica::hacerYVerificar() const {
    std::cout << AMARILLO << "\n" << enunciado << " " << RESET;
    float respuesta;
    std::cin >> respuesta;
    if (esCorrecta(respuesta)) return true;
    std::cout << ROJO << "Incorrecto! Las raices eran " << raiz1 << " y " << raiz2 << "\n" << RESET;
    return false;
}

void PreguntaPotencia::generar() {
    int base = rand() % 8 + 2;
    int exp  = rand() % 3 + 2;
    int resultado = 1;
    for (int i = 0; i < exp; i++) resultado *= base;
    respuestaCorrecta = static_cast<float>(resultado);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es " << base << "^" << exp << "?";
    enunciado = ss.str();
}

void PreguntaSistemaEcuaciones::generar() {
    solX = rand() % 5 + 1;
    solY = rand() % 5 + 1;
    a1 = rand() % 4 + 1;
    b1 = rand() % 4 + 1;
    a2 = rand() % 4 + 1;
    b2 = rand() % 4 + 1;
    c1 = a1 * static_cast<int>(solX) + b1 * static_cast<int>(solY);
    c2 = a2 * static_cast<int>(solX) + b2 * static_cast<int>(solY);
    tolerancia = 0.01f;
    std::ostringstream ss;
    ss << "Sistema de ecuaciones:\n  " << a1 << "x + " << b1 << "y = " << c1
       << "\n  " << a2 << "x + " << b2 << "y = " << c2;
    enunciado = ss.str();
}

bool PreguntaSistemaEcuaciones::hacerYVerificar() const {
    std::cout << AMARILLO << "\n" << enunciado << "\n" << RESET;
    float rx, ry;
    std::cout << AMARILLO << "Ingresa x: " << RESET;
    std::cin >> rx;
    std::cout << AMARILLO << "Ingresa y: " << RESET;
    std::cin >> ry;
    bool xOk = rx >= solX - tolerancia && rx <= solX + tolerancia;
    bool yOk = ry >= solY - tolerancia && ry <= solY + tolerancia;
    if (xOk && yOk) return true;
    std::cout << ROJO << "Incorrecto! La solucion era x=" << static_cast<int>(solX)
              << ", y=" << static_cast<int>(solY) << "\n" << RESET;
    return false;
}

void PreguntaRaizCuadrada::generar() {
    const int bases[]  = {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144};
    const int raices[] = {2, 3,  4,  5,  6,  7,  8,  9,  10,  11,  12};
    int idx = rand() % 11;
    respuestaCorrecta = static_cast<float>(raices[idx]);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es la raiz cuadrada de " << bases[idx] << "?";
    enunciado = ss.str();
}

void PreguntaLogaritmo::generar() {
    int exp = rand() % 5 + 1;
    int num = 1;
    for (int i = 0; i < exp; i++) num *= 10;
    respuestaCorrecta = static_cast<float>(exp);
    tolerancia = 0.0f;
    std::ostringstream ss;
    ss << "Cuanto es log10(" << num << ")?";
    enunciado = ss.str();
}
