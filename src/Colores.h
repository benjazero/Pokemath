#ifndef COLORES_H
#define COLORES_H

namespace Colores {
    constexpr const char* ROJO     = "\033[31m";
    constexpr const char* VERDE    = "\033[32m";
    constexpr const char* AMARILLO = "\033[33m";
    constexpr const char* RESET    = "\033[0m";
    constexpr const char* NEGRITA  = "\033[1m";
}
//se agregan colores para una mejora visual al usuario y un mayor disfrute//
#define ROJO     Colores::ROJO
#define VERDE    Colores::VERDE
#define AMARILLO Colores::AMARILLO
#define RESET    Colores::RESET
#define NEGRITA  Colores::NEGRITA

#endif
