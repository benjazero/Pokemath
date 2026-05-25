#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

#define AMARILLO "\033[33m"
#define VERDE    "\033[32m"
#define ROJO     "\033[31m"
#define RESET    "\033[0m"
#define NEGRITA  "\033[1m"

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrarMenuPrincipal() {
    printf(AMARILLO "╔══════════════════════════╗\n");
    printf(        "║        POKEMATH          ║\n");
    printf(        "╠══════════════════════════╣\n" RESET);
    printf(        "║  1. Jugar                ║\n");
    printf(        "║  2. Instrucciones        ║\n");
    printf(        "║  3. Salir                ║\n");
    printf(AMARILLO "╚══════════════════════════╝\n" RESET);
    printf("Elige una opcion: ");
}

void mostrarInstrucciones() {
    printf(AMARILLO "\n╔══════════════════════════════════════╗\n");
    printf(         "║           INSTRUCCIONES              ║\n");
    printf(         "╠══════════════════════════════════════╣\n" RESET);
    printf("║ - Responde correctamente para atacar ║\n");
    printf("║ - Si fallas, recibes daño            ║\n");
    printf("║ - Gana quien deje al otro en 0 HP    ║\n");
    printf("║ - Grado 1: Operaciones basicas       ║\n");
    printf("║ - Grado 2: Operaciones intermedias   ║\n");
    printf("║ - Grado 3: Operaciones avanzadas     ║\n");
    printf(AMARILLO "╚══════════════════════════════════════╝\n" RESET);
    printf("\nPresiona Enter para volver...");
    getchar(); getchar();
}

void seleccionarGrado(char nombre[], char nombre_rival[]) {
    int grado;
    float vida = 100, vida_rival = 100;
    float resultado;

    printf(AMARILLO "\n╔══════════════════════════╗\n");
    printf(         "║   SELECCIONA TU GRADO   ║\n");
    printf(         "╠══════════════════════════╣\n" RESET);
    printf("║  1. Grado 1 - Basico    ║\n");
    printf("║  2. Grado 2 - Medio     ║\n");
    printf("║  3. Grado 3 - Avanzado  ║\n");
    printf(AMARILLO "╚══════════════════════════╝\n" RESET);
    printf("Tu grado: ");
    scanf("%d", &grado);

    switch(grado) {
        case 1:
            resultado = grado_1(vida, vida_rival, nombre, nombre_rival);
            break;
        case 2:
            resultado = grado_2(vida, vida_rival, nombre, nombre_rival);
            break;
        case 3:
            resultado = grado_3(vida, vida_rival, nombre, nombre_rival);
            break;
        default:
            printf(ROJO "Grado invalido\n" RESET);
            return;
    }

    printf("\nPresiona Enter para continuar...");
    getchar();
    getchar();
}

int main() {
    srand(time(NULL));

    int opcion;
    char nombre[50], nombre_rival[50];

    printf(VERDE NEGRITA "Hola! Cual es tu nombre?: " RESET);
    scanf("%49s", nombre);
    printf(VERDE NEGRITA "Cual es el nombre de tu rival?: " RESET);
    scanf("%49s", nombre_rival);

    do {
        limpiarPantalla();
        mostrarMenuPrincipal();
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                seleccionarGrado(nombre, nombre_rival);
                break;
            case 2:
                mostrarInstrucciones();
                break;
            case 3:
                printf(VERDE "\nHasta luego %s!\n" RESET, nombre);
                break;
            default:
                printf(ROJO "Opcion invalida\n" RESET);
        }

    } while(opcion != 3);

    return 0;
}
