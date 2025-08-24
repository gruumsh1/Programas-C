/*MHLC_U3_EA_PAVR Este programa calcula las sucesiones de Fibonacci
para  n numeros */

// Programa 1: Serie de Fibonacci
#include <stdio.h>

int main() {
    int n, i;
    // se definen los valores de las primeras iteraciones
    long long a = 0, b = 1, c;

    // Pedir al usuario el número de términos
    printf("Ingrese el número de términos de Fibonacci a mostrar: ");
    scanf("%d", &n);

    // Validar entrada para comprobar que no se ingrese algun número negativo
    if (n <= 0) {
        printf("Por favor, ingrese un número mayor que 0.\n");
        return 1;
    }

    // Mostrar los primeros términos según n
    printf("Serie de Fibonacci (%d términos):\n", n);
    if (n >= 1) printf("%lld\n ", a);
    if (n >= 2) printf("%lld\n ", b);

    // Generar y mostrar los siguientes términos se agrega \n para que impriman en forma tabular
    for (i = 3; i <= n; i++) {
        c = a + b;
        printf("%lld\n ", c);
        a = b;
        b = c;
    }

    printf("\n");
    return 0;
}