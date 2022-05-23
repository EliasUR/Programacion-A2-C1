#include "main.h"

int main()
{
    tCola sucursales, clientes;
    Movimiento mov, clisuc;
    Cliente cliente;
    FILE *arch, *ma10, *me10;
    if(!(arch = fopen("movimientos.txt", "r")))
        return -1;
    if(!(ma10 = fopen("movmayoradiezm.bin", "wb"))){
        fclose(arch);
        return -2;
    }
    if(!(me10 = fopen("movmenoradiezm.bin", "wb"))){
        fclose(arch);
        fclose(ma10);
        return -3;
    }
    crearCola(&sucursales);
    crearCola(&clientes);
    trozado(arch, &clisuc);
    cliente.numCliente = clisuc.cliente;
    cliente.monto = clisuc.monto;
    while(trozado(arch, &mov)){
        if(cliente.numCliente == mov.cliente){
            cliente.monto += mov.monto;
        }
        else{
            ponerEnCola(&clientes, &cliente, sizeof(cliente));
            cliente.numCliente = mov.cliente;
            cliente.monto = mov.monto;
        }
        if(clisuc.cliente == mov.cliente && strcmp(clisuc.sucursal, mov.sucursal) == 0){
            clisuc.monto += mov.monto;
            memcpy(&clisuc.fecha, &mov.fecha, sizeof(Fecha));
            clisuc.mov = mov.mov;
        }
        else{
            ponerEnCola(&sucursales, &clisuc, sizeof(clisuc));
            memcpy(&clisuc, &mov, sizeof(Movimiento));
        }
    }
    ponerEnCola(&sucursales, &clisuc, sizeof(clisuc));
    ponerEnCola(&clientes, &cliente, sizeof(cliente));

    puts("RESULTADO");

    sacarDeCola(&clientes, &cliente, sizeof(cliente));
    sacarDeCola(&sucursales, &clisuc, sizeof(clisuc));
    while(!colaVacia(&sucursales)){
        if(cliente.numCliente == clisuc.cliente){
            if(cliente.monto < 10000000){
                printf("Menor a 10M - ");
                fwrite(&clisuc, sizeof(clisuc), 1, me10);
            }
            else{
                printf("Mayor a 10M - ");
                fwrite(&clisuc, sizeof(clisuc), 1, ma10);
            }
            printf("%d/%s %d/%d/%d %d:%d:%d (%c) %.2lf\n",  clisuc.cliente, clisuc.sucursal,
                clisuc.fecha.aaaa, clisuc.fecha.mm, clisuc.fecha.dd,
               clisuc.fecha.hh.hh, clisuc.fecha.hh.mm, clisuc.fecha.hh.ss,
               clisuc.mov, clisuc.monto);
            sacarDeCola(&sucursales, &clisuc, sizeof(clisuc));
        }
        else{
            sacarDeCola(&clientes, &cliente, sizeof(cliente));
        }
    }
    if(cliente.monto < 10000000){
        printf("Menor a 10M - ");
        fwrite(&clisuc, sizeof(clisuc), 1, me10);
    }
    else{
        printf("Mayor a 10M - ");
        fwrite(&clisuc, sizeof(clisuc), 1, ma10);
    }
    printf("%d/%s %d/%d/%d %d:%d:%d (%c) %.2lf\n",  clisuc.cliente, clisuc.sucursal,
        clisuc.fecha.aaaa, clisuc.fecha.mm, clisuc.fecha.dd,
       clisuc.fecha.hh.hh, clisuc.fecha.hh.mm, clisuc.fecha.hh.ss,
       clisuc.mov, clisuc.monto);

    fclose(arch);
    fclose(ma10);
    fclose(me10);
    return 0;
}

int trozado(FILE *p, Movimiento *m){
    char mov[50], *aux;
    fgets(mov, 50, p);
    if(feof(p)){
        return 0;
    }
    aux = strchr(mov, '\n');
    *aux = '\0';
    aux = strchr(mov, ' ');    sscanf(aux+1, "%d/%d/%d %d:%d:%d (%c) %lf",
           &m->fecha.aaaa, &m->fecha.mm, &m->fecha.dd,
           &m->fecha.hh.hh, &m->fecha.hh.mm, &m->fecha.hh.ss,
           &m->mov, &m->monto);
    *aux = '\0';    sscanf(mov, "%d/%s", &m->cliente, m->sucursal);    printf("%d/%s %d/%d/%d %d:%d:%d (%c) %.2lf\n",  m->cliente, m->sucursal,
            m->fecha.aaaa, m->fecha.mm, m->fecha.dd,
           m->fecha.hh.hh, m->fecha.hh.mm, m->fecha.hh.ss,
           m->mov, m->monto);
    return 1;
//    strrchr(aux, ' ');
//    sscanf(aux + 1, "%10.2f", m->monto);
//    *aux = '\0';
//    strrchr(aux, ' ');
//    sscanf(aux + 1, "(%c)", m->mov);
//    *aux = '\0'
}
