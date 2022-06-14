#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char *frase = "aRriba la Birra";
//    printf("%d\n", exponencial(2, 4));
//    printf("%d\n", cantChar(frase));
    printf("%s -> %s", frase, ejercicio13(frase, 1)?"ES PALINDROMO":"NO ES PALINDROMO");
    return 0;
}
