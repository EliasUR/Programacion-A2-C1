#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "macros.h"

///&(*pl)->sig direccion del siguiente
typedef tNodo *tLista;

void creaLista(tLista *li);
int insertarAlFinalDeLista(tLista *li, void* dato, unsigned cantBytes);
void eliminarAlFinalDeLista(tLista *li);
void mostrarLista(const tLista *li, void (*mostrar)(const void *el));
int insertarEnOrdenEnLista(tLista *li, void* dato, unsigned cantBytes,
                           int (*comparar)(const void *a, const void*b));
//int colaLlena(const tCola *c, unsigned cantBytes);
//int ponerEnCola (tCola *c, const void *d, unsigned cantBytes);
//int verPrimero(const tCola *c, void *d, unsigned cantBytes);
//int colaVacia (const tCola *c);
//void vaciarCola(tCola *c);
//int sacarDeCola(tCola *c, void *d, unsigned cantBytes);
#endif // LISTA_H_INCLUDED
