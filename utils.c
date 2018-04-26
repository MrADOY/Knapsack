#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glouglou.h"
#include "utils.h"
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
* Sort with tri fusion
*/

void tri_fusion(glou** tab,int n){
    tri_fusion2(tab,0,n - 1);
}

void tri_fusion2(glou** tab,int p, int r){
    int quotient;

    if(p < r){
      quotient = (p + r) / 2;
      tri_fusion2(tab,p,quotient);
      tri_fusion2(tab,quotient + 1 ,r);
      fusionner(tab,p,quotient,r);
    }
}

void fusionner(glou** tab, int p , int q , int r){
  int n1 , n2;

  n1 = q - p + 1;
  n2 = r - q;

  glou* Left[n1];
  glou* Right[n2];
  for (int i = 0; i < n1; i++) {
    Left[i] = tab[p + i];
  }
  for (int j = 0; j < n2; j++) {
    Right[j] = tab[q + j + 1];
  }
  Left[n1]->rapport = RAND_MAX+1;
  Right[n2]->rapport = RAND_MAX+1;
  int i = 0 ;
  int j = 0 ;
  for(int k = p ; k <= r; k++){
    if(Left[i]->rapport >= Right[j]->rapport){
      tab[k] = Left[i];
      i++;
    }else{
      tab[k] = Right[j];
      j++;
    }
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
