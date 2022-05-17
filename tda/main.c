#include "main.h"
void probarPrimitivasDePila();

int main()
{
    ejSumarNumerosGrandes();
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

