#include "glouglou.h"
#include "data.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>


void swap(glou *t, int a, int b){
 glou tmp;
 tmp = t[a];
 t[a] = t[b];
 t[b] = tmp;
}

int partition(glou* tab, int first, int last, int pivot){
  swap(tab, pivot, last);
  int j = first;
  for (int i = j; i < last; i++) {
    if (tab[i].rapport >= tab[last].rapport){
      swap (tab, i, j);
      j++;
    }
  }
  swap(tab, last, j);
  return j;
}

void quick_sort(glou *tab, int first, int last){
  int pivot;
  if (first < last){
    pivot = (((double)rand()/RAND_MAX) * (last-first) + first);
    pivot = partition(tab, first, last, pivot);
    quick_sort(tab, first, pivot-1);
    quick_sort(tab, pivot+1, last);
  }
}



int *glouglou(Object *t, int size, double max_bag){


  glou *tab;
  double currentbag=0;
  int *finalbag;
  int notfull = 1;
  int i = 0;

  tab = malloc(sizeof (glou) * size);
  finalbag = malloc(sizeof (int)*size);

  for (int i = 0; i < size; i++) {
    tab[i].rapport = ((double)t[i].cost / (double)t[i].size);
    tab[i].index = i;
  }
  quick_sort(tab, 0, size-1);
  while (notfull){
    currentbag += t[tab[i].index].size;
    if (currentbag < max_bag){
      finalbag[i] = tab[i].index;
      i++;
    }
    else{
      finalbag[i] = -1;
      notfull = 0;
    }
  }
  free(tab);
  return finalbag;
}
