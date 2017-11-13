#ifndef STRUCT_FUNCT_H_INCLUDED
#define STRUCT_FUNCT_H_INCLUDED

// FONCTION DE GESTION DE L'ARBRE

tree init_new_tree(char* name_of_tree, int typechoice,tree father);
tree add_next(tree n,char* node_name,int typechoice);
tree add_child(tree n,char* node_name,int typechoice);

// FONCTIONS DE GESTION DES TAGS

taglist init_new_tag(char* name_of_tag);
taglist add_tag(taglist t,char* name_of_tag);
#endif // STRUCT_FUNCT_H_INCLUDED
