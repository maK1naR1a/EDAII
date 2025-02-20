#include "cola.h"
#include <stdlib.h>
#include <stdio.h>

// Inicializa una cola vacía
void colaCreaVacia(Cola *cola) {
    cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = NULL;
    cola->cola = NULL;
    return;
}

int colaVacia (Cola *cola)
{
    if(cola->frente == NULL)
    {
        return 0;
    }
    return 1;
}

void colaInserta (Cola *cola, tipoNodo *dato)
{
   Nodo *nuevo;
   nuevo->dato = dato;
   if (colaVacia(cola))
   {
    nuevo->siguiente = NULL;
    cola->cola = nuevo;
    cola->frente = nuevo;
    return;
   }
   nuevo->siguiente = cola->cola;
   cola->cola = nuevo;
   return;
}

tipoNodo* colaSuprime(Cola *cola)
{
    Nodo *aux = cola->cola;
    if (colaVacia(cola)) {return NULL;}
    if (aux == cola->frente)
    {
        cola->cola = NULL;
        cola->frente = NULL;
        return aux->dato;
    }
    while (aux->siguiente->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    tipoNodo *valor = aux->siguiente->dato;
    aux->siguiente = NULL;
    cola->frente = aux;
    free(aux->siguiente);
    return valor;
}

