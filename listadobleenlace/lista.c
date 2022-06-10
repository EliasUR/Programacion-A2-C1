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

void eliminarRegDeListaOrdenada(tLista *lista, const void *reg, int (* comparar)(const void *a, const void *b))
{
    tNodo *elim, *actual = *lista;
    int seguirBorrando = 1;
    while(actual->ant != NULL && comparar(reg, actual->info) < 0){//si el dato es menor a la posicion retrocede el actual hasta encontrar >=
        actual = actual->ant;
    }
    while(seguirBorrando){
        if(actual->ant != NULL && comparar(reg, elim->info) == 0){//si la pos es igual al registro borra y va al anterior
            elim = actual;
            actual = actual->ant;
            elim->ant->sig = elim->sig;
            elim->sig->ant = elim->ant;
            free(elim->info);
            free(elim);
        }else{
            if(actual->sig != NULL && comparar(reg, actual->info) > 0){//si la info es mayor al actual->info ir al siguiente
                actual = actual->sig;
            }
            else{
                seguirBorrando = 0;//salida
            }
        }
    }
}

void acumularDeLista(tLista *lista, void *reg,
                     int (* comparar)(const void *a, const void *b), void (* acumular)(void *acum, const void *b)){
    tNodo *aux = *lista;
    while(aux->ant != NULL){
        aux = aux->ant;
    }
    while(aux->sig != NULL){
        if(comparar(reg, aux->info) == 0){
            acumular(reg, aux->info);
        }
        aux = aux->sig;
    }
    if(comparar(reg, aux->info) == 0){
        acumular(reg, aux->info);
    }
}

void acumularYborrarDeListaOrdenada(tLista *lista, const void *reg, int (* comparar)(const void *a, const void *b),
                                      void (* acumular)(void *acum, const void *b))
{
    tNodo *elim, *acum = *lista;
    int seguirBorrando = 1, direc = 0;
    if(comparar(reg, acum->info) < 0){
        while(comparar(reg, acum->info) < 0){//si el dato es menor a la posicion retrocede el actual hasta encontrar >=
            acum = acum->ant;
            direc--;
        }
    }else{
        if(comparar(reg, acum->info) > 0){
            while(comparar(reg, acum->info) > 0){//si el dato es menor a la posicion retrocede el actual hasta encontrar >=
                acum = acum->sig;
                direc++;
            }
        }
    }
    if(direc>0){
        elim = acum->sig;
    }
    else{
        elim = acum->ant;
    }
    while(seguirBorrando){
        if(comparar(reg, elim->info) == 0 && elim != acum){//si la pos es igual al registro borra y va al anterior
            acumular(acum->info, elim->info);
            printf("Acum: %d, elim: %d | ", acum, elim);
            elim->ant->sig = elim->sig;
            elim->sig->ant = elim->ant;
            free(elim->info);
            free(elim);
            if(direc>0){
                if(acum->sig == NULL){
                    elim = acum;
                }
                else{
                    elim = acum->sig;
                }
            }else{

                if(acum->ant == NULL){
                    elim = acum;
                }
                else{
                    elim = acum->ant;
                }
            }
                printf("Aca(%d) - ", direc);
            printf("Acum: %d, elim: %d | ", acum, elim);
        }else{
            printf("Acum: %d, elim: %d | ", acum, elim);
            if(direc != 0){
                seguirBorrando = 0;
            }
            else{
                if(acum->sig != NULL){
                    elim = acum->sig;
                    direc++;
                }
                else{
                    seguirBorrando = 0;
                }
            }
        }
    }
}


