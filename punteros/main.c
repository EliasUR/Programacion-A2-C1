#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int a = 10, b = 6, c = 12;
    pintarTipo(a, tipoDeNumero(a));
    printf("algo");
    pintarTipo(b, tipoDeNumero(b));
    pintarTipo(c, tipoDeNumero(c));
}
