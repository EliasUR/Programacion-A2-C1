#include "cola.h"

void crearCola(tCola *c)
{
    c->primero = 0;
    c->ultimo = 0;
    c->tamDisponible = TAM_COLA;
}
int colaLlena(const tCola *c, unsigned cantBytes)
{
    return c->tamDisponible < (cantBytes + sizeof(unsigned));
}
int colaVacia (const tCola *c)
{
    return c->tamDisponible == TAM_COLA;
}
void vaciarCola(tCola *c)
{
    c->tamDisponible = TAM_COLA;
}
int ponerEnCola (tCola *c, const void *d, unsigned cantBytes)
{
    unsigned ini, fin;
    if(c->tamDisponible < (cantBytes + sizeof(unsigned)))
        return 0;

    c->tamDisponible -= (cantBytes + sizeof(unsigned));
    ///GUARDAR TAM
    ini = MIN((TAM_COLA - c->ultimo), sizeof(unsigned));
    if(ini != 0)
        memcpy(c->info+c->ultimo, &cantBytes, ini);
    fin = sizeof(unsigned) - ini;
    if(fin != 0)
        memcpy(c->info, ((char*)&cantBytes) + ini, fin);

    c->ultimo = fin != 0? fin : c->ultimo + ini;

    ///GUARDAR INFO
    ini = MIN((TAM_COLA - c->ultimo), cantBytes);
    if(ini != 0)
        memcpy(c->info+c->ultimo, d, ini);
    fin = cantBytes - ini;
    if(fin != 0)
        memcpy(c->info, (char *)d + ini, fin);

    c->ultimo = fin != 0? fin : c->ultimo + ini;
    return 1;
}
int sacarDeCola(tCola *c, void *d, unsigned cantBytes)
{
    unsigned ini, fin, tamInfo;
    if(c->tamDisponible == TAM_COLA)
        return 0;
    ini = MIN(TAM_COLA - c->primero, sizeof(unsigned));
    if(ini)
        memcpy(&tamInfo, c->info + c->primero, ini);
    fin = sizeof(unsigned) - ini;
    if(fin)
        memcpy(((char*)&tamInfo)+ini, c->info, fin);
    c->primero = fin? fin : c->primero + ini;
    c->tamDisponible += (sizeof(unsigned) + cantBytes);

    ini = MIN(TAM_COLA - c->primero, MIN(cantBytes, tamInfo));
    if(ini)
        memcpy(d, c->info+c->primero,ini);
    fin = MIN(cantBytes, tamInfo) - ini;
    if(fin)
        memcpy((char *)d + ini, c->info, fin);

    c->primero = (c->primero + tamInfo) % TAM_COLA;
    return 1;
}
int verPrimero(const tCola *c, void *d, unsigned cantBytes)
{
    unsigned ini, fin, tamInfo, primero = c->primero;
    if(c->tamDisponible == TAM_COLA)
        return 0;
    ini = MIN(TAM_COLA - primero, sizeof(unsigned));
    if(ini)
        memcpy(&tamInfo, c->info + primero, ini);
    fin = sizeof(unsigned) - ini;
    if(fin)
        memcpy(((char*)&tamInfo)+ini, c->info, fin);
    primero = fin? fin : primero + ini;

    ini = MIN(TAM_COLA - primero, MIN(cantBytes, tamInfo));
    if(ini)
        memcpy(d, c->info+primero,ini);
    fin = MIN(cantBytes, tamInfo) - ini;
    if(fin)
        memcpy((char *)d + ini, c->info, fin);

    return 1;
}
