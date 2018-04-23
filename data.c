#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "data.h"

Object* generate_tab_randomly(int a,int b, int size_){
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

double generate_bag_capacity(Object* t,int size_,int alpha){
  double sum = 0;
  for (int i = 0; i < size_; i++) {
    sum += t[i].size * alpha;
  }
  return sum;
}
