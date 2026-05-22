#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define ROJO    "\033[31m"
#define VERDE   "\033[32m"
#define AMARILLO "\033[33m"
#define RESET   "\033[0m"
#define NEGRITA "\033[1m"

float grado_1(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf(AMARILLO "Se eligio el grado 1!\n" RESET);
    do {
        int num = rand() % 4 + 1;
        switch(num) {
            case 1: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf(AMARILLO "Cuanto es %d + %d? " RESET, a, b);
                scanf("%d", &respuesta);
                if(respuesta == a + b) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! te danan\n" RESET); vida -= 20; }
                break;
            }
            case 2: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf(AMARILLO "Cuanto es %d - %d? " RESET, a, b);
                scanf("%d", &respuesta);
                if(respuesta == a - b) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! te danan\n" RESET); vida -= 20; }
                break;
            }
            case 3: {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                int respuesta;
                printf(AMARILLO "Cuanto es %d * %d? " RESET, a, b);
                scanf("%d", &respuesta);
                if(respuesta == a * b) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! te danan\n" RESET); vida -= 20; }
                break;
            }
            case 4: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf(AMARILLO "Cuanto es %.0f / %.0f? " RESET, a, b);
                scanf("%f", &respuesta);
                float resultado = a / b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %.2f\n" RESET, resultado); vida -= 20; }
                break;
            }
        }

        if(vida > 50)
            printf(VERDE "\n Vida tuya: %.0f" RESET, vida);
        else
            printf(ROJO "\n Vida tuya: %.0f" RESET, vida);

        if(vida_rival > 50)
            printf(VERDE " | Vida rival: %.0f\n" RESET, vida_rival);
        else
            printf(ROJO " | Vida rival: %.0f\n" RESET, vida_rival);

    } while(vida > 0 && vida_rival > 0);

    if(vida <= 0) {
        printf(ROJO NEGRITA "\n %s: Yo sabia que te ganaria %s\n" RESET, nombre_rival, nombre);
        printf(ROJO "\n Debes repasar para mejorar...\n" RESET);
    } else {
        printf(VERDE NEGRITA "\n %s: Me ganaste %s!\n" RESET, nombre_rival, nombre);
        printf(VERDE "\n Felicidades maestro de Pokemath!\n" RESET);
    }
    return vida;
}

float grado_2(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf(AMARILLO "Se eligio el grado 2!\n" RESET);
    do {
        int num = rand() % 4 + 1;
        switch(num) {
            case 1: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf(AMARILLO "Cual es el area de un triangulo con base %.0f y altura %.0f? " RESET, a, b);
                scanf("%f", &respuesta);
                if(respuesta == (a * b) / 2) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %.1f\n" RESET, (a * b) / 2); vida -= 20; }
                break;
            }
            case 2: {
                float a = rand() % 90 + 1;
                float b = rand() % 100 + 10;
                float respuesta;
                printf(AMARILLO "Cuanto es el %.0f%% de %.0f? " RESET, a, b);
                scanf("%f", &respuesta);
                float resultado = (a / 100) * b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %.2f\n" RESET, resultado); vida -= 20; }
                break;
            }
            case 3: {
                int a = rand() % 9 + 1;
                int b = a * (rand() % 10 + 1);
                float respuesta;
                float x = (float)b / a;
                printf(AMARILLO "Cual es el valor de x en %dx - %d = 0? " RESET, a, b);
                scanf("%f", &respuesta);
                if(respuesta >= x - 0.01 && respuesta <= x + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %.0f\n" RESET, x); vida -= 20; }
                break;
            }
            case 4: {
                float a = rand() % 10 + 1;
                float b = rand() % 10 + 1;
                float respuesta;
                printf(AMARILLO "Cuanto es %.0f / %.0f? " RESET, a, b);
                scanf("%f", &respuesta);
                float resultado = a / b;
                if(respuesta >= resultado - 0.01 && respuesta <= resultado + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %.2f\n" RESET, resultado); vida -= 20; }
                break;
            }
        }

        if(vida > 50)
            printf(VERDE "\n Vida tuya: %.0f" RESET, vida);
        else
            printf(ROJO "\n Vida tuya: %.0f" RESET, vida);

        if(vida_rival > 50)
            printf(VERDE " | Vida rival: %.0f\n" RESET, vida_rival);
        else
            printf(ROJO " | Vida rival: %.0f\n" RESET, vida_rival);

    } while(vida > 0 && vida_rival > 0);

    if(vida <= 0) {
        printf(ROJO NEGRITA "\n %s: Yo sabia que te ganaria %s\n" RESET, nombre_rival, nombre);
        printf(ROJO "\n Debes repasar para mejorar...\n" RESET);
    } else {
        printf(VERDE NEGRITA "\n %s: Me ganaste %s!\n" RESET, nombre_rival, nombre);
        printf(VERDE "\n Felicidades maestro de Pokemath!\n" RESET);
    }
    return vida;
}
