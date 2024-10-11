#include <stdio.h>
#include <math.h>

long double pi_recursivo(int n, int k, long double *resultado) {
    if (k >= n) return 0.0;

    long double numerador = tgamma(4 * k + 1) * (1103 + 26390 * k);
    long double denominador = pow(tgamma(k + 1), 4) * pow(396, 4 * k);

    if (denominador != 0.0) {
        *resultado += numerador / denominador;
    }

    return pi_recursivo(n, k + 1, resultado);
}

long double pi_iterativo(int n) {
    long double suma = 0.0;
    for (int k = 0; k < n; k++) {
        long double numerador = tgamma(4 * k + 1) * (1103 + 26390 * k);
        long double denominador = pow(tgamma(k + 1), 4) * pow(396, 4 * k);
        if (denominador != 0.0) {
            suma += numerador / denominador;
        } else {
            break;
        }
    }
    long double resultado = (2 * sqrt(2) / 9801) * suma;
    return 1.0 / resultado;
}

int main() {
    int n = 20;
    long double resultado = 0.0;
    pi_recursivo(n, 0, &resultado);
    long double pi_rec = (2 * sqrt(2) / 9801) * resultado;
    pi_rec = 1.0 / pi_rec;
    printf("Valor aproximado de pi (recursivo): %.50Lf\n", pi_rec);

    long double pi_iter = pi_iterativo(n);
    printf("Valor aproximado de pi (iterativo): %.50Lf\n", pi_iter);

    return 0;
}
