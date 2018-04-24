/* Knapsack problem */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "display.h"
#include "utils.h"

int main(int argc, char const *argv[]) {
  printf("Le fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);
  int sortie=0, n=0, poids=0, best_combinaison=0;
  char menu1;
  int **tab = NULL;
  Object *tab_obj = NULL;
  if (argc>1 && argv[1]) {
    n = atof(argv[1]);
  }
  else {
    error("Utilisation : ./main <Nombre d'objets> !");
    exit(1);
  }
  while(sortie==0) {
    puts("");
    puts("=== Menu ===");
    puts("1 - Voir les variables");
    puts("2 - Générer les objets");
    puts("0 - Quitter");
    puts("\nEntrez votre choix : ");
    scanf(" %c",&menu1);
    puts("");
    switch(menu1) {
      case '1':
      puts("=== Variables ===");
      printf("Nombre d'objets : %d\n", n);
      printf("Poids : %d\n", poids);
      if (tab != NULL) {
        // puts("=== Combinaisons ===");
        // print_tab(tab,n);
        int i=0;
        puts("=== Objets ===");
        while (i < n) {
          printf("%d / %d\n", tab_obj[i].size, tab_obj[i].cost);
          i++;
        }

        int j=0;
        puts("=== Meilleure combinaison ===");
        while (tab[best_combinaison][j] != -1) {
          printf("%d / %d\n", tab_obj[tab[best_combinaison][j]].size, tab_obj[tab[best_combinaison][j]].cost);
          j++;
        }
      }

      puts("=== Fin de l'affichage ===");

      break;

      case '2':
      puts("=== Génération ===");
      tab = generate_combinaisons(n);
      tab_obj=generate_object_randomly(10,100,n);
      poids=generate_bag_capacity(tab_obj,n);
      best_combinaison=find_best_sum(tab,tab_obj,n,poids);
      puts("=== Nombres générés ===");
      break;

      case '0':
      puts("=== Sortie ===");
      sortie=1;
      break;

      default:
      error("Choix non reconnu !");
      break;
    }
  }

  return EXIT_SUCCESS;
}
