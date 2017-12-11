#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

typedef struct  node {
  struct node* siguiente;
  char* tipo;
  char* nombre;
  char* valor;
} nodo;

typedef struct {
  nodo * head;
} lista;

extern lista* tablaSim; //Variable global

nodo* search(lista* l, char* nombre);
void  update(lista* l, char* nombre, char* valor);
nodo* create(char* tipo, char* nombre, char* valor);
nodo* insert(lista* l, char* tipo, char* nombre, char* valor);

#endif