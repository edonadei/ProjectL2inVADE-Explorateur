#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "save.h"
#include "structure.h"
#include "tools.h"
#include "struct_funct.h"
#include "initialisation.h"

#define DEBUG 0


int main()
{
    // Test initialisation arbre
    tree a=init_tree_save();

    print_tree_all(a);

    // Test de l 'affichage de tags

    show_tags(a->child->nexttag);

    calendlist c=init_new_calend("CE d'atome a la puce",3,2,3,"physique","atome a la puce", "ce");
    add_calend(c,"DE d'information numerique",2,8,5,"informatique","information numerique","de");
    add_calend(c,"Cours d'algebre lineraire",1,6,1,"mathematiques","algebre lineaire","cours");
    add_calend(c,"Cours de communication",2,5,1,"general","communication","cours");
    add_calend(c,"CE d'anglais",3,7,3,"general","anglais","ce");
    add_calend(c,"Cours d'anglais",4,6,1,"general","anglais","cours");
    printf("\nListe d'echeance par date:\n");
    list_echeance(c,0,1,4);

    show_tags(c->next->nexttag);

    // test affichage par système de scoring
    printf("\nListe d'echeance par score:\n");
    list_echeance_by_score(c,4,3,4);

    // test filtrage de la liste d'echeance
    printf("\nListe d'echeance par score, avec tag favori -> general:\n");
    calendlist d;
    d=filtre_liste_echeance(c,"general");
    list_echeance_by_score(d,4,3,4);

    // Test de la récupération de fichiers

    tree b=init_new_tree("racine",0,NULL);
    recherche_fichier_selon_tags(a,b,"physique","atome a la puce","ce");


    // Test de de l'affichage d'enfant d'un dossier
    browse_expl(a->child->child);

    return 0;
}
