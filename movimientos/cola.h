#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "macros.h"

#define TAM_COLA 25

///DINAMICA
typedef struct ColaNodo{
    void *info;
    unsigned tam;
    struct ColaNodo *sNodo;
}tColaNodo;

typedef struct{
    tColaNodo *primero;
    tColaNodo *ultimo;
}tCola;

///ESTATICA
//typedef struct{
//    unsigned primero;
//    unsigned ultimo;
//    int tamDisponible;
//    char info[TAM_COLA];
//}tCola;

void crearCola(tCola *c);
int colaLlena(const tCola *c, unsigned cantBytes);
int ponerEnCola (tCola *c, const void *d, unsigned cantBytes);
int verPrimero(const tCola *c, void *d, unsigned cantBytes);
int colaVacia (const tCola *c);
void vaciarCola(tCola *c);
int sacarDeCola(tCola *c, void *d, unsigned cantBytes);

#endif // COLA_H_INCLUDED
