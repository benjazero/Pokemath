#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define ROJO     "\033[31m"
#define VERDE    "\033[32m"
#define AMARILLO "\033[33m"
#define RESET    "\033[0m"
#define NEGRITA  "\033[1m"

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
        if(vida > 50) printf(VERDE "\n Vida tuya: %.0f" RESET, vida);
        else printf(ROJO "\n Vida tuya: %.0f" RESET, vida);
        if(vida_rival > 50) printf(VERDE " | Vida rival: %.0f\n" RESET, vida_rival);
        else printf(ROJO " | Vida rival: %.0f\n" RESET, vida_rival);
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
        if(vida > 50) printf(VERDE "\n Vida tuya: %.0f" RESET, vida);
        else printf(ROJO "\n Vida tuya: %.0f" RESET, vida);
        if(vida_rival > 50) printf(VERDE " | Vida rival: %.0f\n" RESET, vida_rival);
        else printf(ROJO " | Vida rival: %.0f\n" RESET, vida_rival);
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

float grado_3(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf(AMARILLO "Se eligio el grado 3! Nivel preparatoria\n" RESET);
    do {
        int num = rand() % 5 + 1;
        switch(num) {
            case 1: {
                int r1 = rand() % 7 + 1;
                int r2 = rand() % 7 + 1;
                int b = -(r1 + r2);
                int c = r1 * r2;
                float respuesta;
                printf(AMARILLO "Ecuacion cuadratica: x^2 + (%d)x + (%d) = 0\n" RESET, b, c);
                printf(AMARILLO "Ingresa la raiz mayor: " RESET);
                scanf("%f", &respuesta);
                float mayor = (r1 > r2) ? r1 : r2;
                if(respuesta >= mayor - 0.01 && respuesta <= mayor + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! Las raices eran %d y %d\n" RESET, r1, r2); vida -= 20; }
                break;
            }
            case 2: {
                int base = rand() % 8 + 2;
                int exp  = rand() % 3 + 2;
                int resultado = 1;
                for(int i = 0; i < exp; i++) resultado *= base;
                int respuesta;
                printf(AMARILLO "Cuanto es %d^%d? " RESET, base, exp);
                scanf("%d", &respuesta);
                if(respuesta == resultado) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %d\n" RESET, resultado); vida -= 20; }
                break;
            }
            case 3: {
                int x = rand() % 5 + 1;
                int y = rand() % 5 + 1;
                int a1 = rand() % 4 + 1;
                int b1 = rand() % 4 + 1;
                int a2 = rand() % 4 + 1;
                int b2 = rand() % 4 + 1;
                int c1 = a1*x + b1*y;
                int c2 = a2*x + b2*y;
                float rx, ry;
                printf(AMARILLO "Sistema de ecuaciones:\n" RESET);
                printf(AMARILLO "  %dx + %dy = %d\n" RESET, a1, b1, c1);
                printf(AMARILLO "  %dx + %dy = %d\n" RESET, a2, b2, c2);
                printf(AMARILLO "Ingresa x: " RESET);
                scanf("%f", &rx);
                printf(AMARILLO "Ingresa y: " RESET);
                scanf("%f", &ry);
                if(rx >= x - 0.01 && rx <= x + 0.01 && ry >= y - 0.01 && ry <= y + 0.01) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La solucion era x=%d, y=%d\n" RESET, x, y); vida -= 20; }
                break;
            }
            case 4: {
                int bases[] = {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144};
                int raices[] = {2, 3,  4,  5,  6,  7,  8,  9,  10,  11,  12};
                int idx = rand() % 11;
                int respuesta;
                printf(AMARILLO "Cuanto es la raiz cuadrada de %d? " RESET, bases[idx]);
                scanf("%d", &respuesta);
                if(respuesta == raices[idx]) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %d\n" RESET, raices[idx]); vida -= 20; }
                break;
            }
            case 5: {
                int exp = rand() % 5 + 1;
                int num = 1;
                for(int i = 0; i < exp; i++) num *= 10;
                int respuesta;
                printf(AMARILLO "Cuanto es log10(%d)? " RESET, num);
                scanf("%d", &respuesta);
                if(respuesta == exp) { printf(VERDE "Correcto! atacas al rival\n" RESET); vida_rival -= 20; }
                else { printf(ROJO "Incorrecto! La respuesta era %d\n" RESET, exp); vida -= 20; }
                break;
            }
        }
        if(vida > 50) printf(VERDE "\n Vida tuya: %.0f" RESET, vida);
        else printf(ROJO "\n Vida tuya: %.0f" RESET, vida);
        if(vida_rival > 50) printf(VERDE " | Vida rival: %.0f\n" RESET, vida_rival);
        else printf(ROJO " | Vida rival: %.0f\n" RESET, vida_rival);
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
