#include "funciones.h"

int comparar(alum a, empleado e){
    int ap,n,d;
    ap = strcmp(a.apellido,e.apellido);
    if(ap != 0){
        return ap;
    }
    else{
        n = strcmp(a.nombre,e.nombre);
        if(n != 0){
            return n;
        }
        else{
            d = a.dni - e.dni;
            return d;
        }
    }
}

void actualizarSueldo(alum a, empleado e, FILE *archivo){
    if(a.prom > 7){
        fseek(archivo, -sizeof(empleado), SEEK_CUR);
        e.sueldo = e.sueldo + (e.sueldo*0.0728);
        fwrite(&e, sizeof(empleado), 1, archivo);
        fseek(archivo, 0l, SEEK_CUR);
    }
}

void probarCmp(){
    alum a = {127, "Carlos", "Apellido", 7};
    empleado e = {223, "Carlos", "Azellido", 400};
    int r = comparar(a,e);
    printf("%d\n", r);
}

int crearLoteDePrueba(){
    int resp = loteDePruebaAlum();
    resp += loteDePruebaEmp();
    return resp;
}

int loteDePruebaAlum(){
    FILE *p = fopen("estudiantes.dat", "wb");
    if(!p){
        return -1;
    }
    alum alumnosLote[] = {
        {11222333, "Juan", "Florentino", 8.5},
        {11333222, "Juan", "Hernandez", 7},
        {22333111, "Ernesto", "Perez", 8.5},
        {32111333, "Julian", "Sanabria", 5.5},
        {33222111, "Juan", "Florentino", 10}
    };

    fwrite(alumnosLote, sizeof(alumnosLote), 1, p);
    fclose(p);
    return 0;
}

int loteDePruebaEmp(){
    FILE *p = fopen("empleados.dat", "wb");
    if(!p){
        return -2;
    }
    empleado empleadosLote[] = {
        {00222333, "Juan", "Florentino", 100},
        {11333222, "Juan", "Hernandez", 100},
        {22333111, "Ernesto", "Perez", 100},
        {33111333, "Julian", "Sanabria", 100},
        {33222111, "Juan", "Florentino", 100}
    };

    fwrite(empleadosLote, sizeof(empleadosLote), 1, p);
    fclose(p);
    return 0;
}
