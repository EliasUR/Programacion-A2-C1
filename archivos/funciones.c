#include "funciones.h"

char menu(char *mensaje, char *opciones){
    char op;
    system("cls");
    puts(mensaje);
    scanf("%c", &op);
    while(!strchr(opciones, op)){
        printf("La opcion elegida no existe\n");
        fflush(stdin);
        scanf("%c", &op);
    }
    return op;
}
