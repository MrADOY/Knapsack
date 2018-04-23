#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
* Print a int** tab
*/

void print_tab(int** tab, int n){
  int j = 0;
  for (int i = 0; i < (1 << n) - 1; i++) {
    while(tab[i][j] != -1){
      printf("%d ", tab[i][j]);
      j++;
    }
    j = 0;
    printf("\n");
  }
}

/*
* Generate all the combinaison of n elements
*/

int** generate_combinaisons(int n) {
  // size of the current combinaison
  int s = 0;
  // number of current combinaison
  int num = 0;
  // 1 << n == pow(2,n)
  int** combinaisons = (int**) malloc((1 << n) * sizeof(int*));
  for(int i = 0; i < (1 << n) ; i++){
    //For more ease in futur with put -1 at the end of combinaison
    combinaisons[i] = (int*) calloc(n,sizeof(int));
  }
  // Max we will have 2^n possibilities
  for(int i = 1 ;i < pow(2,n);i++) {
    // Max size of the combinaisons will be n
    for(int j = 0; j < n;j++){
      // We represent j in binairy and we check if we match with i
      if ((1<<j) & i){
        combinaisons[num][s] = j;
        s++;
      }
    }
    combinaisons[num][s] = -1;
    num++;
    // set or reset size of combinaison
    s = 0;
  }
  return combinaisons;
}
