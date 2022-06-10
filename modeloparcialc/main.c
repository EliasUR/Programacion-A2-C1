#include "cola.h"
#include "lista.h"

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

int armarListaClientes(tLista *list);
void actualizarStock(tLista *pedidos, char* archProd, tCola *pendientes);

int main()
{
    char *archProd = "prodEnStock.bin";
    char *archPed = "pedidos.txt";
    FILE *pendientes = fopen("pendientes.txt", "w");
    if(!pendientes){
        fclose(product);
        fclose(pedidos);
        puts("No se pudo crear el archivo de pedidos pendientes");
        return -3;
    }
    tCola penCola;
    tLista pedLista;
    crearCola(&penCola);
    creaLista(&pedLista);
    if(!armarListaClientes(&pedLista; archPed)){
        puts("No hay pedidos");
        return 0;
    }
    if(!actualizarStock(pedLista, archPed, &penCola))

    return 0;
}

int armarListaClientes(tLista *list, char *archPed)
{
    Cliente cli;
    FILE *pedidos = fopen(archPed, "r");
    if(!pedidos){
        return 0;
    }
    fread(&cli, sizeof(Cliente), 1, pedidos);
    while(feof(pedidos))
    {
        sumarPedidoEnLista(list, cli);
        fread(&cli, sizeof(Cliente), 1, pedidos);
    }
    fclose(pedidos);
    if(!list){
        return 0;
    }
    return 1;
}

int actualizarStock(tLista *pedidos, char* archProd, tCola *pendientes)
{
    Cliente cliente;
    FILE *product = fopen(archProd, "r+b");
    if(!product){
        return 0;
    }
    tLista productos;
    creaLista(&productos);
    armarListaProductos(&productos, product);
    sacarPrimeroLista(pedidos, &cliente);
    actualizarStockProducto(&productos, cliente);

}
