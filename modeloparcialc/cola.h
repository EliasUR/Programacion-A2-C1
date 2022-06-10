#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

typedef struct Nodo{
    void *info;
    unsigned tam;
    struct Nodo *sig;
}tNodo;

typedef struct {
    tNodo *pri;
    tNodo *ulti;
}tCola;

void crearCola(tCola *cola);
void vaciarCola(tCola *cola);
int colaLlena(const tCola *cola, const unsigned cantBytes);
int colaVacia(const tCola *cola);
int ponerEnCola(tCola *cola, const void *info, const unsigned cantBytes);
void sacarDeCola(tCola *cola, void *dato, const unsigned cantBytes);
int verPriCola(const tCola *cola, void *dato, const unsigned cantBytes);

#endif // COLA_H_INCLUDED
