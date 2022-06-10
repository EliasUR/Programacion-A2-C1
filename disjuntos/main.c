#include <stdio.h>
#include <stdlib.h>

int sonDisjuntos(int *v, int *v2, int cev, int cev2);
void mostrarVector(int *v,int ce);
int main()
{
    int d, ce = 4, ce2 = 5;
    int v1[] = {1,0,3,4}, v2[] = {5,5,5,5,0}, v3[] = {1,2,3,4,3};
    d = sonDisjuntos(v1,v2, ce, ce2);
    printf("Vector 1\n");
    mostrarVector(v1, ce);
    printf(".................\n");
    printf("Vector 2\n");
    mostrarVector(v2, ce2);
    printf(".................\n");
    printf("Disjuntos: %s\n", (d?"Si":"No"));

    d = sonDisjuntos(v2,v3, ce2, ce2);
    printf("Vector 3\n");
    mostrarVector(v2, ce2);
    printf(".................\n");
    printf("Vector 2\n");
    mostrarVector(v3, ce2);
    printf(".................\n");
    printf("Disjuntos: %s\n", (d?"Si":"No"));
    return 0;
}

int sonDisjuntos(int *v, int *v2, int cev, int cev2){
    int i, j, *pv2 = v2;
    for(i=0;i<cev;i++){
        for(j=0;j<cev2;j++){
            if(*v == *v2){
                return 0;
            }
            v2++;
        }
        v2 = pv2;
        v++;
    }
    printf("aversianda\n");
    return 1;
}

void mostrarVector(int *v,int ce){
    int i;
    printf("| ");
    for(i=0;i<ce;i++){
        printf("%d | ", *(v++));
    }
    printf("\ncantidad de elementos: %d\n", ce);
}
