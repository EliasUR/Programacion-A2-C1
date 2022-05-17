#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <string.h>
#define TAM_PILA 23

///estatica
//typedef struct{
//    char info[TAM_PILA];
//    unsigned tope;
//}tPila;

///dinamica
typedef struct Nodo{
    void *info;
    unsigned tam;
    struct Nodo *sNodo;
}tNodo;

typedef tNodo *tPila;

void crearPila(tPila *p);
int pilaLlena(const tPila *p, unsigned cantBytes);
int ponerEnPila (tPila *p, const void *d, unsigned cantBytes);
int verTope(const tPila *p, void *d, unsigned cantBytes);
int pilaVacia (const tPila *p);
void vaciarPila(tPila *p);
int sacarDePila(tPila *p, void *d, unsigned cantBytes);

void mostrarPilaInt(tPila *p);

#endif // PILA_H_INCLUDED
