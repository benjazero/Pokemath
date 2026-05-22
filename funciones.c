#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float grado_1(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf("Se eligio el grado 1!\n");
    do {
        int num = rand() % 4 + 1;
        switch(num) {
            case 1: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf("Cuanto es %d + %d? ", a, b);
                scanf("%d", &respuesta);
                if(respuesta == a + b) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! te danan\n"); vida -= 20; }
                break;
            }
            case 2: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf("Cuanto es %d - %d? ", a, b);
                scanf("%d", &respuesta);
                if(respuesta == a - b) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! te danan\n"); vida -= 20; }
                break;
            }
            case 3: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf("Cuanto es %d * %d? ", a, b);
                scanf("%d", &respuesta);
                if(respuesta == a * b) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! te danan\n"); vida -= 20; }
                break;
            }
            case 4: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf("Cuanto es %.0f / %.0f? ", a, b);
                scanf("%f", &respuesta);
                float resultado = a / b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! La respuesta era %.2f\n", resultado); vida -= 20; }
                break;
            }
        }
        printf("\n Vida tuya: %.0f | Vida rival: %.0f\n", vida, vida_rival);
    } while(vida > 0 && vida_rival > 0);

    if(vida <= 0) {
    printf("\n %s: Yo sabía que te ganaría %s\n", nombre_rival, nombre);
    printf("\n Debes repasar para mejorar...\n");
} else {
    printf("\n %s: Me ganaste %s!\n", nombre_rival, nombre);
    printf("\n Felicidades maestro de Pokemath!\n");
}
    return vida;
}

float grado_2(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf("Se eligio el grado 2!\n");
    do {
        int num = rand() % 4 + 1;
        switch(num) {
            case 1: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf("Cual es el area de un triangulo con base %.0f y altura %.0f? ", a, b);
                scanf("%f", &respuesta);
                if(respuesta == (a * b) / 2) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! La respuesta era %.1f\n", (a * b) / 2); vida -= 20; }
                break;
            }
            case 2: {
                float a = rand() % 90 + 1;
                float b = rand() % 100 + 10;
                float respuesta;
                printf("Cuanto es el %.0f%% de %.0f? ", a, b);
                scanf("%f", &respuesta);
                float resultado = (a / 100) * b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! La respuesta era %.2f\n", resultado); vida -= 20; }
                break;
            }
            case 3: {
                int a = rand() % 9 + 1;
                int b = a * (rand() % 10 + 1);
                float respuesta;
                float x = (float)b / a;
                printf("Cual es el valor de x en %dx - %d = 0? ", a, b);
                scanf("%f", &respuesta);
                if(respuesta >= x - 0.01 && respuesta <= x + 0.01) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! La respuesta era %.0f\n", x); vida -= 20; }
                break;
            }
            case 4: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf("Cuanto es %.0f / %.0f? ", a, b);
                scanf("%f", &respuesta);
                float resultado = a / b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf("Correcto! atacas al rival\n"); vida_rival -= 20; }
                else { printf("Incorrecto! La respuesta era %.2f\n", resultado); vida -= 20; }
                break;
            }
        }
        printf("\n Vida tuya: %.0f | Vida rival: %.0f\n", vida, vida_rival);
    } while(vida > 0 && vida_rival > 0);

    if(vida <= 0) {
    printf("\n %s: Yo sabía que te ganaría %s\n", nombre_rival, nombre);
    printf("\n Debes repasar para mejorar...\n");
} else {
    printf("\n %s: Me ganaste %s!\n", nombre_rival, nombre);
    printf("\n Felicidades maestro de Pokemath!\n");
}
    return vida;
}
