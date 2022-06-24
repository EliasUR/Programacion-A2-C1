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

    mostrarArbolInOrden(&(*arbol)->menor, mostrar);
    mostrar((*arbol)->info);
    mostrarArbolInOrden(&(*arbol)->mayor, mostrar);
}

void mostrarArbolPreOrden(tArbol *arbol,  void (*mostrar)(const void *info))
{
    if(*arbol == NULL){
        return;
    }

    mostrar((*arbol)->info);
    mostrarArbolPreOrden(&(*arbol)->menor, mostrar);
    mostrarArbolPreOrden(&(*arbol)->mayor, mostrar);
}
void mostrarArbolPostOrden(tArbol *arbol,  void (*mostrar)(const void *info))
{
    if(*arbol == NULL){
        return;
    }

    mostrarArbolPostOrden(&(*arbol)->menor, mostrar);
    mostrarArbolPostOrden(&(*arbol)->mayor, mostrar);
    mostrar((*arbol)->info);
}

int eliminarNodo(tArbol *arbol, void *dato, int (*comparar)(const void *a, const void *b))
{
    tNodo *elim = buscarNodo(arbol, dato, comparar);

    if(elim == NULL)
        return 0;

    printf("\nmax: %d", ramaMax(&elim));

    return 1;
}

tNodo *buscarNodo(tArbol *arbol, void *dato, int (*comparar)(const void *a, const void *b))
{
    if(comparar(dato, (*arbol)->info) == 0)
        return *arbol;

    if((*arbol)->menor != NULL && comparar(dato, (*arbol)->info) < 0)
        return buscarNodo(&(*arbol)->menor, dato, comparar);


    if((*arbol)->mayor != NULL && comparar(dato, (*arbol)->info) > 0)
        return buscarNodo(&(*arbol)->mayor, dato, comparar);

    if((*arbol)->mayor == NULL && (*arbol)->menor == NULL)
        return NULL;
}

int ramaMax(tArbol *arbol)
{
    int nivelIzquierda = 0, nivelDerecha = 0;
    if((*arbol)->menor != NULL){
        nivelIzquierda = ramaMax(&(*arbol)->menor);
        nivelIzquierda--;
    }

    if((*arbol)->mayor != NULL){
        nivelDerecha = ramaMax(&(*arbol)->mayor);
        nivelDerecha++;
    }

    return nivelDerecha + nivelIzquierda;

}
