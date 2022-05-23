#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

typedef struct{
    int hh;
    int mm;
    int ss;
} Hora;

typedef struct{
    int dd;
    int mm;
    int aaaa;
    Hora hh;
} Fecha;

typedef struct{
    int cliente;
    char sucursal[4];
    double monto;
    char mov;
    Fecha fecha;
} Movimiento;

typedef struct{
    int numCliente;
    double monto;
} Cliente;

int trozado(FILE *p, Movimiento *m);

#endif // MAIN_H_INCLUDED
