#include "cola.h"

void crearCola(tCola *cola)
{
    cola->pri = NULL;
    cola->ulti = NULL;
}

void vaciarCola(tCola *cola)
{
    tNodo *elim;
    while(cola->pri != NULL){
        elim = cola->pri;
        free(elim->info);
        cola->pri = elim->sig;
        free(elim);
    }
}

int colaLlena(const tCola *cola, const unsigned cantBytes)
{
    tNodo *n = (tNodo *)malloc(sizeof(tNodo));
    if(!n){
        return 1;
    }
    n->info = malloc(cantBytes);
    if(!n->info){
        free(n);
        return 1;
    }
    free(n->info);
    free(n);
    return 0;
}

int colaVacia(const tCola *cola){
    return cola->pri == NULL;
}

int ponerEnCola(tCola *cola, const void *info, const unsigned cantBytes)
{
    tNodo *n = (tNodo *)malloc(sizeof(tNodo));
    if(!n){
        return 0;
    }
    n->info = malloc(cantBytes);
    if(!n->info){
        free(n);
        return 0;
    }
    n->tam = cantBytes;
    memcpy(n->info, info, cantBytes);
    if(cola->pri == NULL){
        cola->pri = n;
        cola->ulti = cola->pri;
    }
    else{
        n->sig = NULL;
        cola->ulti->sig = n;
    }
    return 1;
}

void sacarDeCola(tCola *cola, void *dato, const unsigned cantBytes)
{
    tNodo *elim = cola->pri;
    free(elim->info);
    cola->pri = elim->sig;
    free(elim);
}

int verPriCola(const tCola *cola, void *dato, const unsigned cantBytes)
{
    if(!cola->pri){
        return 0;
    }
    unsigned min = MIN(cantBytes, cola->pri->tam);
    memcpy(dato, cola->pri->info, min);
    return 1;
}
