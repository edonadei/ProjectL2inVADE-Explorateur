#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "save.h"
#include "structure.h"
#include "tools.h"
#include "struct_funct.h"
#include "initialisation.h"
#include "view.h"

#define DEBUG 0


int main(int argc, char *argv[])
{


    //char arbo[47];
    int i=1,j=1,h=1;
    // INITIALISATION DE L'ARBRE
    tree a=init_tree_save();



    //printf("Nom du fichier: %s\n", a->child->child->child->child->next->next->word);
    //show_tags(a->child->child->child->child->next->next->nexttag);

    // INITIALISATION DE LA LISTE D'ECHEANCES
    calendlist c=init_new_calend("cours d'algèbre linéaire",0,0,1,"mathematiques","algebre lineaire", "cours");
    add_calend(c,"Cours de communication",1,1,1,"general","communication","cours");
    add_calend(c,"CE d'atome a la puce",3,2,3,"physique","atome a la puce", "ce");
    add_calend(c,"Cours d'algebre lineraire",1,6,1,"mathematiques","algebre lineaire","cours");
    add_calend(c,"Cours d'atome a la puce ",2,6,1,"physique","atome a la puce","cours");
    add_calend(c,"CE d'anglais",3,7,3,"general","anglais","ce");
    add_calend(c,"Cours d'information numerique",4,8,1,"physique","information numerique","cours");
    add_calend(c,"Cours d'anglais",4,9,1,"general","anglais","cours");
    add_calend(c,"Cours d'algèbre lineaire",4,11,1,"mathematiques","algebre lineaire","cours");
    add_calend(c,"DE d'information numerique",2,12,5,"informatique","information numerique","de");
    add_calend(c,"DE de communication",4,13,5,"general","communication","DE");

    // VERSION CONSOLE

     while(i>0)
    {
        //char* dateh,datej;
        printf("\nCreneau actuel: ");
        printf("%s ",number_to_days(j));
        printf("%s\n",number_to_hours(h));
        printf("\n-----------\n");
        printf("\nListe d'echeance par date:\n");
        list_echeance(c,h,j,4);
        printf("\n\n-----------\n");
        printf("\nListe d'echeance par score:\n");
        list_echeance_by_score_console(c,h,j,2);
        printf("\n\n-----------\n");
        printf("\nChoisissez un tag que vous souhaitez mettre en avant:\n\n_Physique\n_Informatique\n_Mathematiques\n_General\n");
        printf("\n-----------\n");
        char tag1[80],tag2[80];
        printf("\nPremier tag: ");
        scanf("%s",tag1);
        printf("\nDeuxieme tag: ");
        scanf("%s",tag2);
        printf("\nNouvelle liste d'echeance par score:\n");
        calendlist d;

        d=filtre_liste_echeance(c,tag1,tag2);
        list_echeance_by_score_console(d,h,j,2);
        printf("\n\n-----------\n");

        listnode b=init_new_lscnode(a);
        recherche_fichier_selon_tags_v2(a,b,tag1,tag2,tag2);

        printf("\nSouhaitez vous continuer ou passer a la version SDL(Console/1 SDL/0): ");
        scanf("%d",&i);
    }

    // VERSION SDL

    view(a,c);

system("pause");


    //show_listnode(b);
    //show_tags(b->next->arbre->nexttag);



    //printf("%s",list_of_strings->next->stringtosend);

     //Test de la récupération de fichiers
//tree b=init_new_tree("racine",0,NULL);
  //recherche_fichier_selon_tags(a,b,"physique","champs electromagnetiques","ce");
    //print_tree_all(b);

    // Test de de l'affichage d'enfant d'un dossier
    browse_expl(a->child->child);


    //arbo=arborescence_string(b->child->child);
    //printf("%s",arborescence_string(b->child));
    //sprintf(arbo,"\n%s",arborescence_string(b->child->child));
    //printf("%s",arbo);

    //show_tags(b->next->arbre->nexttag);
    return 0;
}
