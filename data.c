#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

/*
 * This function create tab which contains object
 * an object is an item which is characterized by size_ and cost
 */

Object* generate_object_randomly(int a, int b, int size_){
  srand(time(NULL));
  Object* t = NULL;
  t = (Object*)malloc(size_ * sizeof(Object));
  if(!t){
    perror("Allocation error");
  }
  for (int i = 0; i < size_; i++) {
    t[i].size = ((double)rand()/RAND_MAX) * (b - a) + a;
    t[i].cost = ((double)rand()/RAND_MAX) * (b - a) + a;
  }
  return t;
}

/*
 * This function returns the bag capacity which depends
 * of the interval values
 */

double generate_bag_capacity(Object* t, int size_){
  double sum = 0;
  for (int i = 0; i < size_; i++) {
    sum += t[i].size * ALPHA;
  }
  return sum;
}

int count_sum(int** tab, Object* t, int size){
  int cost = 0;
  int costTabFin = 0;
  int** tabFin = [][];

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      index = tab[i][j];
      size = size + t[index].size;
      cost = cost + t[index].cost;
    }
    if(size <= max_size){
      if(t[index].cost > costTabFin){
        tabFin = index;
        costTabFin = t[index].cost;
      }
    }
  }
  return tabFin;
}
