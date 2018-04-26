#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void error(char *message);
void bold(char *message);
void color(char *color, char *message);
void affiche_tab_total(int **tab_combinaisons, Object *tab_obj, int best_combinaison, int *total_poids_meilleur, int *total_cout_meilleur);
void affiche_tab_obj(Object *tab_obj, int *total_poids, int *total_cout, int nb_objets_total);
void affiche_tab_dynamique(int *tab, Object *tab_obj, int *total_poids_meilleur, int *total_cout_meilleur, int taille_sol);
void affiche_var(int n, int poids, int total_cout, int total_poids, int total_poids_meilleur, int total_cout_meilleur);
void affiche_tab_glouglou(int *tab, Object *tab_obj, int *total_poids_meilleur, int *total_cout_meilleur);

#endif
