#include "Grado1.h"
#include "PreguntasGrado1.h"
#include <cstdlib>

// Implementación del nivel básico de dificultad.
// Se encarga de generar preguntas de operaciones matemáticas básicas.

Grado1::Grado1() : Grado("Grado 1 - Basico", 4) {}

std::unique_ptr<Pregunta> Grado1::generarPregunta() {
    int tipo = rand() % numeroPosible + 1;
    std::unique_ptr<Pregunta> p;
    switch (tipo) {
        case 1: p = std::make_unique<PreguntaSuma>();           break;
        case 2: p = std::make_unique<PreguntaResta>();          break;
        case 3: p = std::make_unique<PreguntaMultiplicacion>(); break;
        case 4: p = std::make_unique<PreguntaDivision>();       break;
        default: p = std::make_unique<PreguntaSuma>();          break;
    }
    p->generar();
    return p;
}
