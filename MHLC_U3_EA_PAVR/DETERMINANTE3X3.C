
// MHLC_U3_EA_PAVR Programa 2: Cálculo del determinante de una matriz 3x3 metodo Sarrus
#include <stdio.h>

int main() {
    float matriz[3][3];
    int i, j;
    float determinante;

    // Leer la matriz 3x3, el programa solo acepta numeros con "." si se coloca coma "," marcara error
    printf("Ingrese los elementos de la matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            int resultado = scanf("%f", &matriz[i][j]);
            if (resultado != 1) {
                printf("Error: entrada inválida. Asegúrate de usar números con punto decimal.\n");
                return 1;
            }
        }
    }

    // Mostrar la matriz ingresada (para depuración)
    printf("\nMatriz ingresada:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Calcular determinante usando regla de Sarrus
    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
        - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
        + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    // Mostrar resultado
    printf("\nEl determinante de la matriz es: %.2f\n", determinante);

    return 0;
}
