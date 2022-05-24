#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef struct Nodo{
    void *info;
    unsigned tam;
    struct Nodo *sNodo;
}tNodo;


#endif // NODO_H_INCLUDED
