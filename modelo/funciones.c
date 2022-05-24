/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "LIBERATI"
#define NOMBRE      "GIANFRANCO"
#define DOCUMENTO   "41.614.822"
#define COMISION    "07(7299)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/
#define ESLETRA(X)  ((X >= 'a' && X <= 'z') ||  (X >= 'A' && X <= 'Z'))
#include <string.h>
#include <stdlib.h>
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

char aMayuscula(char c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

char aMinuscula(char c)
{
    return (c >= 'a' && c <= 'z') ?  c : c + ('a' - 'A');
}

int ponerEnLista(tLista* lista, const void* dato, unsigned cantBytes)
{
    tNodo* aux;
    if((aux = (tNodo*)malloc(sizeof(tNodo))) == NULL || (aux->info = malloc(cantBytes)) == NULL)
    {
        return -1;
    }
    memcpy(aux->info, dato, cantBytes);
    aux->tamInfo = cantBytes;
    aux->sig = *lista;
    *lista = aux;
    return 1;
}

/** para el PUNTO 1 **/
char *normalizarCadena_MIO(char *str)
{
    char *escribo = str,
         *pal = str,
         *primerPal = str;

    while(*pal != '\0')
    {
        while(!ESLETRA(*pal) && *pal != '\0')
        {
            pal++;
        }
        if(*pal != '\0')
        {
            *escribo = aMayuscula(*pal);
            pal++;
            escribo++;
        }
        while(ESLETRA(*pal) && *pal != '\0')
        {
            *escribo = aMinuscula(*pal);
            pal++;
            escribo++;
        }
        if(primerPal == str)
        {
            *escribo = '.';
            escribo++;
            primerPal = NULL;
        }
        *escribo = ' ';
        escribo++;
    }
    *(escribo - 2) = '.';
    *(escribo - 1) = '\0';
    return str;
}
/** FIN de PUNTO 1 **/


/** para el PUNTO 2 **/
int fusionarMaestros_MIO(char *nombreArchivo1,
                         char *nombreArchivo2,
                         char *nombreArchivoF)
{
    tProducto p1;
    tProducto p2;
    FILE* f1 = fopen(nombreArchivo1, "rb");
    if(!f1)
    {
        return -1;
    }
    FILE* f2 = fopen(nombreArchivo2, "rb");
    if(!f2)
    {
        return -1;
    }
    FILE* ffinal = fopen(nombreArchivoF, "wb");
    if(!f1)
    {
        return -1;
    }

    fread(&p1, sizeof(tProducto), 1, f1);
    fread(&p2, sizeof(tProducto), 1, f2);
    while(!feof(f1) && !feof(f2))
    {
        while(!feof(f1) && ((p1.idProducto - p2.idProducto) < 0))
        {
            fwrite(&p1, sizeof(tProducto), 1, ffinal);
            fread(&p1, sizeof(tProducto), 1, f1);
        }
        fwrite(&p2, sizeof(tProducto), 1, ffinal);
        fread(&p2, sizeof(tProducto), 1, f2);
    }
    while(!feof(f1))
    {
        fwrite(&p1, sizeof(tProducto), 1, ffinal);
        fread(&p1, sizeof(tProducto), 1, f1);
    }
    while(!feof(f2))
    {
        fwrite(&p2, sizeof(tProducto), 1, ffinal);
        fread(&p2, sizeof(tProducto), 1, f2);
    }

    fclose(f1);
    fclose(f2);
    fclose(ffinal);
    return 0;
}
/** FIN de PUNTO 2 **/


/** para el PUNTO 3 **/
int cargarMaestroEnLista_MIO(char *nombreArchivoMaestro,
                                                tLista *pl,
                                                FILE *fpPantalla)
{
    tProducto prod;
    FILE* f = fopen(nombreArchivoMaestro, "rb");
    if(!f)
    {
        return -1;
    }
    rewind(f);
    fread(&prod, sizeof(tProducto), 1, f);
    while(!feof(f))
    {
        ponerEnLista(pl, &prod, sizeof(prod));
        fread(&prod, sizeof(tProducto), 1, f);
    }
    fclose(f);
    return 0;
}
/** FIN de PUNTO 3 **/


/** para el PUNTO 4 **/
int eliminarDupYsobrescibirMaestro_MIO(tLista *pl,
                                       int *cantDupEliminados,
                                       const char *nombreArchivoMaestro)
{
    *cantDupEliminados = -1;
    return -1;
}
/** FIN de PUNTO 4 **/


/** para el PUNTO 5 **/
int actualizarMaestroDesdeArchivoDeNovedades_MIO(char *nombreArchivoMaestro,
                                                 char *nombreArchivoNovedades,
                                                 FILE *fpPantalla)
{
    return -1;
}

/** FIN de PUNTO 5 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

