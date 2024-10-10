#include <stdio.h>

void suma(int *a, int *b, int *c){ 
    *c = *a + *b; 
}

void resta(int *a, int *b, int *c){ 
    *c = *a - *b; 
}

void multiplicacion(int *a, int *b, int *c){ 
    *c = *a * *b; 
}

void division(int *a, int *b, float *c){
    if (*b != 0) {
        *c = (float) *a / *b;
    } else {
        printf("Error división por cero.\n");
        *c = 0;
    }
}

int main() {
    int numero1, numero2, resultado;
    float rDivision;

    printf("Introduce el primer número: ");
    scanf("%d", &numero1);
    printf("Introduce el segundo número: ");
    scanf("%d", &numero2);

    suma(&numero1, &numero2, &resultado);
    printf("Suma: %d + %d = %d\n", numero1, numero2, resultado);

    resta(&numero1, &numero2, &resultado);
    printf("Resta: %d - %d = %d\n", numero1, numero2, resultado);

    multiplicacion(&numero1, &numero2, &resultado);
    printf("Multiplicación: %d * %d = %d\n", numero1, numero2, resultado);

    division(&numero1, &numero2, &rDivision);
    printf("División: %d / %d = %.2f\n", numero1, numero2, rDivision);

    return 0;
}
