#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAG_X 10
#define TAG_Y 128

// STRUCTURES

// Structure de sauvegarde
typedef struct nodeId
{
    int id;
    struct nodeId *next;
} nodeId;

// Structure de liste de tags

typedef struct nodetag
{
    char *word;
    struct nodetag *next;

} nodetag;

// Structure de l'arbre
typedef struct node
{
    char *word;
    int depth, type;  // 0 for folder, 1 for file

    struct nodeId *nextId;
    struct nodetag *nexttag; // Point to the list of tags
    struct node *father; // point to father of the node
    struct node *child;   // point to children of this node
    struct node *next;    // point to next node at same level
} node;

typedef nodeId *Idlist;
typedef nodetag *taglist;
typedef node *tree;


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

        y = y + 1; //On va rajouter une colonne de 0
        x = x + 1; //On rajoute une ligne pour le nouvelle id


        char **tab = NULL;
        tab = malloc(x * sizeof(char*));
        for (i=0; i<x; i++)
        {
            tab[i] = malloc(y * sizeof(char));
        }

        for (i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
            {
                tab[i][j] = '0';
            }
        }

        char c;
        i=j=0;

        while((c = fgetc(fichier)) != EOF)
        {
            if (c == '\n')
            {
                tab[i][j] = '\n';
                i++;
                j=0;
            }
            else
            {
                tab[i][j] = c;
                j++;
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
        y = y + 1; //Pour rajouter une ligne de 0 sur le côté
        x = x + 1; //On rajoute une ligne pour le nouveau id

        int **tab = NULL;
        tab = malloc(x * sizeof(int*));
        for (i=0; i<x; i++)
        {
            tab[i] = malloc(y * sizeof(int));
        }

        for(i=0; i<x; i++)
        {
            for(j=0; j<y; j++)
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
                    tab[i][j+1] = 0;
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

        return tab;
    }
    else
    {
        exit(0);
    }

    fclose(fichier);

    return NULL;
}

int counterLSC(Idlist a)
{
    int size=0;
    Idlist b = a;

    while(a != NULL)
    {
        size++;
        a = a->next;
    }

    a = b;

    return size;
}


int* convertLSCtoTab(Idlist a, int size)
{
    int i;
    int *tab = NULL;

    tab = malloc(size*sizeof(int));


    Idlist b = a;

    if (tab == NULL)
    {
        exit(0);
    }


    for (i=0; a != NULL; i++)
    {
        tab[i] = a->id;
        a = a->next;
    }

    a = b;

    return tab;
}

int posIdTab(int *tab_new_tree, int **tab_id, int x_id, int size_new_tree)
{
    int i, j,stop=1;
    int pos = 0;
    i=j=0;

    /*
        Algo qui donne la position du nouvel id dans le fichier de sauvegarde.
        On va analyser chaque chiffre du nouvel id et le comparer à ceux déjà présent

    */

    while(stop == 1 || j == size_new_tree-1)
    {
        if (tab_new_tree[0] < tab_id[0][0])
        {
            pos = 0;
            stop = 0;
        }
        else if(tab_new_tree[i] < tab_id[j][i]) //Si le chiffre du nouvel id est inférieur on renvoie directement la posisition
        {
            pos = j+1;
            stop = 0;
        }
        else if (tab_new_tree[i] == tab_id[j][i]) //Si on trouve le même chiffre on avance d'une ligne et d'une colonne (analyse du fils)
        {
            i++;
            j++;
        }
        else if (tab_new_tree[i] > tab_id[j][i]) //Si le chiffre est supérieur on avance d'une ligne
        {
            j++;
        }
        if (tab_new_tree[i+1] == 0) //Si on se trouve à la fin de l'id
        {
            if (tab_new_tree[i] == tab_id[j][i]) //Que tous les chiffre était pareil
            {
                if (tab_id[j+1][i+1] == 0) //Et qu'il n'a pas d'enfant alors c'est le même id donc on return -1
                {
                    return -1;
                }
            }
        }

        if (i==size_new_tree-1)
        {
            if(tab_id[j][i] == 0)
            {

                pos = j;
                stop = 0;
            }
        }
        if (j == x_id-1)
        {
            pos = j+1;
            stop = 0;
        }

    }

    return pos;
}

int sizeTabChar1D(char *tab)
{
    int i=0;
    while(tab[i] != '\0')
    {
        i++;
    }
    return i;
}


void counterCharLSC(taglist a, int *c_size, int *t_size)
{
    taglist b = a;
    int i, c=0, t=0;
    while(a != NULL)
    {
        for (i=0; a->word[i] != '\0'; i++)
        {
            c++;
        }

        if (a->next != NULL)
        {
            t++;
        }
        a=a->next;
    }
    a = b;

    *c_size = c;
    *t_size = t;

}

int sizeInfoNewTree(tree a)
{
    //On va calculer le nombre de caractère qui sera inscrit dans le fichier

    int size=0,c,t;


    size = counterLSC(a->nextId)*2; //Id plus les points et l'étoile
    size = size + (sizeTabChar1D(a->word) + 3); //Nom du fichier plus le type plus les 2 étoiles
    counterCharLSC(a->nexttag, &c, &t);
    size = size + c + t + 1;//Les tags + tirets + 1 étoile
    return size;
}

char** addNewId(tree a, int pos, int *tab_id, int size_id, char **tab_tree, int x_tree, int y_tree)
{

    int i,j;

    int x_new_tree = x_tree + 1;
    int y_new_tree;

    int y_temp = sizeInfoNewTree(a)+1;

    if (y_temp>y_tree)
    {
        y_new_tree = y_temp;
    }
    else
    {
        y_new_tree = y_tree;
    }

    char **new_tree = NULL;
    new_tree = malloc(x_new_tree*sizeof(char*));

    for (i=0; i<x_new_tree; i++)
    {
        new_tree[i] = malloc(y_new_tree*sizeof(char));
    }

    for (i=0; i<x_new_tree; i++)
    {
        for(j=0; j<y_new_tree; j++)
        {
            new_tree[i][j] = '0';
        }
    }


    char temp[2];
    int add = 0,k;
    for (i=0; i<x_new_tree; i++)
    {
        if (i == pos)
        {
            k=0;
            //On rajoute la nouvel arbre
            for (j=0; j<size_id; j++)
            {
                //On rajoute l'id
                sprintf(temp, "%d", tab_id[j]);
                new_tree[i][k] = temp[0];
                k++;
                if(j<size_id-1)
                {
                    new_tree[i][k] = '.';
                    k++;
                }

            }
            //Le nom
            new_tree[i][k]='*';
            k++;
            for (j=0; a->word[j] != '\0'; j++)
            {
                new_tree[i][k] = a->word[j];
                k++;
            }
            new_tree[i][k] = '*';
            k++;
            //Le type
            sprintf(temp, "%d", a->type);
            new_tree[i][k] = temp[0];
            k++;
            new_tree[i][k] = '*';
            k++;
            //Les tags
            taglist b = a->nexttag ;

            while(a->nexttag != NULL)
            {
                for (j=0; a->nexttag->word[j] != '\0'; j++)
                {
                    new_tree[i][k] = a->nexttag->word[j];
                    k++;
                }
                if (a->nexttag->next != NULL)
                {
                    new_tree[i][k] = '-';
                    k++;
                }
                a->nexttag = a->nexttag->next;
            }

            new_tree[i][k] = '*';
            k++;
            new_tree[i][k] = '\n';

            add = 1;
            a->nexttag = b;

        }
        else if(add)
        {
            for (j=0; j<y_tree; j++)
            {
                new_tree[i][j] = tab_tree[i-1][j];
            }
        }
        else
        {
            for (j=0; j<y_tree; j++)
            {
                new_tree[i][j] = tab_tree[i][j];
            }
        }
    }


    return new_tree;

}

void insertTreeToFile(char **tab_tree, int size_x)
{

    FILE* fichier = NULL;
    fichier = fopen("arbre.txt", "w+");

    if (fichier!=NULL)
    {
        int i,j;

        for (i=0; i<size_x; i++)
        {

            for(j=0; tab_tree[i][j] != '\n'; j++)
            {
                fputc(tab_tree[i][j], fichier);
            }
            fputc(tab_tree[i][j], fichier);
        }

    }

    fclose(fichier);
}

void sortFolderTree(tree a)
{

    int size_new_tree = counterLSC(a->nextId);

    int *new_tree_id = convertLSCtoTab(a->nextId, size_new_tree);
    int x_tree, y_tree, x_id, y_id;
    sizeFile(&x_tree,&y_tree);
    sizeId(&x_id,&y_id);

    char **tab_tree = tabTree();
    int **tab_id = tabId();

    if (tab_tree != NULL && tab_id != NULL)
    {
        //On doit trouver la position du nouveau maillon
        int pos = posIdTab(new_tree_id, tab_id, x_id, size_new_tree);

        if (pos != -1) //Si l'id n'est pas déjà présent
        {
            char **new_tree = addNewId(a, pos, new_tree_id, size_new_tree, tab_tree, x_tree, y_tree);

            insertTreeToFile(new_tree, x_tree+1);

            freeTabChar(new_tree, x_tree+1);
        }




        free(new_tree_id);
        freeTabChar(tab_tree,x_tree+1);
    }

}


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

// FONCTIONS D'AFFICHAGE
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

// printf("%s>",a->word); // Pas besoin, debug

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

int main()
{
    // Test de la création d'un arbre
    tree a = init_new_tree("root",0,NULL);
    add_child(a,"physique",0);
    add_child(a,"information numerique",0);
    add_child(a,"mathematiques",0);
    add_child(a->child,"CE",0);
    add_child(a->child->child,"CE n1",1);
    add_child(a->child,"DE",0);
    add_child(a->child,"Cours",0);
    add_child(a->child->next,"CE",0);
    add_child(a->child->next->child,"CE n1",1);
    add_child(a->child->next,"DE",0);
    add_child(a->child->next,"Cours",0);
    add_child(a->child->next->next,"CE",0);
    add_child(a->child->next->next->child,"CE n1",1);
    add_child(a->child->next->next,"DE",0);
    add_child(a->child->next->next,"Cours",0);

    print_tree(a,0);

    printf("\nPere de l'element %s = %s \n",a->child->child->word,a->child->child->father->word);

    // Test de l 'affichage de tags
    a->nexttag = init_new_tag("physique");
    add_tag(a->child->nexttag,"atome a la puce");
    add_tag(a->child->nexttag,"ce");
    show_tags(a->nexttag);

    tree b=init_new_tree("Emrick",0,NULL);

    b->nextId = malloc(sizeof(nodeId));
    b->nextId->id = 2;
    b->nextId->next = malloc(sizeof(nodeId));
    b->nextId->next->id = 1;
    b->nextId->next->next = malloc(sizeof(nodeId));
    b->nextId->next->next->id = 2;
    b->nextId->next->next->next = NULL;
    b->nexttag=init_new_tag("Chef de projet");
    add_tag(b->nexttag,"Gars sympa");
    add_tag(b->nexttag,"Homme stock");

    sortFolderTree(b);

    // Test de de l'affichage d'enfant d'un dossier
    browse_expl(a->child);

    return 0;
}
