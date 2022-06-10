#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ES_LETRA(X) (((X)>='a'&&(X)<='z')||((X)>='A'&&(X)<='Z'))

void eliminarBlancosDemas(char *str);
void mayus(char *chr);
void minus(char *chr);
char *normalizarPalabra(char *str);
char *normalizarCadena_MIO(char *str);

int main()
{
    char *str = "    anita.  LAVa la tinA!";
    puts(str);
    puts(normalizarCadena_MIO(str));
    return 0;
}



char *normalizarCadena_MIO(char *str)
{
    char *salto;
    if(str){
                puts(str);

        eliminarBlancosDemas(str);
    puts(str);
        while(*salto != '\0')
        {
            salto = normalizarPalabra(str);
            eliminarBlancosDemas(str);
        }
    }
    return str;
}

void eliminarBlancosDemas(char *str)
{
    char *letra = str;
    while(*letra == ' '){
        letra++;
    }
    while(*letra != ' '){
        *str = *letra;
        if(*str != '\0'){
            *letra = ' ';
        }
        letra++;
        str++;
    }
    puts(aux);
}

char *normalizarPalabra(char *str)
{
    mayus(str);
    str++;
    while(ES_LETRA(*str)){
        minus(str);
        str++;
    }
    while(*str != ' ' && *str != '\0'){
        str++;
    }
    if(*str != '\0'){
        str++;
    }
    return str;
}

void mayus(char* chr)
{
    *chr = (*chr >= 'a' && *chr <= 'z')? *chr - ('a' - 'A'): *chr;
}

void minus(char* chr)
{
    *chr = (*chr >= 'A' && *chr <= 'Z')? *chr + ('a' - 'A'): *chr;
}
