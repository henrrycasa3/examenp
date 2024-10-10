#include <stdio.h>

int suma(int a, int b){ return a + b; }

int resta(int a, int b){return a - b; }

int multiplicacion(int a, int b){ return a * b;}

float division(int a, int b){
    if (b != 0) {
       return (float) a / b;
    }else{
        printf("Error División por cero.\n");
    return 0;}
}

int main() {
    int numero1, numero2;
    printf("Introduce el primer número: ");
    scanf("%d", &numero1);
    printf("Introduce el segundo número: ");
    scanf("%d", &numero2);

    printf("Suma: %d+%d = %d\n", numero1, numero2, suma(numero1, numero2));
    printf("Resta: %d-%d = %d\n", numero1, numero2, resta(numero1, numero2));
    printf("Multiplicación: %d * %d = %d\n", numero1, numero2, multiplicacion(numero1, numero2));

    printf("División: %d/%d = %.2f\n", numero1, numero2, division(numero1, numero2));

    return 0;
}
