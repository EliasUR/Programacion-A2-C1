#include "main.h"

void probarPrimitivasDePila();
void probarPrimitivasDeCola();
void probarPrimitivasDeLista();

int main()
{
    probarPrimitivasDeCola();
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

void probarPrimitivasDeCola()
{
    char *d = "Messi",
          *d2 = "Diego",
           d3[20],
           tope[20],
           tope2[20],
           tope3[20];
    tCola cola;
    crearCola(&cola);
    if(colaVacia(&cola)){
        puts("COLA VACIA!!");
    }
    ponerEnCola(&cola, d, sizeof(d));
    verPrimero(&cola, tope, 20);
    printf("Tope: %s\n", tope);

    ponerEnCola(&cola, d2, sizeof(d2));
    verPrimero(&cola, tope2, 20);
    printf("Tope: %s\n", tope2);

    if(colaLlena(&cola, 1))
        printf("Cola llena!\n");

    sacarDeCola(&cola, d3, sizeof(d3));
    printf("Elemento que saque: %s\n", d3);

    verPrimero(&cola, tope3, 20);
    printf("Tope: %s\n", tope3);

    vaciarCola(&cola);
    if(colaVacia(&cola))
        printf("Cola vacia!\n");
}


void probarPrimitivasDeLista(){
    int datos[] = {1,3,2,5,5,4};
    tLista lista;
    creaLista(&lista);
    cargarListaConVector(&lista, datos, sizeof(int), 6, comparar);//pendiente comparacion
}

int cargarListaConVector(tLista *li, void *vect, unsigned tamEl, unsigned cantEl,
                         int (*insertar)(tLista *li, const void *dato, unsigned cantBytes))
{
    int i;
    for(i=0;i<cantEl;i++){
        if(!insertarAlFinalDeLista(li, vect, tamEl)){
            break;
        }
        vect = (vect + tamEl);
    }
    return i;
}
