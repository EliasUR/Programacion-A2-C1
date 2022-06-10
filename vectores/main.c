#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 5

int main()
{
    int vec[TAM] = {1,2,3,4};
    int ce = 4;
    mostrarVect(vec, ce);
    ce = cargarPorPos(vec, 2, 3, 4, TAM);
    mostrarVect(vec, ce);
}
