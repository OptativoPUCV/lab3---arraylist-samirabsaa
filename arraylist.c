#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *aux = (ArrayList *) malloc(sizeof(ArrayList)); 
  if(aux == NULL) exit(EXIT_FAILURE); 
  aux-> capacity = 2; 
  aux ->data = (void *) malloc(sizeof(void) * aux->capacity); 
  aux -> size = 0;

  return aux; 
}

void append(ArrayList * l, void * data){


if(l->size != l->capacity){ 
  l->data[l->size]=data;  
  l->size++; 
  
}
else if(l->size == l->capacity){
l-> data = realloc(data, l->capacity*2); 
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
