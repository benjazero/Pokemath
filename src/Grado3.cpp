#include "Grado3.h"
#include "PreguntasGrado3.h"
#include <cstdlib>

Grado3::Grado3() : Grado("Grado 3 - Avanzado", 5) {}

std::unique_ptr<Pregunta> Grado3::generarPregunta() {
    int tipo = rand() % numeroPosible + 1;
    std::unique_ptr<Pregunta> p;
    switch (tipo) {
        case 1: p = std::make_unique<PreguntaCuadratica>();        break;
        case 2: p = std::make_unique<PreguntaPotencia>();          break;
        case 3: p = std::make_unique<PreguntaSistemaEcuaciones>(); break;
        case 4: p = std::make_unique<PreguntaRaizCuadrada>();      break;
        case 5: p = std::make_unique<PreguntaLogaritmo>();         break;
        default: p = std::make_unique<PreguntaPotencia>();         break;
    }
    p->generar();
    return p;
}
