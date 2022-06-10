#include "lista.h"

void creaLista(tLista *li)
{
    *li = NULL;
}
int insertarAlFinalDeLista(tLista *li, void* dato, unsigned cantBytes)
{
    tNodo *n = (tNodo *)malloc(sizeof(tNodo));
    if(!n){
        return 0;
    }
    n->info = malloc(cantBytes);
    if(!n->info){
        free(n);
        return 0;
    }
    memcpy(n->info, dato, cantBytes);
    n->tam = cantBytes;
    n->sNodo = NULL;

    while(*li){
        li = &(*li)->sNodo;
    }
    (*li) = n;
    return 1;
}

void mostrarLista(const tLista *li, void (*mostrar)(const void *el))
{
    while(*li){
        mostrar((*li)->info);
        li = &(*li)->sNodo;
    }
}

void eliminarAlFinalDeLista(tLista *li)
{
    while((*li)->sNodo){
        li = &(*li)->sNodo;
    }
    *li = NULL;
}

int insertarEnOrdenEnLista(tLista *li, void* dato, unsigned cantBytes,
                           int (*comparar)(const void *a, const void*b))
{
    tNodo *n = (tNodo *)malloc(sizeof(tNodo));
    if(!n){
        return 0;
    }
    n->info = malloc(cantBytes);
    if(!n->info){
        free(n);
        return 0;
    }
    memcpy(n->info, dato, cantBytes);
    n->tam = cantBytes;

    while(*li){
        if(comparar(n->info, (*li)->sNodo->info) >= 0){
            li = &(*li)->sNodo;
        }
        else{
            break;
        }
    }
    if(*li != NULL){
        n->sNodo = (*li)->sNodo;
        (*li)->sNodo = n;
    }
    else{
        *li = n;
    }
    return 1;
}
//int cargarListaConVector(tLista *li, void *vect, unsigned tamEl, unsigned cantEl)
//{
//    int i;
//    tNodo *n;
//    while(*li){
//        li = &(*li)->sNodo;
//    }
//    for(i=0;i<cantEl;i++){
//        n = (tNodo *)malloc(sizeof(tNodo));
//        if(!n){
//            return i;
//        }
//        n->info = malloc(tamEl);
//        if(!n->info){
//            free(n);
//            return i;
//        }
//        memcpy(n->info, vect, tamEl);
//        n->tam = tamEl;
//        n->sNodo = NULL;
//        (*li) = n;
//        li = &(*li)->sNodo;
//        vect = (vect + tamEl);
//    }
//    return cantEl;
//}

