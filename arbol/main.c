#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void mostrarInt(const void *info);
int compararInt(const void *a, const void *b);
void nuevasRamas(tArbol *arbol, int *info, int max);

int main()
{
    tArbol arbol;
    int buscar = 12, num[] = {100,50,150,75,25,125,175,10,30,60,55,70,110,130,160,200};
    crearArbol(&arbol);
    nuevasRamas(&arbol, num, 16);
    printf("\nrecorrido inorden\n...............\n");
    mostrarArbolInOrden(&arbol, mostrarInt);
    printf("\nrecorrido preorden\n...............\n");
    mostrarArbolPreOrden(&arbol, mostrarInt);
    printf("\nrecorrido postorden\n...............\n");
    mostrarArbolPostOrden(&arbol, mostrarInt);
    printf("\neliminar\n...............\n");
    eliminarNodo(&arbol, &buscar, compararInt);
    return 0;
}

void nuevasRamas(tArbol *arbol, int *info, int max){
    int i;
    for(i=0;i<max;i++){
        printf("%d\n", nuevaRama(arbol, info++, sizeof(int), compararInt));
    }
}

int compararInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void mostrarInt(const void *info){
    printf("|%d|", *(int *)info);
}
