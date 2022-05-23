#include "main.h"

int cargarPilaConArchivo(tPila *p, char *fileName);
char sumaConCarry(char n1, char n2, char carry, char *result);
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
    char num;
    FILE *arch = fopen(fileName, "rt");
    if(!arch){
        printf("No se pudo cargar el archivo\n");
        exit(-1);
    }

    while((num = fgetc(arch)) != EOF){
        if(num != '\0' && num != '\n'){
            num = num - '0';
            ponerEnPila(p, &num, sizeof(char));
        }
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
    do{
        sacarDePila(p, &n, sizeof(char));
        n += '0';
        fputc(n, arch);
    }
    while(!pilaVacia(p));
    fclose(arch);
    return 1;
}
void sumarPilas(tPila *pN1, tPila *pN2, tPila *pResult)
{
    char n1, n2, carry = 0, result;
    while(!pilaVacia(pN1) && !pilaVacia(pN2)){
        sacarDePila(pN1, &n1, sizeof(char));
        sacarDePila(pN2, &n2, sizeof(char));
        carry = sumaConCarry(n1, n2, carry, &result);
        ponerEnPila(pResult, &result, sizeof(char));
    }
    while(!pilaVacia(pN1)){
        sacarDePila(pN1, &n1, sizeof(char));
        carry = sumaConCarry(n1, 0, carry, &result);
        ponerEnPila(pResult, &result, sizeof(char));
    }
    while(!pilaVacia(pN2)){
        sacarDePila(pN2, &n2, sizeof(char));
        carry = sumaConCarry(n2, 0, carry, &result);
        ponerEnPila(pResult, &result, sizeof(char));
    }
    if(carry > 0){
        ponerEnPila(pResult, &carry, sizeof(char));
    }
}

char sumaConCarry(char n1, char n2, char carry, char *result){
    *result = n1 + n2 + carry;
    carry = 0;
    if(*result >= 10){
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
