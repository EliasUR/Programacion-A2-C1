#include "main.h"

int cargarPilaConArchivo(tPila *p, char *fileName);
int sumaConCarry(int n1, int n2, int carry, int *result);
void sumarPilas(tPila *pN1, tPila *pN2, tPila *pResult);
int cagarArchivoConPila(tPila *p, char *fileName);

void ejSumarNumerosGrandes()
{
    tPila pN1, pN2, pResult;
    crearPila(&pN1);
    crearPila(&pN2);
    crearPila(&pResult);
    cargarPilaConArchivo(&pN1, "numero1.txt");
    cargarPilaConArchivo(&pN2, "numero2.txt");
//    int n1[16] = {1,2,3,0,0,0,2,0,9,5,4,5,1,3,5,3},
//        n2[8] = {9,5,4,5,1,3,5,3};
//    int *p1 = n1, *p2 = n2;
//    int i;
//    for(i=0;i<16;i++){
//        ponerEnPila(&pN1, p1, sizeof(int));
//        if(i%2 == 0){
//            ponerEnPila(&pN2, p2, sizeof(int));
//            p2++;
//        }
//        p1++;
//    }
    sumarPilas(&pN1, &pN2, &pResult);
    cagarArchivoConPila(&pResult, "resultado.txt");
//    mostrarPilaInt(&pResult);
}
int cargarPilaConArchivo(tPila *p, char *fileName){
    int num;
    FILE *arch = fopen(fileName, "rt");
    if(!arch){
        printf("No se pudo cargar el archivo\n");
        exit(-1);
    }
    num = fgetc(arch) - '0';
    while(!feof(arch)){
        ponerEnPila(p, &num, sizeof(int));
        num = fgetc(arch) - '0';
    }
    fclose(arch);
    return 1;
}

int cagarArchivoConPila(tPila *p, char *fileName)
{
    FILE *arch = fopen(fileName, "wt");
    if(!arch){
        return 0;
    }
    char n;
    sacarDePila(p, &n, sizeof(int));
    n += '0';
    while(!pilaVacia(p)){
        fputc(n, arch);
        sacarDePila(p, &n, sizeof(int));
        n += '0';
    }
    fclose(arch);
    return 1;
}
void sumarPilas(tPila *pN1, tPila *pN2, tPila *pResult)
{
    int n1, n2, carry = 0, result;
    while(!pilaVacia(pN1) && !pilaVacia(pN2)){
        sacarDePila(pN1, &n1, sizeof(int));
        sacarDePila(pN2, &n2, sizeof(int));
        carry = sumaConCarry(n1, n2, carry, &result);
        ponerEnPila(pResult, &result, sizeof(int));
    }
    while(!pilaVacia(pN1)){
        sacarDePila(pN1, &n1, sizeof(int));
        carry = sumaConCarry(n1, 0, carry, &result);
        ponerEnPila(pResult, &result, sizeof(int));
    }
    while(!pilaVacia(pN2)){
        sacarDePila(pN2, &n2, sizeof(int));
        carry = sumaConCarry(n2, 0, carry, &result);
        ponerEnPila(pResult, &result, sizeof(int));
    }
    if(carry > 0){
        ponerEnPila(pResult, &carry, sizeof(int));
    }
}

int sumaConCarry(int n1, int n2, int carry, int *result){
    *result = n1 + n2 + carry;
    carry = 0;
    while(*result >= 10){
        *result -= 10;
        carry++;
    }
    return carry;
}

void mostrarPilaInt(tPila *p){
    int aux;
    printf("\n");
    while(!pilaVacia(p)){
        sacarDePila(p, &aux, sizeof(int));
        printf("%d", aux);
    }
    printf("\n");
}
