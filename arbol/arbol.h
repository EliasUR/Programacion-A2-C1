#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    unsigned tam;
    void *info;
    struct Nodo *menor;
    struct Nodo *mayor;
}tNodo;

typedef tNodo *tArbol;

void crearArbol(tArbol *arbol);
int nuevaRama(tArbol *arbol, const void *info, unsigned cantBytes, int (* comparar)(const void *a, const void *b));
void mostrarArbolInOrden(tArbol *arbol,  void (*mostrar)(const void *info));
void mostrarArbolPreOrden(tArbol *arbol,  void (*mostrar)(const void *info));
//TO DO RECURSIVO
//INORDEN v
//PREORDEN
//POSTORDEN
//volver del postorden al inorden
//algun orden sin recursividad
//de un arbol incompleto inorden 10-25-50-75-100-120-130 crear un arbol completo
//contar nodos
//contar hojas
//contar ramas
//conocer altura de un arbol
//ver nodos a una altura dada
//ver nodos hasta una altura dada(incluida)
//ver nodos hasta una altura dada(excluida)
//podar hojas
//eliminar arbol
//eliminar un nodo cualquiera
//buscar clave en un nodo
//ver nodos hasta un nvel
//ver nodos desde un nvel
//ver nodos de un nvel

#endif // ARBOL_H_INCLUDED
