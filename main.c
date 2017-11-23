#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "save.h"
#include "structure.h"
#include "tools.h"
#include "struct_funct.h"

#define DEBUG 0


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
    a->child->nexttag = init_new_tag("physique");
    add_tag(a->child->nexttag,"atome a la puce");
    add_tag(a->child->nexttag,"ce");
    show_tags(a->child->nexttag);

    calendlist c=init_new_calend("CE d'atome a la puce",3,2,3);
    add_calend(c,"DE d'information numerique",2,8,5);
    add_calend(c,"Cours d'algebre lineraire",1,6,1);
    add_calend(c,"Cours de communication",2,5,1);
    add_calend(c,"CE d'anglais",3,7,3);
    add_calend(c,"Cours d'anglais",4,6,1);
    list_echeance(c,0,1,4);

    // Test ID pour sauvegarde dans fichier txt

    // Test de de l'affichage d'enfant d'un dossier
    browse_expl(a->child);

    return 0;
}
