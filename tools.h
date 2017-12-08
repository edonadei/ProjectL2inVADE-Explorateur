#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
// Libération de la mémoire
void print_tree_all();
void freeTabInt(int **tab,int x_tab); //On libère la mémoire d'un tableau 2D de int
void freeTabChar(char **tab,int x_tab); //On libère la mémoire d'un tableau 2D de char
char* malloc_tad1D(int size); //On alloue une chaine de caractère

// FONCTIONS D'AFFICHAGE
void dossier_ou_fichier(tree a);
void show_folder_childs(tree a);
void arborescence(tree a);
void browse_expl(tree a);
void show_tags(taglist t);
void _print_n_char(char c, int n);
void print_array(char *t);
void print_tree(tree a, int p);   // p = profondeur de l'arbre

//Copie de LSC
calendlist copy_lsc_calend(calendlist a);
#endif // TOOLS_H_INCLUDED
