#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int colaCreaVacia(Cola *c) {
	if (c == NULL) return -1;
	c->frente = c->fondo = NULL;
	return 0;
}

int colaVacia(Cola *c) {
	if (c == NULL) return -1;
	return (c->frente == NULL && c->fondo == NULL);
}

int colaInserta(Cola *c, tipoElemento elemento) { 
	if(c == NULL) return -1;

	tipoCelda *celda;
	if((celda = malloc(sizeof(tipoCelda))) == NULL) return -2;

	celda->elemento = elemento;
	celda->sig = NULL;

	if (c->fondo == NULL) c->frente = c->fondo = celda;
	else c->fondo = c->fondo->sig = celda;
	return 0;
}

tipoElemento colaSuprime(Cola *c) {
	if(c == NULL || c->frente == NULL) return NULL;

	tipoCelda *aBorrar = c->frente;
	tipoElemento elemento = aBorrar->elemento;

	c->frente = aBorrar->sig;
	if(aBorrar == c->fondo) c->fondo = c->frente;
	free(aBorrar);
	return elemento;
}