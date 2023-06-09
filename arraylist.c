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

if(l->size == l->capacity){
  l-> data = realloc(l->data, sizeof(void*)*l->capacity*2); 
  l->capacity=l->capacity*2;
}
  l->data[l->size]=data;  
  l->size++;
}

void push(ArrayList * l, void * data, int i){

  if(i > l->size)return; 
  
  if(l->size == l->capacity){
    l-> data = realloc(l->data, sizeof(void*)*l->capacity*2); 
    l->capacity=l->capacity*2; }
    
  for(int z=l->size; z>i; z--){
    l->data[z]=l->data[z-1]; 
  } 
    l->data[i] = data; 
    l->size++;
  

}

void* pop(ArrayList * l, int i){
  
  if(l->size==0)return NULL;
  if(i>=l->size)return NULL;
  if(i<0){
    get(l,i);
    l->data[l->size] = NULL; 
  }
  else{
  for(int z=i+1; z<l->size; z++)
    l->data[z-1]=l->data[z]; 
  }
   l->size--;
  return l->data[l->size];   
}

void* get(ArrayList * l, int i){
  
  if(i >= l->size)return NULL;
  if(i<0)i = l->size+i;
    
  /*if(i<0){
    for(int z=l->size; z>i; z--)
      return l->data[z];
  }
  l->data = l->data[l->size];*/
  return l->data[i];

}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  free(l->data); 
  l->data = NULL;
  l->size= 0; 
  l->capacity = 2;
}
