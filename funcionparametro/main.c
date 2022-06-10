#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void ordenPorSeleccion(int *vect, int cantEl, (*comp)(int, int)){
    int i, j, *paux = vect++;
    for(i=0, i<cantEl-1,i++){
        for(j=0, j<cantEl, j++){
            if(comp(*vect, *paux) < 0){
                darVuelta(*vect, *paux);
            }
            vect++;
        }
        paux++;
        vect = paux + 1;
    }
}
