#include "pila.h"

void crearPila(tPila *p)
{
    p->tope = TAM_PILA;
}
int pilaVacia (const tPila *p)
{
    return p->tope == TAM_PILA;
}
int pilaLlena(const tPila *p, unsigned cantBytes)
{
    return (cantBytes + sizeof(unsigned)) > p->tope;
}
int ponerEnPila (tPila *p, const void *d, unsigned cantBytes){
//    printf("%d-%d\n", (cantBytes + sizeof(unsigned)), p->tope);
    if((cantBytes + sizeof(unsigned)) > p->tope){
        return 0;
    }
    p->tope -= cantBytes;
    memcpy(p->info+p->tope, d, cantBytes );
    p->tope -= sizeof(unsigned);
    memcpy(p->info+p->tope, &cantBytes, sizeof(unsigned));
    return 1;
}
int sacarDePila(tPila *p, void *d, unsigned cantBytes)
{
    int bytes, min;
    if(p->tope == TAM_PILA){
        return 0;
    }
    memcpy(&bytes, p->info + p->tope, sizeof(unsigned));
    p->tope+=sizeof(unsigned);
    min = cantBytes<bytes? cantBytes : bytes;
    memcpy(d, p->info + p->tope, min);
    p->tope+=bytes;
    return 1;
}
int verTope(const tPila *p, void *d, unsigned cantBytes){
    int bytes, min;
    if(p->tope == TAM_PILA){
        return 0;
    }
    memcpy(&bytes, p->info + p->tope, sizeof(unsigned));
    min = cantBytes<bytes? cantBytes : bytes;
    memcpy(d, p->info + p->tope + sizeof(unsigned), min);
    return 1;
}
void vaciarPila(tPila *p)
{
    p->tope = TAM_PILA;
}
