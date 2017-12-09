#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "tools.h"
#include "save.h"
#include "struct_funct.h"

tree creat_tree_save(tree a, char **info, int pos_x) //On initilialise un arbre avec les valeurs du txt
{
    if (a == NULL)
    {
        return a;
    }

    int i;
    int pos_y=0;
    int size_element;
    a->next=NULL;
    a->child=NULL;
    a->father=NULL;
    while(info[pos_x][pos_y] != '*')
    {
        pos_y = pos_y + 1;
    }

    pos_y++;
    size_element = 0;

    for(i=pos_y; info[pos_x][i] != '*'; i++)
    {
        size_element++;
    }
    a->word = malloc_tad1D(size_element+1);

    for(i=0; info[pos_x][i+pos_y] != '*'; i++)
    {
        a->word[i] = info[pos_x][i+pos_y];
    }
    a->word[i] = '\0';
    pos_y = pos_y + i + 1;

    a->type = atoi(&info[pos_x][pos_y]);

    if (a->type == 1)
    {
        pos_y = pos_y + 2;

        char *tag=NULL;
        int tag_init = 0; //Pour savoir si les tags on déjà était initialisé
        while(info[pos_x][pos_y] != '\n')
        {
            size_element = 0;
            i=0;

            while(info[pos_x][i+pos_y] != '-' && info[pos_x][i+pos_y] != '*')
            {
                size_element++;
                i++;
            }

            tag = malloc_tad1D(size_element+1);

            i=0;
            while(info[pos_x][i+pos_y] != '-' && info[pos_x][i+pos_y] != '*')
            {
                tag[i] = info[pos_x][i+pos_y];
                i++;
            }
            tag[i] = '\0';

            if (tag_init == 0)
            {
                a->nexttag=init_new_tag(tag);
                tag_init = 1;
                //printf("\n%s %s\n",a->nexttag->word);
            }
            else
            {

                add_tag(a->nexttag, tag);
                //printf("\n%s\n",a->nexttag->word);
            }

            pos_y = pos_y + i + 1;

            free(tag);
        }
    }
    return a;
}



void generate_tree_save(tree a, char **info, int info_x, int info_y, int **id, int id_x, int id_y, int pos_x, int pos_y)
{
    int i;
    for (i=0; i<info_x; i++)
    {

        if (id[pos_x+1][pos_y] != 0) ///Il faut ajouter un fils tant que c'est possible
        {

            a->child = malloc(sizeof(node));
            a->child = creat_tree_save(a->child, info,pos_x+1);
            a->child->father = a;
            a->child->next = NULL;
            pos_x = pos_x + 1;
            pos_y = pos_y + 1;
            a = a->child;
            //printf("%d) -> child -> %s\n", i,a->word);


        }
        else if (id[pos_x+1][pos_y-1] != 0)/// On ajoute le frère
        {

            //printf("\nFrere 1 = %s\n", a->word);
            if (a->next == NULL)
            {
                a->next = malloc(sizeof(node));
                a->next = creat_tree_save(a->next, info, pos_x+1);
                a->next->father = a->father;
                pos_x = pos_x + 1;

            }
            else
            {
                tree b = a->next;

                tree c = malloc(sizeof(node));
                c = creat_tree_save(c,info,pos_x+1);
                c->father = a->father;
                a->next = c;
                c->next = b;
                pos_x = pos_x + 1;
            }
            a = a->next;
            //printf("%d) -> brother -> %s\n", i, a->word);
        }
        else
        {

            while (id[pos_x+1][pos_y-1] == 0)
            {
                pos_y = pos_y - 1;
                a = a->father;
                //printf("On retourne en arriere -> Pere -> %s\n", a->word);
            }
            i = i - 1;

        }

    }
}
tree init_tree_save()
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt","r");
    int **tab_id = NULL;
    char **tab_tree;
    tab_id = tabId();
    tab_tree = tabTree();
    tree a = NULL;

    if (fichier != NULL && tab_id != NULL && tab_tree != NULL)
    {
        int size_id_x, size_id_y, size_tree_x, size_tree_y;
        sizeId(&size_id_x, &size_id_y);
        sizeFile(&size_tree_x, &size_tree_y);

        if (tab_id[0][0] == 0)
        {
            a = malloc(sizeof(node));
            a=creat_tree_save(a, tab_tree,0); //Génération de la racine
            tree b = a;
            //printf("Taille fichier: %d\n", size_tree_x);
            generate_tree_save(a, tab_tree, size_tree_x, size_tree_y, tab_id, size_id_x, size_id_y, 0,0);
            a=b;

            //printf("\n\n\n\n\n");
            //print_tree_all(a);
            //a = a->child;
            //printf("%s", a->next->next->child->next->child->word);
            //printf("\n\nParent: %s\n", a->word);
            //printf(">: %s\n", a->child->word);
            //printf("> >: %s\n", a->child->child->word);
            //printf("> > >: %s\n", a->child->child->child->word);
            //printf("> > > - : %s\n", a->child->child->child->next->word);
            //printf("> > > - - : %s\n", a->child->child->child->next->next->word);

        }

    }
    else
    {
        printf("L'un des tableaux n'a pas été généré");
        exit(0);
    }


    return a;

}
