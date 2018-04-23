#include <stdlib.h>
#include <stdio.h>

void print_tab(int* tab,int size){
  for (int i = 0;i < size; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}

int* generate_combinaisons(const int size){

  /*
  * Generate tab which contains values 1 to n
  */
  int* tab = NULL;
  tab = (int*)malloc(size *sizeof(int));
  for(int i = 0; i < size; i++){
    tab[i] = i + 1;
  }

  int actual_size = 1;
  int* combinaison = NULL;
  /* Generate all the combinaison */
  for (int i = 0; i < size; i++) {
    combinaison = (int*) malloc(actual_size * sizeof(int));
    for (int j = i; j < size; j++) {
      combinaison[actual_size - 1] = tab[j];
      print_tab(combinaison,actual_size);
      actual_size++;
    }
    free(combinaison);
    actual_size = 1;
  }

  return NULL;
}
