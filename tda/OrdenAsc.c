#include "main.h"

void ordenAscendente(tPila *ordenados, const int reg, tPila *aux);
void ejAcomodarEnPilaAsc();
void mostrarArray(int *ar, int cantEl);

void ejAcomodarEnPilaAsc()
{
//    int i, ar[] = {3,1,5,2,4,8,6,7,9};
    int reg, auxInt;
    FILE *arch = fopen("numeros.bin", "rb");
    if(!arch){
        exit(-1);
    }
    tPila ordenados, aux;
//    int *p = ar;
//    mostrarArray(ar, 9);
    crearPila(&ordenados);
    crearPila(&aux);
    fread(&reg, sizeof(int), 1, arch);
//    for(i=0;i<9; i++)
    while(!feof(arch))
    {
        ordenAscendente(&ordenados, reg, &aux);
//        p++;
        fread(&reg, sizeof(int), 1, arch);
    }
    while(!pilaVacia(&aux)){
        sacarDePila(&aux, &auxInt, sizeof(int));
        ponerEnPila(&ordenados, &auxInt, sizeof(int));
    }
    fclose(arch);
//    p--;
//    for(i=0;i<9;i++){
//        sacarDePila(&ordenados, p, sizeof(int));
//        p--;
//    }
//    mostrarArray(ar, 9);
}

void ordenAscendente(tPila *ordenados, const int reg, tPila *aux)
{
    int d, auxInt;
    verTope(ordenados, &d, sizeof(int));
    verTope(aux, &auxInt, sizeof(int));
    if((!pilaVacia(ordenados)) && reg > d)
    {
        if((!pilaVacia(aux) && reg > auxInt))
        {
            do
            {
                sacarDePila(aux, &auxInt, sizeof(int));
                ponerEnPila(ordenados, &auxInt, sizeof(int));;
                verTope(aux, &auxInt, sizeof(int));
            }
            while(reg > auxInt && (!pilaVacia(aux)));
        }
    }
    else
    {
        while((!pilaVacia(ordenados)) && d > reg)
        {
            sacarDePila(ordenados, &d, sizeof(int));
            ponerEnPila(aux, &d, sizeof(int));
            verTope(ordenados, &d, sizeof(int));
        }
    }
    ponerEnPila(ordenados, &reg, sizeof(int));
}

void mostrarArray(int *ar, int cantEl)
{
    int i;
    for(i=0; i<cantEl; i++)
    {
        printf("| %d ", *ar++);
    }
    printf("|\n");
}
