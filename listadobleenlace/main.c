#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct{
    int cod;
    int stock;
} Producto;

void mostrarInt(const void *n);
int compararInt(const void *a, const void*b);
void loteDePrueba(tLista *lista);
void mostrarProducto(const void *producto);
int compararProductos(const void *a, const void *b);
void acumularStock(void *acum, const void *otroProd);
void loteDePruebaProductos(tLista *lista);

int main()
{
//    int elim = 2;
    Producto acum = {1234, 0};
    tLista lista;
    crearLista(&lista);
    loteDePruebaProductos(&lista);
    mostrarListaAsc(&lista, mostrarProducto);
    printf("\n");
//    eliminarRegDeLista(&lista, &elim, compararInt);
    acumularYborrarDeListaOrdenada(&lista, &acum, compararProductos, acumularStock);
    mostrarListaDesc(&lista, mostrarProducto);
    printf("\n");
//    printf("Stock total: %d\n", acum.stock);

    return 0;
}

void mostrarInt(const void *n)
{
    printf("|%d|", *(int *)n);
}

int compararInt(const void *a, const void*b){
    return *(int *)a - *(int *)b;
}

void loteDePrueba(tLista *lista){
    int i, lote[10] = {1,2,5,4,2,3,1,7,8,5};
    for(i=0;i<10;i++){
        insertarEnListaOrdenada(lista, (lote+i), sizeof(int), compararInt);
    }
}

void acumularStock(void *acum, const void *otroProd){
    Producto *acumulador = (Producto *)acum,
             *otro = (Producto *)otroProd;
    acumulador->stock += otro->stock;
}

int compararProductos(const void *a, const void *b){
    Producto *pri= (Producto *)a,
             *segu = (Producto *)b;
    return pri->cod - segu->cod;
}

void mostrarProducto(const void *producto){
    Producto *p = (Producto *)producto;
    printf("Prod: %d, Stock: %d | ", p->cod, p->stock);
}

void loteDePruebaProductos(tLista *lista){
    int i;
    Producto lote[5] = {
        {1234, 12},
        {1244, 12},
        {1344, 12},
        {1234, 3},
        {1234, 5}
    };
    for(i=0;i<5;i++){
        insertarEnListaOrdenada(lista, (lote+i), sizeof(Producto), compararProductos);
    }
}

