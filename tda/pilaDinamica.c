#include "pila.h"
#include <stdlib.h>

void crearPila(tPila *p)
{
    *p = NULL;
}
int pilaLlena(const tPila *p, unsigned cantBytes)
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
int ponerEnPila (tPila *p, const void *d, unsigned cantBytes)
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
    memcpy(n->info, d, cantBytes);
    n->sNodo = *p;
    *p = n;
    return 1;
}
int verTope(const tPila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL){
        return 0;
    }
    unsigned tam = (*p)->tam < cantBytes? (*p)->tam: cantBytes;
    memcpy(d, (*p)->info, tam);
    return 1;
}
int pilaVacia (const tPila *p)
{
    return *p == NULL;
}
void vaciarPila(tPila *p)
{
    tNodo *elim;
    while(*p != NULL){
        elim = *p;
        *p = (*p)->sNodo;
        free(elim->info);
        free(elim);
    }
}
int sacarDePila(tPila *p, void *d, unsigned cantBytes){
    if(*p == NULL){
        return 0;
    }
    tNodo *elim = *p;
    unsigned tam = (*p)->tam < cantBytes? (*p)->tam: cantBytes;
    memcpy(d, (*p)->info, tam);
    *p = (*p)->sNodo;
    free(elim->info);
    free(elim);
    return 1;
}
