// MHLC_U3_EA_PAVR Programa 3: Cálculo de media y desviación estándar
#include <stdio.h>
#include <math.h>  // Para sqrt()

int main() {
    int n, i;
    float suma = 0, media, varianza = 0, desviacion;
    float datos[100];  // Máximo 100 datos

    // Pedir número de datos
    printf("¿Cuántos datos desea ingresar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de datos debe ser mayor que 0.\n");
        return 1;
    }

    // Leer los datos
    printf("Ingrese %d números:\n", n);
    for (i = 0; i < n; i++) {
        printf("Dato %d: ", i+1);
        scanf("%f", &datos[i]);
        suma += datos[i];
    }

    // Calcular media
    media = suma / n;

    // Calcular varianza
    for (i = 0; i < n; i++) {
        float diferencia = datos[i] - media;
        varianza += diferencia * diferencia;
    }
    varianza /= n;

    // Calcular desviación estándar
    desviacion = sqrt(varianza);

    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    printf("Media aritmética: %.2f\n", media);
    printf("Desviación estándar: %.2f\n", desviacion);

    return 0;
}