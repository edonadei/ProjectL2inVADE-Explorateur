#ifndef STRUCT_FUNCT_H_INCLUDED
#define STRUCT_FUNCT_H_INCLUDED



// FONCTION DE GESTION DE L'ARBRE

tree init_new_tree(char* name_of_tree, int typechoice,tree father);
tree add_next(tree n,char* node_name,int typechoice);
tree add_child(tree n,char* node_name,int typechoice);

// FONCTIONS DE GESTION DES TAGS

taglist init_new_tag(char* name_of_tag);
taglist add_tag(taglist t,char* name_of_tag);

// FONCTIONS DE GESTION DES CALENDRIERS

calendlist init_new_calend(char *name_of_calend,int heure,int jour, int importance, char* tag1, char* tag2, char* tag3);
calendlist add_calend(calendlist t,char* name_of_calend, int heure,int jour, int importance,char* tag1, char* tag2, char* tag3);
void _list_echeance_by_score(calendlist c, int h, int j,int nbr_iteration);
void list_echeance(calendlist c, int h, int j,int nbr_iteration);
void list_echeance_by_score(calendlist c, int h, int j,int nbr_iteration);
int compare_temps(int j1, int j2, int h1, int h2);

// FONCTION DE GESTION DES FILTRES

calendlist filtre_liste_echeance (calendlist a,char* tag1,char* tag2);
void _filtre_liste_echeance (calendlist c,char* tag1,char* tag2);
int check_if_tag_exist(taglist a, char* tag1);

//FONCTIONS DE RECHERCHE DANS L'ARBRE

void recherche_fichier_selon_tags (tree a,tree b,char* tag1, char* tag2, char* tag3);
listnode init_new_lscnode(tree a);
void recherche_fichier_selon_tags_v2 (tree a,listnode b,char* tag1, char* tag2, char* tag3);
void show_listnode(listnode l);

#endif // STRUCT_FUNCT_H_INCLUDED
