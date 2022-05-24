#include "cola.h"

void crearCola(tCola *c)
{
    c->primero = NULL;
    c->ultimo = NULL;
}
int colaVacia (const tCola *c)
{
    return c->primero == NULL;
}
int ponerEnCola (tCola *c, const void *d, unsigned cantBytes){
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
    n->tam = cantBytes;
    n->sNodo = NULL;
    if(!c->primero){
        c->primero = n;
    }
    else{
        c->ultimo->sNodo = n;
    }
    c->ultimo = n;
    return 1;
}
int sacarDeCola(tCola *c, void *d, unsigned cantBytes){
    if(c->primero == NULL)
        return 0;

    tNodo *elim = c->primero;
    unsigned minTam = cantBytes<elim->tam? cantBytes : elim->tam;
    memcpy(d, elim->info, minTam);

    c->primero = elim->sNodo;
    if(c->primero == NULL)
        c->ultimo = NULL;

    free(elim->info);
    free(elim);
    return 1;
}
int verPrimero(const tCola *c, void *d, unsigned cantBytes)
{
    if(c->primero == NULL)
        return 0;

    unsigned minTam = cantBytes < c->primero->tam ? cantBytes : c->primero->tam;
    memcpy(d, c->primero->info, minTam);

    return 1;
}
void vaciarCola(tCola *c)
{
        tNodo *elim = c->primero;
    while(c->primero != NULL)
    {
        c->primero = elim->sNodo;
        free(elim->info);
        free(elim);
        elim = c->primero;
    }
    c->ultimo = NULL;
}
int colaLlena(const tCola *c, unsigned cantBytes)
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
