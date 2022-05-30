#include <stdio.h>
#include <stdlib.h>
/**<  #define TAM 10
int borrarTodasLasOcurrencias(int *v, int el, int ce);
void mostrarVector(int *v, int ce);

int main()
{
    int vect[TAM] = {1,2,1,1,3,1,4};
    int ce = 7;
    mostrarVector(vect, ce);
    printf(".................\n");
    ce = borrarTodasLasOcurrencias(vect, 1, ce);
    mostrarVector(vect, ce);
    printf(".................\n");
    return 0;
}

int borrarTodasLasOcurrencias(int *v, int el, int ce){
    int i, *pav = v, borrados = 0;
    for(i=0;i<ce;i++){
        if(*v == el){
            v++;
            while(*v != el && i < ce){
                *pav = *v;
                pav++;
                v++;
                i++;
            }
            borrados++;
        }
        else{
            v++;
            pav++;
        }
    }
    ce -= borrados;
    return ce;
}

void mostrarVector(int *v,int ce){
    int i;
    for(i=0;i<ce;i++){
        printf("pos: %d, el: %d\n", (i+1), *(v++));
    }
    printf("cantidad de elementos: %d\n", ce);
}

*/
int eliminarTodas(int *v, int TAM, int ce, int val){
    int *vecEsc = v,i;
    for(i=0; i< ce; i++){
    if(*v == val){
        v++;
        ce--;
    } else {
        *vecEsc = *v;
        vecEsc++;
        v++;

    }
    }
    return ce;
}

int main()
{
    int vec[] = {1,2,4,3,4,5,3,4};
    int ce = 8;
    int i;
    int *point = vec;
    for(i = 0; i < ce; i++){
        printf("%d", *point);
        point++;
    }
    printf("\n");
    point = vec;
    ce = eliminarTodas(vec,8,ce,4);
    for(i = 0; i < ce; i++){
        printf("%d", *point);
        point++;
    }

    return 0;
}
