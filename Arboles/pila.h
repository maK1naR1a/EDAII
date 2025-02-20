#ifndef __PILA_H
#define __PILA_H
#include "arbol.h"

typedef struct tipoElemento
{
    tipoNodo dato;
    tipoNodo *siguiente;
}tipoElemento;

typedef struct Pila
{
    tipoElemento *cima;
}Pila;

#endif
