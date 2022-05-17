#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct ColaNodo{
    void *info;
    unsigned tam;
    struct ColaNodo *sNodo;
}tColaNodo;

typedef struct{
    tColaNodo *primero;
    tColaNodo *ultimo;
}tCola;

void crearCola(tCola *p);
int colaLlena(const tCola *p, unsigned cantBytes);
int ponerEnCola (tCola *p, const void *d, unsigned cantBytes);
int verPrimero(const tCola *p, void *d, unsigned cantBytes);
int colaVacia (const tCola *p);
void vaciarCola(tCola *p);
int sacarDeCola(tCola *p, void *d, unsigned cantBytes);

#endif // COLA_H_INCLUDED
