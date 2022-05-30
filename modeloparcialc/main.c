#include "cola.h"

typedef struct {
    int dd;
    int mm;
    int aaaa;
}Fecha;

typedef struct {
    Fecha fecha;
    int codCliente;
    char codProducto[11];
    int cantPedida;
}Cliente;

typedef struct {
    char codProducto[11];
    char descripcion[26];
    float precioUnitario;
    int stock;
}Producto;

int main()
{
    char *archProd = "prodEnStock.bin";
    char *archPed = "pedidos.txt";
    FILE *product = fopen(archProd, "r+b");
    if(!product){
        puts("No se pudo leer el archivo de productos en stock");
        return -1;
    }
    FILE *pedidos = fopen(archPed, "r");
    if(!pedidos){
        puts("No se pudo leer el archivo de pedidos");
        fclose(product);
        return -2;
    }
    FILE *pendientes = fopen("pendientes.txt", "w");
    if(!pendientes){
        fclose(product);
        fclose(pedidos);
        puts("No se pudo crear el archivo de pedidos pendientes");
        return -3;
    }
    Producto pro;
    Cliente cli;
    tCola penCola;
    crearCola(&penCola);
    armarColaClientes(&penCola; )
    printf("Hello world!\n");
    return 0;
}
