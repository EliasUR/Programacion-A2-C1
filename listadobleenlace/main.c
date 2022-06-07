#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrarInt(const void *n);
int compararInt(const void *a, const void*b);
void loteDePrueba(tLista *lista);
int main()
{
    int elim = 2;
    tLista lista;
    crearLista(&lista);
    loteDePrueba(&lista);
    mostrarListaAsc(&lista, mostrarInt);
    printf("\n");
    eliminarRegDeLista(&lista, &elim, compararInt);
    mostrarListaDesc(&lista, mostrarInt);
    printf("\n");

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
