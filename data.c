#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

/*
 * This function create tab which contains object
 * an object is an item which is characterized by size and cost
 */

Object* generate_object_randomly(int a, int b){
  srand(time(NULL));
  Object* t = NULL;
  t = (Object*)malloc(SIZE * sizeof(Object));
  if(!t){
    perror("Allocation error");
  }
  for (int i = 0; i < SIZE; i++) {
    t[i].size = ((double)rand()/RAND_MAX) * (b - a) + a;
    t[i].cost = ((double)rand()/RAND_MAX) * (b - a) + a;
  }
  return t;
}

/*
 * This function returns the bag capacity which depends
 * of the interval values
 */

double generate_bag_capacity(Object* t, int ALPHA){
  double sum = 0;
  for (int i = 0; i < SIZE; i++) {
    sum += t[i].size * ALPHA;
  }
  return sum;
}
