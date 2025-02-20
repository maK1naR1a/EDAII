#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{ Cola c;
  tipoNodo *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz!=NULL) colaInserta(&c,nodo);
  while (!colaVacia(&c))
  { nodo = (Arbol) colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq!=NULL) colaInserta(&c,nodo->izq);
    if (nodo->der!=NULL) colaInserta(&c,nodo->der);
  }
}
int altura(Arbol raiz)
{
    if (raiz==NULL) return 0;
    else
    { int altIzq, altDer;
      altIzq = altura(raiz->izq);
      altDer = altura(raiz->der);
      if (altIzq>altDer) return altIzq+1;
      else return altDer+1;
    }
}
int numNodos(Arbol raiz)
{
    if (raiz==NULL) return 0;
    else return 1+numNodos(raiz->izq)+numNodos(raiz->der);
}
Arbol anula(Arbol raiz)
{
}
int numNodosHoja(Arbol raiz)
{
    if (raiz==NULL) return 0;
    else if (raiz->izq==NULL && raiz->der==NULL) return 1;
    else return numNodosHoja(raiz->izq)+numNodosHoja(raiz->der);
}
int numNodosInternos(Arbol raiz)
{
    if (raiz==NULL) return 0;
    else if (raiz->izq==NULL && raiz->der==NULL) return 0;
    else return 1+numNodosInternos(raiz->izq)+numNodosInternos(raiz->der);
}
int numHijoUnico(Arbol raiz)
{
    if (raiz==NULL) return 0;
    else if (raiz->izq==NULL && raiz->der!=NULL) return 1+numHijoUnico(raiz->der);
    else if (raiz->izq!=NULL && raiz->der==NULL) return 1+numHijoUnico(raiz->izq);
    else return numHijoUnico(raiz->izq)+numHijoUnico(raiz->der);
}
Arbol buscarMax(Arbol raiz)
{
    if (raiz==NULL) return NULL;
    else if (raiz->der==NULL && raiz->izq==NULL) return raiz;
    else return buscarMax(raiz->der) < buscarMax(raiz->izq)? buscarMax(raiz->izq):buscarMax(raiz->der);
}
//
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}
