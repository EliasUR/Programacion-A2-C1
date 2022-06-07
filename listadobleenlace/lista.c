#include "lista.h"

void crearLista(tLista *lista){
    *lista = NULL;
}
int insertarEnListaOrdenada(tLista *lista, void *info, unsigned cantBytes, int (* comparar)(const void *a, const void *b)){
    tNodo *nue, *auxant, *auxsig, *actual = *lista;
    if(*lista){
        while(actual->sig != NULL && comparar(info, actual->info) > 0){
            actual = actual->sig;
        }
        while(actual->ant != NULL && comparar(info, actual->info) < 0){
            actual = actual->ant;
        }
        if(comparar(info, actual->info) > 0){
            auxsig = actual->sig;
            auxant = actual;
        }
        else{
            auxsig = actual;
            auxant = actual->ant;
        }
    }
    else{
        auxant = NULL;
        auxsig = NULL;
    }

    nue = (tNodo *)malloc(sizeof(tNodo));
    if(!nue){
        return 0;
    }
    nue->info = malloc(cantBytes);
    if(!nue->info){
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, cantBytes);
    nue->tam = cantBytes;
    nue->sig = auxsig;
    nue->ant = auxant;
    *lista = nue;
    if(auxant){
        auxant->sig = nue;
    }
    if(auxsig){
        auxsig->ant = nue;
    }
    return 1;
}

void mostrarListaAsc(tLista *lista, void (* mostrar)(const void *info)){
    while((*lista)->ant != NULL){
        *lista = (*lista)->ant;
    }
    while((*lista)->sig != NULL){
        mostrar((*lista)->info);
        *lista = (*lista)->sig;
    }
    mostrar((*lista)->info);
}

void mostrarListaDesc(tLista *lista, void (* mostrar)(const void *info)){
    while((*lista)->sig != NULL){
        *lista = (*lista)->sig;
    }
    while((*lista)->ant != NULL){
        mostrar((*lista)->info);
        *lista = (*lista)->ant;
    }
    mostrar((*lista)->info);
}

void eliminarRegDeLista(tLista *lista, const void *reg, int (* comparar)(const void *a, const void *b)){
    tNodo *elim = *lista;
    int seguirBorrando = 1;
    while(seguirBorrando){
        while(elim->ant != NULL && comparar(reg, elim->info) != 0){
            elim = elim->ant;
        }
        while(elim->sig != NULL && comparar(reg, elim->info) != 0){
            elim = elim->sig;
        }
        if(comparar(reg, elim->info) == 0){
            elim->ant->sig = elim->sig;
            elim->sig->ant = elim->ant;
            free(elim->info);
            free(elim);
        }
        else{
            seguirBorrando = 0;
        }
    }
}

void acumularDeLista(tLista *lista, void *dato, int (* comparar)(const void *a, const void *b), void (* acumular)(void *acum, const void *b)){
}
