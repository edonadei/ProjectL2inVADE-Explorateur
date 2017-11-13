#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "save.h"
#include "structure.h"
#include "tools.h"
#include "struct_funct.h"

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
    b->nextId->next->id = 6;
    b->nextId->next->next = malloc(sizeof(nodeId));
    b->nextId->next->next->id = 3;
    b->nextId->next->next->next = NULL;
    b->nexttag=init_new_tag("Chef de projet");
    add_tag(b->nexttag,"Gars sympa");
    add_tag(b->nexttag,"Homme stock");

    sortFolderTree(b);

    // Test de de l'affichage d'enfant d'un dossier
    browse_expl(a->child);

    return 0;
}
