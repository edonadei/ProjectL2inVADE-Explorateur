#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char *word;
    int depth, type;  // 0 for folder, 1 for file

    struct node *child;   // point to children of this node
    struct node *next;    // point to next node at same level
}node;

typedef node *tree;

tree init_new_tree(char* name_of_tree)
{
    tree new_tree = malloc(sizeof(node));

    if (new_tree)
    {
    new_tree->next=NULL;
    new_tree->child=NULL;
    new_tree->word=name_of_tree;
    }

    return new_tree;
}

tree add_next(tree n,char* node_name)
{
   if (n==NULL)
    return NULL;

   while (n->next)
    n=n->next;

   return (n->next = init_new_tree(node_name));
}

tree add_child(tree n,char* node_name)
{
   if (n==NULL)
    return NULL;

    if (n->child)
    return add_next(n->child,node_name);

    else
    return (n->child = init_new_tree(node_name));
}

void _print_n_char(char c, int n) {while (n--) putchar(c); }

void print_array(char *t) {
   if (*t == '\0')
      return;
   printf("%c", *t);
   print_array(++t);
}

void print_tree(tree a, int p) { // p = profondeur de l'arbre
	_print_n_char('-', 2 * p);
	if (a)
    {
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

    tree a = init_new_tree("root");
    add_child(a,"enfant");
    add_child(a->child,"enfant2");
    add_next(a->child,"next2");
    add_child(a->child->child,"enfant3");
    add_next(a,"next");
    print_tree(a,0);
    return 0;
}
