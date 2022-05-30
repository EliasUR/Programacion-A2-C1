#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct{
    int dd;
    int mm;
    int aaaa;
} t_fecha;

typedef struct alum{ /// si quiero asignarle un valor de la misma struct hay que definirla con nombre
    int dni;
    char apyn[51];
    t_fecha fNam;
    int notas[3];
    //struct alum *tutor; /// para añadir un alumno dentro de otro hay que asignarlo como puntero
} t_alum;

char menu(char *mensaje, char *opciones);
int abrirArchivo(FILE **p, char *nombre, char *modo);

#endif // FUNCIONES_H_INCLUDED
