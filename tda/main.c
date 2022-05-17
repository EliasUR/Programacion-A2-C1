#include "main.h"

void probarPrimitivasDePila();
void ordenAscendente(tPila *ordenados, const int reg, tPila *aux);
void ejAcomodarEnPilaAsc();
void mostrarArray(int *ar, int cantEl);
int main()
{
    ejAcomodarEnPilaAsc();
    return 0;
}

void probarPrimitivasDePila()
{
    char *d = "Messi",
          *d2 = "Diego",
           d3[7],
           tope[20],
           tope2[20],
           tope3[20];
    tPila pila;
    crearPila(&pila);
    if(pilaVacia(&pila))
        printf("Pila vacia!\n");
    ponerEnPila(&pila, d, sizeof(d));
    verTope(&pila, tope, 7);
    printf("Tope: %s\n", tope);

    ponerEnPila(&pila, d2, sizeof(d2));
    verTope(&pila, tope2, 7);
    printf("Tope: %s\n", tope2);

    if(pilaLlena(&pila, 1))
        printf("Pila llena!\n");

    sacarDePila(&pila, d3, sizeof(d3));
    printf("Elemento que saque: %s\n", d3);

    verTope(&pila, tope3, 7);
    printf("Tope: %s\n", tope3);

    vaciarPila(&pila);
    if(pilaVacia(&pila))
        printf("Pila vacia!\n");
}

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
