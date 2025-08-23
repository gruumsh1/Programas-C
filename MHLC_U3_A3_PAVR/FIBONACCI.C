/*Este programa calcula las sucesiones de Fibonacci
para  n numeros */

#include <stdio.h>
#include <math.h>

/*
 * @brief Calcula el n-ésimo número de Fibonacci usando la fórmula de Binet.
 *
 * @param n La posición en la sucesión de Fibonacci.
 * @return El valor del n-ésimo número de Fibonacci (redondeado).
 */
long long fibonacci_binet(int n) {
    if (n < 0) {
        return -1; // Valor de error para entrada negativa
    }
    const double sqrt5 = sqrt(5.0);
    double phi = (1.0 + sqrt5) / 2.0;
    double psi = (1.0 - sqrt5) / 2.0;
    
    // Utilizamos pow para calcular las potencias
    return round((pow(phi, n) - pow(psi, n)) / sqrt5);
}

int main() {
    int n;
    char continuar;

    do {
        // Pedimos al usuario que ingrese la posición deseada
        printf("Ingrese la posicion (n) en la sucesion de Fibonacci: ");
        scanf("%d", &n);

        // Validamos la entrada
        if (n < 0) {
            printf("Error: La posicion debe ser un numero no negativo.\n");
        } else {
            // Iteramos para imprimir cada término hasta n
            for (int i = 0; i <= n; i++) {
                long long resultado = fibonacci_binet(i);
                printf("F(%d) = %lld\n", i, resultado);
            }
        }
        
        // Limpiamos el buffer de entrada para evitar problemas con la lectura del caracter
        while (getchar() != '\n');

        // Preguntamos si el usuario desea continuar
        printf("\n¿Desea continuar con otro numero? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Fin del programa.\n");

    return 0;
}