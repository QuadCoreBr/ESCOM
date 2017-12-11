#include "TablaSimbolos.h"

nodo* create(char* a, char* b, char* c){
    nodo* n = (nodo*) malloc(sizeof(nodo));
    n->tipo  = (char*) malloc(sizeof(a)); 
    n->nombre  = (char*) malloc(sizeof(b)); 
    n->valor  = (char*) malloc(sizeof(c)); 
    strcpy(n->nombre, b);
    strcpy(n->valor, c);
    strcpy(n->tipo, a);
    n->siguiente = 0;
    return n;
}

nodo* insert(lista* l, char * tipo, char *nombre, char * valor) {
  nodo* n = create(tipo,nombre, valor);
  if (!l->head) 
    return l->head  = n;  
  nodo** x = &l->head;
  while ((*x)->siguiente)
    x = &(*x)->siguiente;
  return (*x)->siguiente = n;
} 

nodo* search(lista* l, char * nombre) {
  if (!l->head){
      return 0;
  }
  nodo** x =  &l->head;
  while ((*x)) {
    if (strcmp((*x)->nombre, nombre) == 0)
      return *x;
    x = &(*x)->siguiente;
  }
  return 0;
}

void update(lista* l, char * nombre, char * nuevo) {
  if (!l->head)   return;  
  nodo** x =  &l->head;
  while ((*x)) {
    if (strcmp((*x)->nombre, nombre) == 0) {
      (*x)->valor = (char*) malloc(sizeof(nuevo));
      strcpy((*x)->valor,nuevo);
      return;
    }
    x = &(*x)->siguiente;
  }     
}