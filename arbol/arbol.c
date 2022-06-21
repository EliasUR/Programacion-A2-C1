#include "arbol.h"

void crearArbol(tArbol *arbol)
{
    *arbol = NULL;
}
int nuevaRama(tArbol *arbol, const void *info, unsigned cantBytes, int (* comparar)(const void *a, const void *b))
{
    while(*arbol != NULL){
        printf("%d - ", *(int *)(*arbol)->info);
        if(comparar(info, (*arbol)->info) == 0){
            return 0;
        }
        if(comparar(info, (*arbol)->info) < 0){
            arbol = &(*arbol)->menor;
        }
        else{
            arbol = &(*arbol)->mayor;
        }
    }

    *arbol = (tNodo *)malloc(sizeof(tNodo));
    if(!(*arbol)){
        return 0;
    }
    (*arbol)->info = malloc(cantBytes);
    if(!(*arbol)->info){
        free(*arbol);
        return 0;
    }
    memcpy((*arbol)->info, info, cantBytes);
    (*arbol)->tam = cantBytes;
    (*arbol)->menor = NULL;
    (*arbol)->mayor = NULL;
        printf("%d\n", *(int *)(*arbol)->info);
    return 1;
}

void mostrarArbolInOrden(tArbol *arbol, void (*mostrar)(const void *info))
{
    if(*arbol == NULL){
        return;
    }

    if((*arbol)->menor != NULL)
    {
        mostrarArbolInOrden(&(*arbol)->menor, mostrar);
    }
        mostrar((*arbol)->info);
    if((*arbol)->mayor != NULL)
    {
        mostrarArbolInOrden(&(*arbol)->mayor, mostrar);
    }
}

void mostrarArbolPreOrden(tArbol *arbol,  void (*mostrar)(const void *info))
{
    if(*arbol == NULL){
        return;
    }

    mostrar((*arbol)->info);
    if((*arbol)->menor != NULL)
    {
        mostrarArbolInOrden(&(*arbol)->menor, mostrar);
    }
    if((*arbol)->mayor != NULL)
    {
        mostrarArbolInOrden(&(*arbol)->mayor, mostrar);
    }
}
