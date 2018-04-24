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

int find_best_sum(int** tab, Object* t, int size, int max_size){
  int actualcost = 0;
  int actualsize = 0;
  int bestcost = 0;
  int index=0;

  for(int i = 0; i < size; i++){
    int j = 0;
    actualcost = 0;
    actualsize = 0;
    while (tab[i][j] != -1){
      actualcost += t[tab[i][j]].cost;
      actualsize += t[tab[i][j]].size;
      j++;
    }
    if(actualsize <= max_size){
      if(actualcost > bestcost){
        bestcost = actualcost;
        index = i;
      }
    }
  }
  return index;
}
