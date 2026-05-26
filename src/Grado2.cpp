#include "Grado2.h"
#include "PreguntasGrado2.h"
#include <cstdlib>

Grado2::Grado2() : Grado("Grado 2 - Intermedio", 4) {}

std::unique_ptr<Pregunta> Grado2::generarPregunta() {
    int tipo = rand() % numeroPosible + 1;
    std::unique_ptr<Pregunta> p;
    switch (tipo) {
        case 1: p = std::make_unique<PreguntaAreaTriangulo>();   break;
        case 2: p = std::make_unique<PreguntaPorcentaje>();      break;
        case 3: p = std::make_unique<PreguntaEcuacionLineal>();  break;
        case 4: p = std::make_unique<PreguntaDivisionDecimal>(); break;
        default: p = std::make_unique<PreguntaAreaTriangulo>();  break;
    }
    p->generar();
    return p;
}
