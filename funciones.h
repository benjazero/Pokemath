#include <stdio.h>
#include <stdlib.h>

float grado_1(float vida, float vida_rival, char nombre[], char nombre_rival[]) {
    printf("Se eligió el grado 1!\n");

    do {
        int num = rand() % 4 + 1;

        switch(num) {
            case 1: {
                int a = 2, b = 3, respuesta;
                printf("¿Cuánto es %d + %d? ", a, b);
                scanf("%d", &respuesta);

                if(respuesta == a + b) {
                    printf("Correcto! atacas al rival\n");
                    vida_rival -= 20;
                } else {
                    printf("Incorrecto! te dañan\n");
                    vida -= 20;
                }
                break;
            }
            case 2:
                printf("Ejercicio 2 pendiente\n");
                break;
            case 3:
                printf("Ejercicio 3 pendiente\n");
                break;
            case 4:
                printf("Ejercicio 4 pendiente\n");
                break;
        }

        printf("Vida tuya: %.0f | Vida rival: %.0f\n", vida, vida_rival);

    } while(vida > 0 && vida_rival > 0);

    if(vida <= 0) {
        printf("%s: Yo sabía que te ganaría %s\n", nombre_rival, nombre);
    } else {
        printf("%s: Me ganaste %s!\n", nombre_rival, nombre);
    }

    return vida;
}