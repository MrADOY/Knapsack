/* Knapsack problem */
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "display.h"
#include "utils.h"

int main(int argc, char const *argv[]) {
  printf("Le fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);
  int sortie=0, n=0, poids=0, best_combinaison=0, total_poids_meilleur=0, total_cout_meilleur=0;
  int total_poids=0, total_cout=0;
  char menu1;
  char menu2;
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
    color(GREEN,"\t=== Menu ===");
    puts("1 - Générer les objets");
    puts("2 - Voir les tableaux");
    puts("3 - Voir les variables");
    puts("0 - Quitter");
    bold("\nEntrez votre choix : ");
    scanf(" %c",&menu1);
    puts("");
    switch(menu1) {
      case '1':
      color(YELLOW,"\t=== Génération ===");
      color(GREEN,"\t\t=== Menu de génération===");
      do{
        puts("\t1 - Générer les objets aléatoirement");
        puts("\t2 - Générer les objets dynamiquement");
        puts("\t0 - Quitter");
        bold("\nEntrez votre choix : ");
        scanf(" %c", &menu2);


        switch(menu2){
          case '1':
          if (n>10) {
            n=10;
          }
          tab = generate_combinaisons(n);
          tab_obj=generate_object_randomly(10,100,n);
          poids=generate_bag_capacity(tab_obj,n);
          best_combinaison=find_best_sum(tab,tab_obj,(1 << n)-1,poids);
          bold("\n\t\t=== Objets générés aléatoirement ===");
          menu2='0';
          break;

          case '2':
          if (n>10) {
            n=10;
          }
          tab_obj=generate_object_randomly(10,100,n);
          poids=generate_bag_capacity(tab_obj,n);
          tab = version_prog_dynamique(tab_obj,poids+1,n);
          find_solution(tab,n,poids,tab_obj);

          for (int i = 0; i < n; i++) {
          }
          bold("\n\t\t=== Objets générés dynamiquement ===");
          menu2='0';
          break;


          case '0':
          break;

          default:
          error("Choix non reconnu !");
          break;
        }

      }while(menu2 != '0');

      color(BLUE,"\t=== Retour au menu principal ===");
      break;

      case '2':
      if (tab != NULL) {
        int i=0;
        total_poids=0;
        total_cout=0;
        color(CYAN,"\t=== Objets ===");
        printf("POIDS | PRIX\n");
        while (i < n) {
          printf("   %d | %d\n", tab_obj[i].size, tab_obj[i].cost);
          total_poids+=tab_obj[i].size;
          total_cout+=tab_obj[i].cost;
          i++;
        }

        int j=0;
        total_poids_meilleur=0;
        total_cout_meilleur=0;
        color(CYAN,"\t=== Objets dans le sac ===");
        printf("POIDS | PRIX\n");
        while (tab[best_combinaison][j] != -1) {
          printf("   %d | %d\n", tab_obj[tab[best_combinaison][j]].size, tab_obj[tab[best_combinaison][j]].cost);
          total_poids_meilleur+=tab_obj[tab[best_combinaison][j]].size;
          total_cout_meilleur+=tab_obj[tab[best_combinaison][j]].cost;
          j++;
        }
      }
      color(BLUE,"\t=== Retour au menu ===");
      break;

      case '3':
      color(YELLOW, "\t=== Variables ===");
      color(CYAN,"\t\t=== Objets ===");
      printf("\tNombre total d'objets : %d\n", n);
      if (total_cout>0) {
        printf("\tCoût total des objets : %d\n", total_poids);
        printf("\tPoids total des objets : %d\n", total_cout);
      }
      if (total_poids_meilleur>0) {
        color(CYAN,"\t\t=== Sac ===");
        if (poids>0) {
          printf("\tCapacité du sac : %d\n", poids);
          printf("\tCapacité restant dans le sac : %d\n", poids-total_poids_meilleur);
        }
        printf("\tPoids total des objets dans le sac : %d\n",  total_poids_meilleur);
        printf("\tCoût total des objets dans le sac : %d\n", total_cout_meilleur);
      }
      color(BLUE,"\t=== Retour au menu ===");
      break;


      case '0':
      color(YELLOW,"\t=== Sortie ===");
      sortie=1;
      break;

      default:
      error("Choix non reconnu !");
      break;
    }
  }

  return EXIT_SUCCESS;
}
