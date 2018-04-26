#ifndef __UTILS_H__
#define __UTILS_H__

/*
* Generate all the combinaisons for pow(2,n) values without
* repetitions
*/
int** generate_combinaisons(int n);

/*
* Print the combinaison
*/
void print_tab(int** tab, int n);

void tri_fusion(glou** tab,int n);

void fusionner(glou** tab, int p , int q , int r);

void tri_fusion2(glou** tab,int p, int r);

#endif
