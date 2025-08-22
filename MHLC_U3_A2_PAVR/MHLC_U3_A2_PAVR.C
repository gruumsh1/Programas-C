#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MONTO_MINIMO_DESCUENTO 500.0
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

Articulo solicitarArticulo(){
    Articulo art;
    int intentos = 0;
    const int MAX_INTENTOS = 3;

    do {
        printf("  Precio del articulo: $"):

        if (scanf("%f", &art.precio) !=1) {
            printf(" Error: Ingrese un Valor númerico válido.\n");
            while (getchar() != '\n');
            intentos++;
        } else if (art.precio <=0) {
            printf("  Error: El precio debe ser mayor a cero.\n");
            intentos++;
        } else {
            break;
        }

        if (intentos >= MAX_INTENTOS) {
            printf("  Demasiados intentos fallidos. Cancelando artículo.\n");
            art.precio = 0;
            art.cantidad = 0;
            art.subtotal = 0;
            return art;
        }
        
    } while (1);

    intentos = 0;


    do {
        printf("  Cantidad:  ");

        if(scanf("%d", &art.cantidad) !=1) {
            printf(" Error: Ingrese un número entero válido.\n");
            while (getchar() != '\n');
            intentos++;
        } else if (art.cantidad <= 0){
            printf(" Error: La cantidad debe ser mayor a cero.\n");
            intentos++;
        } else {
            break;
        }

        if (intentos >= MAX_INTENTOS) {
            printf(" Demasiados intentos fallidos. Cancelando artículo.\n");
            art.precio = 0;
            art.cantidad = 0;
            art.subtotal = 0;
            return art;
        }
    } while (1);

    art.subtotal = art.precio * art.cantidad;
    printf("   Subtotal: $%.2f\n", art.subtotal);

    return art;

}

void mostrarTicket(Articulo articulos[], int totalAticulos, float totalCompra) {
    printf("\n=============================================\n");
    printf("               TICKET DE COMPRA\n");
    printf("=============================================\n\n");


    printf("No.  Precio    Cantidad  Subtotal\n");
    printf("---------------------------------\n");

    for (int i = 0; i < totalAticulos; i++) {
        printf("%-4d $%-8.2f %-9d $%-8.2f\n"), 
                i+1,
                articulos[i].precio,
                articulos[i].cantidad,
                articulos[i].subtotal;
    }

    printf("---------------------------------\n");
    printf("SUBTOTAL: $%.2f\n", totalCompra);

    if (totalCompra> MONTO_MINIMO_DESCUENTO) {
        float descuento = totalCompra * PORCENTAJE_DESCUENTO;
        float totalConDescuento = totalCompra - descuento;

        printf("¡DESCUENTO APLICADO (%.0f%%)! - $%.2f\n",
            PORCENTAJE_DESCUENTO * 100, descuento);
        printf("TOTAL A PAGAR: $%.2f\n", totalConDescuento);

        int totalItems = 0;
        for (int i = 0; i < totalAticulos; i++) {
            totalItems += articulos[i].cantidad;
        }

        printf("Total de items: %d\n", totalItems);
        printf("Precio promedio por item: $%.2f\n", totalConDescuento / totalItems);

    } else {
        float faltaParaDescuento = MONTO_MINIMO_DESCUENTO - totalCompra;

        printf("TOTAL A PAGAR: $%.2f\n", totalCompra);
        printf("Le faltan $%.2f para el descuento del %.0f%%\n", faltaParaDescuento, PORCENTAJE_DESCUENTO * 100);

        int totalItems = 0;
        for (int i=0; i< totalAticulos; i++){
            totalItems += articulos[i].cantidad;
        }
        printf("Total de items: %d\n", totalItems);
        printf("Precio promedio por item: $%.2f\n", totalCompra / totalItems);
    }
    printf("=============================================\n\n");
}

char solocitarContinuacion(){
    char opcion;

    printf("\n¿Desea realizar otra venta? (S/N): ");
    scanf(" %c", &opcion);

    while (getchar() != '\n');

    opcion = toupper(opcion);

    while (opcion != 'S' && opcion != 'N'){
        printf("Por favor, ingrese 'S' para Sí o 'N' para No: ");
        scanf(" %c", &opcion);
        opcion = toupper(opcion);
        while (getchar() != '\n');
    }

    return opcion;
}


