#ifndef BUSQUEDABINARIA_H_INCLUDED
#define BUSQUEDABINARIA_H_INCLUDED

#include "arbol.h"

typedef struct
{
    int claveProd,
        cant;
    float precio;
    char descripcion[30];
}t_dato;

typedef struct{
    int pos;
    int clave;
}Indice;

void crearLoteDatos (const char* nombArch);
void busquedaBinaria(FILE *arch, void *dato, unsigned tam);

#endif // BUSQUEDABINARIA_H_INCLUDED
