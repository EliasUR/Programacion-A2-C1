#include "funciones.h"

void mostrarVect(int *v, int ce){
    int i;
    printf("::::::::::\n");
    for(i=0;i<ce;i++){
        printf("Elemento posicion %d: %d\n", i, *v);
        v++;
    }
    printf("\nCE:%d\n", ce);
}

int cargarPorPos(int *v, int el, int pos, int ce, int tam){
    int i, aux;
    if(pos > ce){
        if(ce < tam)
            *(v+ce) = el;
    }
    else{
        for(i = (pos - 1);i<ce;i++){
            if(i < pos){
                v+=i;
            }
            aux = el;
            el = *v;
            *v = aux;
            v++;
        }
        if(ce < tam){
            *v = el;
            ce++;
        }
    }
    return ce;
}
