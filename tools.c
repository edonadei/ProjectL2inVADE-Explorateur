#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "struct_funct.h"

void freeTabInt(int **tab,int x_tab)///On libère la mémoire d'un tableau 2D
{
    int i;

    for (i=0; i<x_tab; i++) ///On libère toutes les lignes
    {
        free(tab[i]);

    }
    free(tab);///On libère le tableau
}

void freeTabChar(char **tab,int x_tab)///On libère la mémoire d'un tableau 2D
{
    int i;

    for (i=0; i<x_tab; i++) ///On libère toutes les lignes
    {
        free(tab[i]);
    }
    free(tab);///On libère le tableau
}

char* malloc_tad1D(int size)
{
    char *tab=NULL;

    tab = malloc(size * sizeof(char));

    if (tab == NULL)
    {
        exit(0);
    }

    return tab;
}

void dossier_ou_fichier(tree a)
{
    if (a->type==0) printf("Dossier ");
    if (a->type==1) printf("Ficher ");
}

void show_folder_childs(tree a)
{
    if (a->child)
    {
        dossier_ou_fichier(a->child);
        printf("  _%s\n",a->child->word);

        while(a->child->next)
        {
            dossier_ou_fichier(a->child->next);
            printf("  _%s\n", a->child->next->word);
            a->child=a->child->next;
        }
    }
    else
    {
        printf("  _NULL");
    }
}

void arborescence(tree a)
{
    int i=0;
    while(a->father)
    {
        a=a->father;
        i++;
    }

    while (i!=-1)
    {
        printf(">%s",a->word);
        a=a->child;
        i--;
    }

}

void browse_expl(tree a)
{
    // int choice;
    //while (choice!= 0)
    //{
    printf("\n");
    arborescence(a);
    printf("\n");
    show_folder_childs(a);

    //}
}

void show_tags(taglist t)
{
    printf("\nListe de tags pour cet item: ");
    if(t == NULL) return;
    while (t->next)
    {
        printf("%s, ",t->word);
        t=t->next;
    }
    printf("%s",t->word); //le dernier de la liste !
    printf("\n");
}

void _print_n_char(char c, int n)
{
    while (n--) putchar(c);
}

void print_array(char *t)
{
    if (*t == '\0')
        return;
    printf("%c", *t);
    print_array(++t);
}

void print_tree(tree a, int p)   // p = profondeur de l'arbre
{
    _print_n_char('-', 2 * p);
    if (a)
    {
        if (a->type==1) printf("fichier ");
        if (a->type==0) printf("dossier ");
        print_array(a->word);
        printf("\n");
        if (a->child || a->next)
        {
            print_tree(a->next, p);
            print_tree(a->child, p + 1);
            // On incrémente la profondeur lorsque l'on rajoute à la pile d'appel
        }
    }
}

calendlist copy_lsc_calend(calendlist a)
{

calendlist b = init_new_calend(a->word,a->hour,a->day,a->emergency);

if (a->next) a=a->next;

while (a)
{
add_calend(b,a->word,a->hour,a->day,a->emergency);
a=a->next;
}
return b;
}
