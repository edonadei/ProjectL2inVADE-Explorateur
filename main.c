#include <stdio.h>
#include <stdlib.h>

#define MAX 256
#define TAG_X 3
#define TAG_Y 256



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
    struct node *son;
    listFile *next;


}node;

typedef node *tree;

int treeEmpty(tree t)
{
    if (t==NULL) return 0; //Vide
    else return 1; //Pas vide

}

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

int main()
{
    tree t=NULL;

    t=createTree(t);
    printf("%d\n", treeEmpty(t));
    printTree(t);
    createNode(&t);
    createNode(&t);
    printTree(t);



    return 0;
}
