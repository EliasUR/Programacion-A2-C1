#include "funciones.h"

int main()
{
    FILE *p;
    char opcion;

    do
    {
        opcion = menu("Seleccione una operación\n"
                      "1. Abrir o crear archivo\n"
                      "\n"
                      "0. Cerrar programa\n","10");
        switch(opcion)
        {
        case '1':
            printf("lol?\n");
            //abrirArchivo(&p, "alumnos.bin", "w+b");
            break;
        case '2':
            break;
        }
    }
    while(opcion != '0');


    /*int *pDni, *pDia;
    t_alum al1, al2, vecal[5], *pAl;
    t_fecha f1 = {25, 8, 2002};
    t_alum al3 = {111, "Juan Perez", 8.2, {01 , 01, 2000}, {10, 2, 4}};
    al1.fNam.dd = 30;
    al2.fNam = f1;
    vecal[4].notas[1] = 5;
    pAl = &al3;
    printf("al3 nombre: %s\n", pAl->apyn);/// Para acceder a un valor de una struct desde un puntero se utiliza "->" y no "."
    pDni = &pAl->dni; /// Para acceder a la direccion de un valor dentro de una struct desde un puntero se utiliza "&p->v"
    printf("al3 dni: %d\n", *pDni);
    pDia = &pAl->fNam.dd; /// Si accedemos desde una constante podemos usar "."
    printf("al3 dia: %d\n", *pDia);
    */
    return 0;
}
