#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main() {
    srand(time(NULL)); // SOLO AQUÍ

    float vida = 100, vida_rival = 100;
    int grado;
    char nombre[50], nombre_rival[50];

    printf("Hola, cual es tu nombre?: ");
    scanf("%49s", nombre);

    printf("Cual es el nombre de tu rival?: ");
    scanf("%49s", nombre_rival);

    printf("Ya veo te llamas %s, cual es tu grado (1,2,3): ", nombre);
    scanf("%d", &grado);

    switch(grado) {
        case 1:
            grado_1(vida, vida_rival, nombre, nombre_rival);
            break;
        case 2:
            printf("Grado 2 aun no implementado\n");
            break;
        case 3:
            printf("Grado 3 aun no implementado\n");
            break;
        default:
            printf("Ingrese un grado valido\n");
    }

    return 0;
}
