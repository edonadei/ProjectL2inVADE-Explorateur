#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
// Lib�ration de la m�moire
void print_tree_all();
void freeTabInt(int **tab,int x_tab); //On lib�re la m�moire d'un tableau 2D de int
void freeTabChar(char **tab,int x_tab); //On lib�re la m�moire d'un tableau 2D de char
char* malloc_tad1D(int size); //On alloue une chaine de caract�re

// FONCTIONS D'AFFICHAGE
void dossier_ou_fichier(tree a);
void show_folder_childs(tree a);
void arborescence(tree a);
void browse_expl(tree a);
void show_tags(taglist t);
void _print_n_char(char c, int n);
void print_array(char *t);
void print_tree(tree a, int p);   // p = profondeur de l'arbre
char* number_to_hours(int i);
char* number_to_days(int i);
void menu(int h, int j, tree a, calendlist c);
char* arborescence_string(tree a);
char *print_tag_echeance(tree a);

//Copie de LSC
calendlist copy_lsc_calend(calendlist a);
listnode add_listnodes(listnode l, tree a);

#endif // TOOLS_H_INCLUDED
