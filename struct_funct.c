#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

// FONCTION DE GESTION DE L'ARBRE

tree init_new_tree(char* name_of_tree, int typechoice,tree father)
{
    tree new_tree = malloc(sizeof(node));

    if (new_tree)
    {
        new_tree->next=NULL;
        new_tree->child=NULL;
        new_tree->father=father;
        new_tree->type=typechoice; // Donne l'information que c'est un fichier (tant qu'il n'a pas de childs)
        new_tree->word=name_of_tree;
        new_tree->nexttag=NULL; // A l'initialisation, pas de tags
        new_tree->nextId=NULL;
    }

    return new_tree;
}

tree add_next(tree n,char* node_name,int typechoice)
{
    if (n==NULL)
        return NULL;

    while (n->next)
        n=n->next;

    return (n->next = init_new_tree(node_name,typechoice,n)); // On envoie en paramètre l'adresse du père
}

tree add_child(tree n,char* node_name,int typechoice)
{
    n->type=0; /// Ici on donne l'information qu'il s'agit d'un dossier

    if (n==NULL)
        return NULL;

    if (n->child)
        return add_next(n->child,node_name,typechoice);

    else
        return (n->child = init_new_tree(node_name,typechoice,n)); // On envoie en paramètre l'adresse du père
}

// FONCTIONS DE GESTION DES TAGS

taglist init_new_tag(char* name_of_tag)
{
    taglist new_tag = malloc(sizeof(nodetag));

    new_tag->word=name_of_tag;

    new_tag->next=NULL;

    return new_tag;
}

taglist add_tag(taglist t,char* name_of_tag)
{
    if (t==NULL)
        return NULL;

    while (t->next)
        t=t->next;

    return (t->next = init_new_tag(name_of_tag));
}
