#include <stdlib.h>
#define TAM 5

int fnCmpSim(int mat[][TAM]);


int main()
{
    int mat[5][5]={{1,7,7,9,5},{3,1,2,4,11},{7,2,1,6,8},{9,4,6,1,2},{5,11,8,2,1}};

    printf("Comprueba si una matriz es simetrica\n");

    if(fnCmpSim(mat))
    {
        printf("La matriz es SIMETRICA\n");

    }else{

        printf("La matriz NO ES SIMETRICA\n");
    }
    return 0;
}



int fnCmpSim(int mat[][TAM])
{
    int i=0, j=1;

    while(i<TAM-2)
    {
       if(j==TAM)
       {
           i++;
           j=1;
           j+=i;
       }

       if(mat[i][j]!= mat[j][i])
       {
           return 0;
       }

       j++;

    }

    return 1;

}

/*#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int esSimetrica(int m[][TAM], int filas, int colum);
void mostrarMatriz(int m[][TAM], int filas, int colum);
void mostrarMatrizYSimetria(int matriz[][TAM], int filas, int col);

int main()
{
    int mSimetrica[TAM][TAM]=
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    },
    mAsimetrica[][TAM]=
    {
        {1,2,3,4},
        {1,2,3,4}
    },
    mAsimetrica2[TAM][TAM]=
    {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };

    mostrarMatrizYSimetria(mSimetrica, TAM, TAM);
    mostrarMatrizYSimetria(mAsimetrica, 2, TAM);
    mostrarMatrizYSimetria(mAsimetrica2, TAM, TAM);
    return 0;
}

int esSimetrica(int m[][TAM], int filas, int colum){
    int i,j, diagEl=0;
    /// Las matrices simetricas tienen la misma cantidad de filas que de columnas
    if(filas != colum){
        return 0;
    }
    for(i=0;i<filas;i++){
        for(j=colum-1;j>diagEl;j--){
            if(m[i][j] != m[j][i]){
                return 0;
            }
        }
        diagEl++;
    }
    return 1;
}

void mostrarMatriz(int m[][TAM], int filas, int colum){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("| %d ", m[i][j]);
        }
        printf("|\n");
    }
}

void mostrarMatrizYSimetria(int matriz[][TAM], int filas, int col){
    int simetria = esSimetrica(matriz, filas, col);
    printf("Matriz\n\n");
    mostrarMatriz(matriz, filas, col);
    printf("\n%s\n", simetria?"Simetrica":"Asimetrica");
    printf(".................\n");
}

*/
