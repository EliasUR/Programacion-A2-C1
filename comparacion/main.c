#include "funciones.h"

int main()
{
    int lp = crearLoteDePrueba();
    switch(lp){
    case 0:
        printf("Lote de prueba creado\n");
        break;
    case -1:
        printf("No se pudo crear el lote de prueba de estudiantes\n");
        return -1;
    case -2:
        printf("No se pudo crear el lote de prueba de empleados\n");
        return -2;
    case -3:
        printf("No se pudo crear ningun lote de prueba\n");
        return -3;
    }

    FILE *pest, *pemp;
    alum a;
    empleado e;
    int comp;
    pest = fopen("estudiantes.dat", "r+b");
    if(!pest)
    {
        return -1;
    }
    pemp = fopen("empleados.dat", "r+b");
    if(!pemp)
    {
        fclose(pest);
        return -2;
    }
    fread(&a, sizeof(alum), 1, pest);
    fread(&e, sizeof(empleado), 1, pemp);
    while(!feof(pest) && !feof(pemp))
    {
        comp = comparar(a, e);
        printf("%d: %s, %s prom: %.2f\n", a.dni, a.apellido, a.nombre, a.prom);
        printf("%d: %s, %s $%.2lf\n", e.dni, e.apellido, e.nombre, e.sueldo);
        printf("%d\n", comp);
        printf("......................\n");
        if(comp > 0)
        {
            fread(&e, sizeof(empleado), 1, pemp);
        }
        else
        {
            if(comp < 0)
            {
                fread(&a, sizeof(alum), 1, pest);
            }
            else
            {
                actualizarSueldo(a, e, pemp);
                fread(&e, sizeof(empleado), 1, pemp);
                fread(&a, sizeof(alum), 1, pest);
            }
        }
    }
    fseek(pemp,0l,SEEK_SET);
    printf("\n.......Resultados.....\n");
    fread(&e, sizeof(e),1,pemp);
    while(!feof(pemp))
    {
        printf("%d: %s, %s $%.2lf\n", e.dni, e.apellido, e.nombre, e.sueldo);
        printf("......................\n");
        fread(&e, sizeof(e),1,pemp);
    }
    fclose(pemp);
    fclose(pest);
    return 0;
}

