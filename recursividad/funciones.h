#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string.h>
#define ES_LETRA(X) ((((X)>='a'&&(X)<='z')||((X)>='A'&&(X)<='Z'))?1:0)

int factorial(int n);
int exponencial(int base, unsigned exponente);
int cantChar(char *c);
void ejercicio1(const char *c);
void ejercicio2(const char *c);
void ejercicio3(const char *c);
void ejercicio4(const char *c);
void ejercicio5(const char *c);
void ejercicio6(const char *c);
void ejercicio7(const char *c);
void ejercicio8(int n);
void ejercicio9(int n);
void ejercicio10(int n);
void ejercicio11(int n);
void ejercicio12bis(int n);
void ejercicio12(int n);
int ejercicio13(const char * str, int pos);

//TO DO
//mostrar
//h  a  a    hola  h
//o  l  la    ola  ho
//l  o  ola    la  hol
//a  h  hola    a  hola
//y un par mas que no me acuerdo
#endif // FUNCIONES_H_INCLUDED
