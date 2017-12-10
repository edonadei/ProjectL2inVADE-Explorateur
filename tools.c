#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "struct_funct.h"
#define SIZE 47

void print_tree_all(tree a)
{
    if(a == NULL)
    {
        return;
    }
    printf("%s\n", a->word);
    print_tree_all(a->child);
    print_tree_all(a->next);
}

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

char* arborescence_string(tree a)
{
    char* str;
    strcpy(str, "");
    int i=0;
    while(a->father)
    {
        a=a->father;
        i++;
    }

    while (i!=-1)
    {

        //strcat(str,(">%s",a->word));
        strcat(str,">");
        strcat(str,a->word);
        a=a->child;
        i--;
    }

return str;
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
    //printf("\nJe vais copier %s %s %s\n",a->nexttag->word,a->nexttag->next->word,a->nexttag->next->next->word);
    calendlist b = init_new_calend(a->word,a->hour,a->day,a->emergency,a->nexttag->word,a->nexttag->next->word,a->nexttag->next->next->word);

    if (a->next) a=a->next;

    while (a)
    {
        add_calend(b,a->word,a->hour,a->day,a->emergency,a->nexttag->word,a->nexttag->next->word,a->nexttag->next->next->word);
        a=a->next;
    }
    return b;
}

char* number_to_hours(int i)
{
int creneau = i%5;
char* string;
switch(creneau)
{
    case 0:
        string="08H-10H";
        break;
    case 1:
        string="10H-12H";
        break;
    case 2:
        string="12H-14H";
        break;
    case 3:
        string="14H-16H";
        break;
    case 4:
        string="16H-18H";
        break;
    case 5:
        string="18H-20H";
        break;
}

return string;
}

char* number_to_days(int i)
{
//int jour = i%30;
int creneau = i%4;
char* string;
switch(creneau)
{
    case 0:
        string="Lundi";
        break;
    case 1:
        string="Mardi";
        break;
    case 2:
        string="Mercredi";
        break;
    case 3:
        string="Jeudi";
        break;
    case 4:
        string="Vendredi";
        break;
}

return string;
}

char *print_tag_echeance(tree a)
{
    int i,pos=0;
    int tag_entier=0; //Check si tag a été affiché en entier

    char* info = "Details: ";
    char* string_tag = malloc((SIZE+2)*sizeof(char));

    for (i=0; info[i] != '\0'; i++)
    {
        string_tag[i] = info[i];
    }
    pos = pos + i;
    //printf("%s", a->nexttag->next->word);
    taglist l = a->nexttag;
    for(i=pos; i<SIZE; i++)
    {
        if (a->nexttag->word[i-pos] == '\0')
        {
            if (a->nexttag->next != NULL)
            {
                a->nexttag = a->nexttag->next;
                string_tag[i] = ',';
                pos = i+1;
            }
            tag_entier= 0;
        }
        else
        {
            tag_entier = 1;
            string_tag[i] = a->nexttag->word[i-pos];
        }
    }
    if (tag_entier == 1)
    {
        string_tag[SIZE]='.';
        string_tag[SIZE-1]='.';
        string_tag[SIZE-2]='.';
    }
    a->nexttag = l;

    string_tag[SIZE+1] = '\0';

    return string_tag;
}

/*
void menu(int h, int j, tree a, calendlist c)
{
    char* string;
    int i=1;
    calendlist d;
    while(i)
    {
        //char* dateh,datej;
        printf("\nCreneau actuel: ");
        printf("%s ",number_to_days(j));
        printf("%s\n",number_to_hours(h));

        printf("\nListe d'echeance par date:\n");
        list_echeance(c,h,j,4);
        printf("\n-----------\n");
        printf("\nListe d'echeance par score:\n");
        list_echeance_by_score(c,h,j,2);
        printf("\n-----------\n");
        printf("\nChoisissez un tag que vous souhaitez mettre en avant: ");
        scanf("%s",string);

        d=filtre_liste_echeance(c,"general");
        list_echeance_by_score(d,h,j,2);

        printf("Souhaitez vous continuer(y/1 n/0): ");
        scanf("%d",&i);
    }

}
*/
