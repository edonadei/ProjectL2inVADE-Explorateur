#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define TAG_X 3
#define TAG_Y 256
#define DEBUG 1


/*typedef struct folder
{
    int info;
    struct folder *next;
}folder;

typedef folder *listFolder;

typedef struct file
{
    char name[MAX];
    char tag[TAG_X][TAG_Y];
    struct file *next;
}file;

typedef file *listFile;

typedef struct node
{
    char name[MAX];
    char tag[TAG_X][TAG_Y];
    listFolder *son;
    listFile *next;


}node;

typedef node *tree;*/

/*
typedef struct file
{
    char name[MAX];
    char tag[TAG_X][TAG_Y];
    struct file *next;
}file;

typedef file *listFile;



tree createTree(tree t)
{
    t=malloc(sizeof(node));
    printf("Nom de l'arbre: ");
    scanf("%s", t->name);
    int i;
    for (i=0;i<TAG_X;i++)
    {
        printf("Choisir TAG %d (en minuscule): ",i+1);
        scanf("%s", t->tag[i]);
    }
    t->son=NULL;
    t->next=NULL;

    return t;
}

void printTree(tree t)
{
    if(t==NULL)
    {
        return;
    }
    printf("%s\n", t->name);
    printTree(t->son);

}

void createNode(tree *t)
{
    tree a = (*t);

    while(a->son != NULL)
    {
        a=a->son;
        printf("caca");
    }
    a=malloc(sizeof(node));
    printf("Nom de l'arbre: ");
    scanf("%s", a->name);

}

Tree crneateTree(Tree t)
{
    t = malloc(sizeof(Node));
    printf("Nom: ");
    scanf("%s", t->name);

    t->childs=NULL;

    return t;
}


void createFolder(Tree *t) //On rajoute un dossier dans l'arbre t
{
    Tree cour;
    Tree succ;
    Liste child;

    cour = (*t);

    child=cour->childs;

    while(child!=NULL)
    {
        child=child->next;
    }

    //On crée le nouvel arbre
    child=malloc(sizeof(Maillon));
    succ=malloc(sizeof(Node));
    printf("Nom: ");
    scanf("%s", succ->name);
    succ->childs=NULL;

    //On met l'arbre dans la liste chainée
    child->info=succ;

}*/

typedef struct Maillon{

    struct Maillon *next;
    void *info;
}Maillon;
typedef Maillon *Liste;


typedef struct Node
{
    char name[MAX];
    char tag[TAG_X][TAG_Y];
    int type;
    Maillon *childs;

}Node;
typedef Node *Tree;


int treeEmpty(Tree t)
{
    if (t==NULL) return 0; //Vide
    else return 1; //Pas vide

}

void stringDup(Tree *t, char *title)
{
    int i;
    Tree a = (*t);

    for(i=0; title[i] != '\0'; i++)
    {
        a->name[i] = title[i];
    }
    a->name[i] = title[i];
}

Tree createTree(char *title, int info)
{
    Tree t;

    t=malloc(sizeof(Node));

    stringDup(&t,title);

    t->type=info;

    return t;
}

void AddTree(Tree *a, Tree b)
{
    Liste child;

    child = (*a)->childs;

    while(child != NULL)
    {
        printf("teste");
        child = child->next;
    }

    child = malloc(sizeof(Maillon));
    child->info = b;
}

void printTree(Tree t)
{
    Liste child;
    if (t==NULL) return;

    printf("%s", t->name);

    child = t->childs;

    while(child!=NULL)
    {
        child->info=t;
        printTree(child->info);
        child=child->next;
    }

}

int main(int argc, char *argv[])
{


    Tree a = NULL;
    Tree b = NULL;
    Tree c = NULL;
    char title[MAX];
    printf("Nom arbre a: ");
    scanf("%s", title);
    a=createTree(title,0);
    printf("Nom arbre b: ");
    scanf("%s", title);
    b=createTree(title,0);
    printf("Nom arbre c: ");
    scanf("%s", title);
    c=createTree(title,0);


    AddTree(&a, b);
    AddTree(&a, c);

    printTree(a);


    /*
    t=createTree(t);
    createFolder(&t);
    createFolder(&t);
    printTree(t);


    createFolder(&t);
    createFolder(&t);
    t=t->son;
    createFolder(&t);
    createFolder(&t);
    */
    //printTree(a);




    return 0;
}
