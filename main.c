#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrarMenuPrincipal() {
    printf("╔══════════════════════════╗\n");
    printf("║        POKEMATH          ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║  1. Jugar                ║\n");
    printf("║  2. Instrucciones        ║\n");
    printf("║  3. Salir                ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Elige una opcion: ");
}

void mostrarInstrucciones() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║           INSTRUCCIONES              ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ - Responde correctamente para atacar ║\n");
    printf("║ - Si fallas, recibes daño            ║\n");
    printf("║ - Gana quien deje al otro en 0 HP    ║\n");
    printf("║ - Grado 1: Operaciones basicas       ║\n");
    printf("║ - Grado 2: Operaciones intermedias   ║\n");
    printf("║ - Grado 3: Operaciones avanzadas     ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\nPresiona Enter para volver...");
    getchar(); getchar();
}

void seleccionarGrado(char nombre[], char nombre_rival[]) {
    int grado;
    float vida = 100, vida_rival = 100;
    float resultado;

    printf("\n╔══════════════════════════╗\n");
    printf("║   SELECCIONA TU GRADO   ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║  1. Grado 1 - Basico    ║\n");
    printf("║  2. Grado 2 - Medio     ║\n");
    printf("║  3. Grado 3 - Avanzado  ║\n");
    printf("╚══════════════════════════╝\n");
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
            printf("Grado 3 aun no implementado\n");
            return;
        default:
            printf("Grado invalido\n");
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

    printf("Hola! Cual es tu nombre?: ");
    scanf("%49s", nombre);
    printf("Cual es el nombre de tu rival?: ");
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
                printf("\nHasta luego %s!\n", nombre);
                break;
            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 3);

    return 0;
}
