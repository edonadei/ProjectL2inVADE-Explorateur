#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

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

typedef struct calend // Liste d'échéances
{
    struct nodetag *nexttag;
    struct calend *next;
    char *word;
    int hour,day,emergency; // Coefficient "d'urgence"
}calend;

typedef calend *calendlist;
typedef nodeId *Idlist;
typedef nodetag *taglist;
typedef node *tree;



#endif // STRUCTURE_H_INCLUDED
