#include "funciones.h"

int factorial(int n)
{
    if(n == 0){
        return 1;
    }
    return n*factorial(n-1);
}

int exponencial(int base, unsigned exponente)
{
    int result;
    if(exponente == 0){
        return 1;
    }
    else{
        return base * exponencial(base, exponente-1);
    }
}

int cantChar(char *c){
    if(*c == '\0')
        return 0;

    return 1 + cantChar(c+1);
}
