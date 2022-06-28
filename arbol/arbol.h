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
void mostrarArbolPostOrden(tArbol *arbol,  void (*mostrar)(const void *info));
int ramaMax(tArbol *arbol);
tNodo *buscarNodo(tArbol *arbol, void *dato, int (*comparar)(const void *a, const void *b));
int eliminarNodo(tArbol *arbol, void *dato, int (*comparar)(const void *a, const void *b));
float promedioArbolInt(tArbol *arbol);

//TO DO SI O SI
//eliminar nodo
//contar nodos
//altura del arbol
//sumar claves del arbol
//leer archivo en arbol
//balancear
//mostrar arbol

//TO DO RECURSIVO
//INORDEN v
//PREORDEN v
//POSTORDEN v
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
//ver nodos dedd un nvel
// calcular promedio de numeros del arbol
#endif // ARBOL_H_INCLUDED
