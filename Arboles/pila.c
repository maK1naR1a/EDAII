#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

Pila* crearPila() {
    Pila* nuevaPila = (Pila*)malloc(sizeof(Pila));
    nuevaPila->cima = NULL;
    return nuevaPila;
}

void pilaInserta(Pila *pila, tipoNodo elemento)
{
    tipoElemento *nuevo = (tipoElemento*)malloc(sizeof(tipoElemento));
    nuevo->dato = elemento;
    nuevo->siguiente = pila->cima;

    pila->cima = nuevo;
}

tipoNodo pilaSuprime(Pila *pila)
{
    if (pila->cima == NULL)
    {
        return NULL;
    }
    tipoElemento *borrar = pila->cima;
    pila->cima = borrar->siguiente;
    tipoNodo borrado = borrar->dato;
    free(borrar);
    return borrado;
}