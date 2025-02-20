#ifndef __PILA_H
#define __PILA_H
#include "arbol.h"

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef tipoNodo * tipoElemento;
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda * sig;
	} tipoCelda;
#endif

typedef tipoCelda * Pila;

int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);


#endif