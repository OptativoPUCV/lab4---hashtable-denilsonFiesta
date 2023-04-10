#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {

  long newPos = hash(key, map->capacity);

  if( *(map->buckets+newPos) == NULL){

    *(map->buckets+newPos) = createPair(key, value);
    
  }else{
    
    for(long i = 0, it = newPos+1; i < map->capacity; i++, it++){
      it = it%map->capacity;
      if(*(map->buckets+it) ==  NULL){
        *(map->buckets+it) = createPair(key, value);
        break;
      }
    }
  }
  map->size++;
  
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap* nuevo = (HashMap*) calloc(1, sizeof(HashMap));

  nuevo->buckets = (Pair**) calloc(capacity, sizeof(HashMap));

  nuevo->current = -1;
  nuevo->size = 0;
  nuevo->capacity = capacity;
  
  
  return nuevo;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   

  long pos = hash(key, map->capacity);

  if(is_equal(key, *(map->buckets+pos)->key)){
    return map->buckets+pos);
  }


  return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
