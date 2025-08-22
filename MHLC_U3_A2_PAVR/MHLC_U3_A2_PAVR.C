#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MONTO:MINIMO_DESCUENTO 500.0
#define PORCENTAJE_DESCUENTO 0.10
#define MAX_ARTICULOS 100

typedef struct {
    float precio;
    int cantidad;
    float subtotal;
} Articulo;

void mostrarEncabezado();
int menuPrincipal();
void procesarVenta();
Articulo solicitarArticulo();
void mostrarTicket(Articulo articulos[], int totalArticulos, float totalCompra);
char solicitarContinuacion();

int main(){
    mostrarEncabezado();

    int opcion;

    do {
        opcion = menuPrincipal();

        switch(opcion) {
            case 1:
                procesarVenta();
                break;
            case 2:
                printf("\nSaliendo del sistema...\n");
                break;
            default:
                printf ("\nOpción no válida. Intente nuevamente.\n"); 
        }

    } while (opcion != 2);

    printf("\n=============================================\n");
    printf("    ¡Gracias por usar nuestro sistema!\n");
    printf("=============================================\n");

    return 0;
}

void mostrarEncabezado() {
    printf("=============================================\n");
    printf("    TIENDA DE ABARROTES - SISTEMA DE VENTAS\n");
    printf("=============================================\n\n");
}

int menuPrincipal(){
    int opcion;

    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Iniciar nueva venta\n");
    printf("2. Salir del sistema\n");
    printf("Seleccione una opción: ");

    if (scanf("%d", &opcion) !=1){

        while (getchar() != '\n');
        return -1;
        
    }

    return opcion;
}

void procesarVenta(){
    Articulo articulos[MAX_ARTICULOS];
    int totalArticulos = 0;
    float totalCompra = 0.0;
    char continuar;

    printf("\n--- NUEVA VENTA ---\n");
    printf("Ingrese los artículos uno por uno:\n\n");

    do {
        if (totalArticulos >= MAX_ARTICULOS) {
            printf("¡ Límite máximo de artículos alcanzado!\n");
            break;
        }

        printf("Artículo #%d:\n", totalArticulos + 1);
        articulos[totalArticulos] = solicitarArticulo();
        totalCompra += articulos[totalArticulos].subtotal;
        totalArticulos++;

        if (totalArticulos < MAX_ARTICULOS) {
            printf("\n¿Desea agregar otro artículo? (S/N): ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);

            while (continuar != 'S' && continuar != 'N'){
                printf("Por favor, ingrese 'S' para Sí o 'N' para No: ");
                scanf("%c", &continuar);
                continuar = toupper(continuar);
            }

            while (getchar() != '\n');
            
        }

    } while (continuar == 'S' && totalArticulos < MAX_ARTICULOS);

    mostrarTicket(articulos, totalArticulos, totalCompra);
}

