#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAG_X 10
#define TAG_Y 128

typedef struct nodeId
{
    int id;
    struct nodeId *next;
} nodeId;
typedef struct nodetag
{
    char *word;
    struct nodetag *next;

} nodetag;

typedef struct node
{
    char *word;
    int depth, type;  // 0 for folder, 1 for file

    struct nodeId *nextId;
    struct nodetag *nexttag;
    struct node *child;   // point to children of this node
    struct node *next;    // point to next node at same level
} node;

typedef nodeId *Idlist;
typedef nodetag *taglist;
typedef node *tree;

void save_new_tree(tree t)
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "a");

    if (fichier!=NULL)
    {
        //Définir l'id

        fprintf(fichier,"*%s*%d*",t->word,t->type);

        while(t->nexttag!=NULL)
        {
            fprintf(fichier,"%s",t->nexttag->word);
            t->nexttag=t->nexttag->next;
            if(t->nexttag!=NULL)
            {
                fputc('-',fichier);
            }
        }
        fputs("*",fichier);

        fputs("\n",fichier);
    }
    fclose(fichier);
}

void sizeFile(int *size_x,int *size_y)
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "r");

    char c;
    int x=0, y=0, size_y_max = 0;

    if(fichier != NULL)
    {
        while((c=fgetc(fichier)) != EOF)
        {
            y++;
            if(c=='\n')
            {
                x++;
                if (size_y_max < y)
                {
                    size_y_max = y;
                }
                y = 0;
            }
        }
    }
    *size_x = x;
    *size_y = size_y_max;
    fclose(fichier);
}

void sizeId(int *size_x, int *size_y)
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "r");

    char c;
    int x=0, y=0, size_y_max = 0, stop=1;

    if(fichier != NULL)
    {
        while((c=fgetc(fichier)) != EOF)
        {
            if(c=='*')
            {
                stop = 0;
            }
            if (stop)
            {
                if(c=='.')
                {
                    y++;
                    if (size_y_max < y)
                    {
                        size_y_max = y;
                    }
                }
            }
            if(c=='\n')
            {
                x++;
                y = 0;
                stop = 1;
            }
        }
    }
    *size_x = x;
    *size_y = size_y_max;
    fclose(fichier);
}
char** tabTree()
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "r");

    if (fichier != NULL)
    {
        int x,y,i,j;
        sizeFile(&x,&y);

        char **tab = NULL;
        tab = malloc(x * sizeof(char*));
        for (i=0; i<x; i++)
        {
            tab[i] = malloc(y * sizeof(char));
        }

        char c;
        i=j=0;
        while((c = fgetc(fichier)) != EOF)
        {
            tab[i][j] = c;

            j++;
            if (c == '\n')
            {
                i++;
                j=0;
            }
        }

        fclose(fichier);

        return tab;
    }


    fclose(fichier);

    return NULL;
}

int** tabId()
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "r");

    if (fichier != NULL)
    {
        int x,y,i,j;
        sizeId(&x,&y);

        int **tab = NULL;
        tab = malloc(x * sizeof(int*));
        for (i=0; i<x; i++)
        {
            tab[i] = malloc(y * sizeof(int));
        }

        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                tab[i][j] = 0;
            }
        }
        char c;
        int number,stop = 1;
        i=j=0;

        while((c = fgetc(fichier)) != EOF)
        {

            if(c=='*')
            {
                stop = 0;
            }
            if (stop)
            {
                if (c != '.' && c != '\n')
                {

                    number = atoi(&c);
                    tab[i][j] = number;
                    j++;
                }
            }
            if(c=='\n')
            {
                stop = 1;
                j=0;
                i++;
            }
        }
        fclose(fichier);

        return tab;
    }

    fclose(fichier);

    return NULL;
}

void sortFolderTree()
{

}
tree init_new_tree(char* name_of_tree, int typechoice)
{
    tree new_tree = malloc(sizeof(node));

    if (new_tree)
    {
        new_tree->next=NULL;
        new_tree->child=NULL;
        new_tree->type=typechoice; // Donne l'information que c'est un fichier (tant qu'il n'a pas de childs)
        new_tree->word=name_of_tree;
        new_tree->nexttag=NULL; // A l'initialisation, pas de tags
    }

    return new_tree;
}

tree add_next(tree n,char* node_name,int typechoice)
{
    if (n==NULL)
        return NULL;

    while (n->next)
        n=n->next;

    return (n->next = init_new_tree(node_name,typechoice));
}

tree add_child(tree n,char* node_name,int typechoice)
{
    n->type=0; /// Ici on donne l'information qu'il s'agit d'un dossier

    if (n==NULL)
        return NULL;

    if (n->child)
        return add_next(n->child,node_name,typechoice);

    else
        return (n->child = init_new_tree(node_name,typechoice));
}

taglist init_new_tag(char* name_of_tag)
{
    taglist new_tag = malloc(sizeof(nodetag));

    if (new_tag)
    {
        new_tag->word=name_of_tag;
        // printf("%s , ", name_of_tag); // Utile en cas de debug
        new_tag->next=NULL;
    }

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


void show_tags(taglist t)
{
    printf("\nListe de tags pour cet item: ");
    while (t->next)
    {
        printf("%s, ",t->word);
        t=t->next;
    }
    printf("%s",t->word); //le dernier de la liste !
    printf("\n");
}

/* // VERSION TEST DE LA FONCTION ADD_TAGS, NON FONCTIONNEL
taglist add_tags(tree n, char* node_name, char* tag_name, int typechoice)
{
    if ((n->type)==(0))
    {
        printf("\n Opération impossible, c'est un dossier \n");
        exit(EXIT_FAILURE);
    }

    else if (n->nexttag==NULL) // Si le fichier n'a pas encore de tags, on initialise
    {
        taglist newtag=malloc(sizeof(nodetag)); // On alloue un nouveau tag et on l'ajoute à la suite des tags existants
        newtag->word=tag_name;
        newtag->next=NULL;
        // n->nexttag=newtag;
        return newtag;
    }
    else // Si le fichier a déja au moins un tag
    {
        while (n->nexttag)
    n=n->nexttag;
    }
}

*/

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

int main()
{
    // Test de la création d'un arbre
    tree a = init_new_tree("root",0);
    add_child(a,"enfant",0);
    add_child(a->child,"next",1);
    add_next(a->child,"CE d'atome a la puce",1);
    add_child(a->child->child,"enfant3",0);
    add_next(a,"next",0);
    print_tree(a,0);

    // Test de l 'affichage de tags
    a->child->nexttag = init_new_tag("physique");
    add_tag(a->child->nexttag,"atome a la puce");
    add_tag(a->child->nexttag,"ce");
    show_tags(a->child->nexttag);
    save_new_tree(a->child);
    tabId();

    return 0;
}
