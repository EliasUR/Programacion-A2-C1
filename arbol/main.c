#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void mostrarInt(const void *info);
int compararInt(const void *a, const void *b);
void nuevasRamas(tArbol *arbol, int *info, int max);

int main()
{
    tArbol arbol;
    int num[10] = {100,50,120,75,25,135};
    crearArbol(&arbol);
    nuevasRamas(&arbol, num, 6);
    printf("\nrecorrido inorden\n...............\n");
    mostrarArbolInOrden(&arbol, mostrarInt);
    printf("\nrecorrido preorden\n...............\n");
    mostrarArbolPreOrden(&arbol, mostrarInt);
//    printf("Hello world!\n");
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
