#ifndef __COLA_H
#define __COLA_H
#include "arbol.h"

typedef struct Nodo
{
    tipoNodo *dato;
    struct Nodo *siguiente;
}Nodo;


typedef struct Cola
{
    Nodo *frente;
    Nodo *cola;
}Cola;

void colaCreaVacia(Cola *cola);
void colaInserta(Cola *cola, tipoNodo *dato);
tipoNodo* colaSuprime(Cola *cola);
int colaVacia(Cola *cola);

#endif