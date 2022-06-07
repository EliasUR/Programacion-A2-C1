#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    unsigned tam;
    void *info;
    struct Nodo *sig;
    struct Nodo *ant;
}tNodo;

typedef tNodo *tLista;

void crearLista(tLista *lista);
int insertarEnListaOrdenada(tLista *lista, void *info, unsigned cantBytes, int (* comparar)(const void *a, const void *b));
void mostrarListaAsc(tLista *lista, void (* mostrar)(const void *info));
void mostrarListaDesc(tLista *lista, void (* mostrar)(const void *info));
void eliminarRegDeLista(tLista *lista, const void *reg, int (* comparar)(const void *a, const void *b));
#endif // LISTA_H_INCLUDED
