#include "funciones.h"

int factorial(int n)
{
    if(n == 0){
        return 1;
    }
    return n*factorial(n-1);
}

int exponencial(int base, unsigned exponente)
{
    if(exponente == 0){
        return 1;
    }
    else{
        return base * exponencial(base, exponente-1);
    }
}

int cantChar(char *c){
    if(*c == '\0')
        return 0;

    return 1 + cantChar(c+1);
}


void ejercicio1(const char *c){
    if(*c == '\0')
        return;
    printf("%c\n", *c);
    ejercicio1(c+1);
}

void ejercicio2(const char *c){
    if(*c == '\0')
        return;
    ejercicio2(c+1);
    printf("%c\n", *c);
}

void ejercicio3(const char *c){
    if(*c == '\0')
        return;
    puts(c);
    ejercicio3(c+1);
}

void ejercicio4(const char *c){
    if(*c == '\0')
        return;
    ejercicio4(c+1);
    puts(c);
}

void ejercicio5(const char *c){
    if(*(c+1) == '\0'){
        printf("%c\n", *c);
        return;
    }
    printf("%c\n", *c);
    ejercicio5(c+1);
    printf("%c\n", *c);
}

void ejercicio6(const char *c){
    if(*(c+1) == '\0'){
        printf("%c\n", *c);
        return;
    }
    printf("%c\n", *c);
    ejercicio6(c+1);
    printf("%c\n", *c);
}

void ejercicio7(const char *c){
    if(*c == '\0')
        return;

    puts(c);
    ejercicio7(c+1);
}

void ejercicio8(int n){//no me salio
    if(n == 0)
        return;

    printf("%d\n", n%10);
    ejercicio8(n/10);
}

void ejercicio9(int n){
    if(n == 0)
        return;

    ejercicio9(n/10);
    printf("%d\n", n%10);
}

void ejercicio10(int n){
    int resto = n, mult = 1;
    if(n < 10){
        printf("%d\n", n);
        return;
    }

    while(resto > 10){
        mult *= 10;
        resto = resto/10;
    }
    printf("%d\n", n);
    ejercicio10(n-(mult*resto));
}

void ejercicio11(int n){
    if(n == 0)
        return;

    printf("%d\n", n);
    ejercicio11(n/10);
}

void ejercicio12bis(int n){
    int resto = n, mult = 1;
    if(n == 0)
        return;
    while(resto > 10){
        mult *= 10;
        resto = resto/10;
    }

    ejercicio12bis(n%mult);
    printf("%d\n", n%(mult*10));
}

void ejercicio12(int n){//no me gusta
    ejercicio12bis(n);
    ejercicio10(n);
}

int ejercicio13(const char * str, int pos)
{
    char * fin = strchr(str, '\0') - pos;
        printf("%c|%c\n", tolower(*str), tolower(*fin));    if(str >= fin){
        return 1;
    }
    while(!ES_LETRA(*fin)){
        fin--;
    }
    while(!ES_LETRA(*str)){
        str++;
    }
    if(tolower(*str) !=  tolower(*fin)){
        return 0;
    }
    return ejercicio13(str+1, strlen(fin)+1);
}
