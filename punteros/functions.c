#include "functions.h"

int tipoDeNumero(int n){
    int i, suma_divisores = 0, resultado;
    for(i = 0; i < n; i++){
        if(!(n%i)){
            suma_divisores += i;
        }
    }
    if(suma_divisores > n)
        resultado = 1;
    else if(suma_divisores < n)
        resultado = -1;
    else
        resultado = 0;

    return resultado;
}

void pintarTipo(int numero, int tipo){
    printf("\n...........\n");
    printf("\nEl numero %d es:", numero);
    if(!tipo){
        printf("Perfecto");
    }
    else{
        printf("%s", (tipo > 0? "Abundante" : "Deficiente"));
    }
    printf("\n...........\n");
}
