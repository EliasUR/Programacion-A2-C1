//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void moverChrXpos(char* str, int x);
//char *moverStrXpos(char* str, int x);
//void darVuelta(char *inicio, char *fin);
//void desofuscar(char *str, char *movidas);
//
//int main()
//{
//    char str[] = "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA",
//         movidas[] = "acefhijklo";
//    printf("%s\n",str);
//    printf(".............................\n");
//    desofuscar(str, movidas);
//    printf("%s\n",str);
//    return 0;
//}
//
//void desofuscar(char *str, char* movidas){
//    char *reemplazo,
//         *inicioPalabra = str;
//    while(*str){
//        if( (reemplazo = strchr(movidas, *str)) ){
//            if(*(reemplazo+1) == '\0' || *(reemplazo+2) == '\0' || *(reemplazo+3) == '\0'){
//                reemplazo -= strlen(movidas);
//            }
//            *str = *(reemplazo+3);
//        }
//        if(*(str+1) == ' ' || *(str+1) == ';' || *(str+1) == '.' || *(str+1) == '\0'){
//            darVuelta(inicioPalabra, str);
//            inicioPalabra = str+2;
//        }
//        str++;
//    }
//}
//
//
//void darVuelta(char *inicio, char *fin){
//    char aux;
//    while(inicio < fin){
//        aux = *inicio;
//        *inicio = *fin;
//        *fin = aux;
//        inicio++;
//        fin--;
//    }
//}
//
//char *moverStrXpos(char* str, int x){
//    char *movStr = str + strlen(str) -1 -x;
//    while(*movStr){
//        moverChrXpos(movStr, x);
//        movStr--;
//    }
//    printf("%s\n", str);
//    return movStr;
//}
//
//void moverChrXpos(char* str, int x){
//    int i = 0;
//    char aux = *str;
//    for(i=0;i<x;i++){
//        *str = *(str+1);
//      printf("%c",*str);
//        str++;
//    }
//    *str = aux;
//      printf("%c",*str);
//    printf("\n.............................\n");
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pepito(char x);
int cantidadLetras (char* linea);
void darVueltaPalabra (char* inicio, char* final);
void cambiarLetras (char*inicio, int cant);
void desofuscarLinea (char* linea);

int main()
{
    char linea[]="jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA";

    desofuscarLinea(linea);

    puts(linea);

    return 0;
}

int identificarPalabra (char* linea)
{
    int i=0;

    while(pepito(*linea))
    {
        i++;
        linea++;
    }

    return i;
}

void darVueltaPalabra (char* inicio, char* final)
{
    char aux;

    while(inicio<final)
    {
        aux=*inicio;
        *inicio++=*final;
        *final--=aux;
    }
}

void cambiarLetras (char* linea, int cant)
{
    char desofuscar[]="acefhijklo",
         * letra,
         * final;
    int longitud;

    longitud=strlen(desofuscar);
    final=desofuscar+longitud-1;

    while(cant--)
    {
        if((letra=strchr(desofuscar, *linea)))
        {
            letra+=3;

            if(letra>final)
                letra-=longitud;

            *linea=*letra;
        }

        linea++;
    }
}

void desofuscarLinea (char* linea)
{
    int cantLetras;

    while(*linea)
    {
        if(pepito(*linea))
        {
            cantLetras=identificarPalabra(linea);
            darVueltaPalabra(linea, linea+cantLetras-1);
            cambiarLetras(linea, cantLetras);
            linea+=cantLetras;
        }
        else
            linea++;
    }
}

int pepito(char x){
    return (x == ' ' || x == ';' || x == '.' || x == '\0')? 0 : 1;
}
