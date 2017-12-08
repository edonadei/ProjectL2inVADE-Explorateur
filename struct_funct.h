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

#endif // STRUCT_FUNCT_H_INCLUDED
