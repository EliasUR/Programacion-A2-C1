#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct {
    int dni;
    char *nombre;
    char *apellido;
    float prom;
} alum;

typedef struct {
    int dni;
    char *nombre;
    char *apellido;
    double sueldo;

} empleado;

int comparar(alum a, empleado e);
void actualizarSueldo(alum a, empleado e, FILE *archivo);
void probarCmp();
int loteDePruebaAlum();
int loteDePruebaEmp();
int crearLoteDePrueba();

#endif // FUNCIONES_H_INCLUDED
