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
                printf("\nSaliendo del sistema...\n")
                
        }
    }
}