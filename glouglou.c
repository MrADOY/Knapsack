#include "glouglou.h"
#include "data.h"
#include "utils.h"
#include <stdlib.h>

int *glouglou(Object *t, int size){

  glou **tab;
  tab = malloc(sizeof (glou*) * size);
  for (int i = 0; i < size; i++) {
    tab[i] = malloc(sizeof (glou)*1);
  }
  for (int i = 0; i < size; i++) {
    tab[i]->rapport = ((double)t[i].size / t[i].cost);
    tab[i]->index = i;
  }
  for (int i = 0; i < size; i++) {
    printf("%f\n",tab[i]->rapport);
  }
  tri_fusion(tab, size);

  for (int i = 0; i < size; i++) {
    printf("%f\n",tab[i]->rapport);
  }

}
