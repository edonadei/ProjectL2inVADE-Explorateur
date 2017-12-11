#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "save.h"
#include "tools.h"
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

// FONCTION DE GESTION DE L'ARBRE

liststring init_new_lscstring(char* string_to_send)
{
    liststring new_list_of_string = malloc(sizeof(lscstring));

    if (new_list_of_string)
    {
        new_list_of_string->next=NULL;
        new_list_of_string->stringtosend=string_to_send;
    }

    return new_list_of_string;
}

liststring add_liststring(liststring l, char* string_to_send)
{
    if (l==NULL)
        return NULL;

    while(l->next)
        l=l->next;

    return (l->next = init_new_lscstring(string_to_send));
}

listnode init_new_lscnode(tree a)
{
    listnode new_list_of_nodes = malloc(sizeof(lscnode));

    if (new_list_of_nodes)
    {
        new_list_of_nodes->next=NULL;
        new_list_of_nodes->arbre=a;
    }

    return new_list_of_nodes;
}

listnode add_listnodes(listnode l, tree a)
{
    if (l==NULL)
        return NULL;

    while(l->next)
        l=l->next;

    return (l->next = init_new_lscnode(a));
}

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

// Fonctions de gestion des tags



calendlist init_new_calend(char *name_of_calend,int heure,int jour, int importance, char* tag1, char* tag2, char* tag3)
{
    // printf("\ndebug\n");
    calendlist new_calend = malloc(sizeof(calend));
    new_calend->word=name_of_calend;
    new_calend->nexttag=init_new_tag(tag1);
    //add_tag(new_calend->nexttag,tag1);
    add_tag(new_calend->nexttag,tag2);
    add_tag(new_calend->nexttag,tag3);
    new_calend->next=NULL;
    new_calend->day=jour;
    new_calend->hour=heure;
    new_calend->emergency=importance;

    return new_calend;
}


calendlist add_calend(calendlist t,char* name_of_calend, int heure,int jour, int importance,char* tag1, char* tag2, char* tag3)
{
    if (t==NULL)
        return NULL;



    while (t->next)
    {
        t=t->next;
    }

    return (t->next = init_new_calend(name_of_calend,heure,jour,importance,tag1,tag2,tag3));
}

int compare_temps(int j1, int j2, int h1, int h2)
{
    if (j1>j2) return 1;
    if (j1==j2 && h1>h2) return 1;
    return 0;
}

int calcul_score(int h, int j, calendlist temp) // Calcul du "score" d'une échéance urgente
{
    //printf("\n Détail du calcul du score: \n");
    if (j > temp->day) return 0; // Sécurité
    if (j == temp-> day && h > temp->hour) return 0; // Sécurité contre des maillons plus vieux que celui étudié

    int score,ecart_jours,ecart_heures,importance_critique;
    ecart_jours=temp->day-j+1;
    ecart_heures=temp->hour-h+1;
    importance_critique=(50*temp->emergency);
    // importance* 50, Nombre de jours divise le score, nombre d'heures retire un pourcentage
    //printf("\n importance_critique %d, ecart jours %d, ecart heures %d",importance_critique,ecart_jours,ecart_heures);

    score=(((importance_critique)/ecart_jours)-(ecart_heures/importance_critique));
    //printf("\n score: %d importance_critique %d, ecart jours %d, ecart heures %d",score,importance_critique,ecart_jours,ecart_heures);
    return score;
}

void list_echeance(calendlist c, int h, int j,int nbr_iteration) // Fonction d'affichage des 10 premières échéances, à récupérer pour le calcul du score
{
if(nbr_iteration>0) // conditions d'arrêt
    {
        calendlist temp=c; // Var temporaire car on ne veut pas toucher à la struct de base

        int jtemp=0, htemp=0;
        char* stringtemp;

        while ((jtemp==0 || htemp==0)&&(temp)) // Ici on s'assure que jtemp et htemp prennent bien les valeurs de la première date plus grande que nos j et h en argument
            {
                if (compare_temps(temp->day, j, temp->hour, h))
                        {
                            //printf("\nOn a trouve une valeur plus grande, je la range dans les temps !\n");
                            jtemp=temp->day;
                            htemp=temp->hour;
                            stringtemp=temp->word;
                        }
                //printf("h %d et temp->hour %d,j %d et temp->day %d\n",h,temp->hour,j,temp->day);
                //printf("premiere boucle %d,%d,%s\n",temp->day,temp->hour,temp->word);
                //printf("contenu des variables temporaires: htemp %d jtemp %d\n",htemp, jtemp);
                temp=temp->next;
                //printf("iteration suivante \n\n");
            }

        // Ici on récupère la plus petite date qui reste supérieur à h et j au dessus

        //printf("contenu des variables temporaires: htemp %d jtemp %d\n",htemp, jtemp);

        while (temp)
        {
            int echeance_inf=0;
            if (temp->day < jtemp && temp->day >= j && temp->hour>h) echeance_inf=1;
            if (temp->day < jtemp && temp->day > j)
            {
            echeance_inf=1;
            //printf("OK !");
            }

            if(echeance_inf)
            {
                jtemp=temp->day;
                htemp=temp->hour;
                stringtemp=temp->word;
                // printf("\ndeuxieme boucle OK ! "); // debug
            }
            //printf("\niteration debug echeance inf=%d\n",echeance_inf);
            //printf ("\ntemp->day %d,temp->hour %d,temp->word %s htemp %d, jtemp %d, h %d, j %d\n",temp->day,temp->hour,temp->word,htemp,jtemp,h,j);
            temp=temp->next;
        }

        //printf("\n- %s - Jour: %d - Heure: %d",stringtemp,jtemp,htemp);
        printf("\n- %s - %s %s",stringtemp,number_to_days(jtemp),number_to_hours(htemp));
        list_echeance(c,htemp,jtemp,nbr_iteration-1); // On rappelle la fonction et on recommence ! Condition d'arrêt avec les itérations
    }
}

void _list_echeance_by_score(calendlist c, int h, int j,int nbr_iteration,liststring list_of_strings) // Fonction d'affichage des 10 premières échéances, à récupérer pour le calcul du score
{
//if (nbr_iteration==0) return;
//printf("\niteration = %d\n",nbr_iteration);
if(nbr_iteration>0) // conditions d'arrêt
    {

        calendlist temp=c; // Var temporaire car on ne veut pas toucher à la struct de base
        //calendlist prec=c; // Deuxième var temporaire pour garder marqueur sur le maillon précédent

        //printf("\ntemp->next d: %d h: %d\n", temp->next->day, temp->next->hour);

        int jtemp=0, htemp=0, scoretemp=0, i=0;
        char* stringtemp;
        scoretemp=calcul_score(h,j,temp); // On stocke la valeur de la première variable potable
        //printf("\ntemp->next d: %d h: %d\n", temp->next->day, temp->next->hour);
        jtemp=temp->day;
        htemp=temp->hour;
        stringtemp=temp->word;
        calendlist prec = temp; // Besoin d'un marqueur temporaire de prec pour libération
        calendlist temp2,prec2; // Se souvenir de l'emplacement du maillon le plus grand
        temp=temp->next;

        while (temp) // Deuxième boucle, on étudie le reste de la liste
        {
            // printf("\nOn compare le score du maillon en temp: %d et le score du maillon etudie: %d\n",scoretemp,calcul_score(h,j,temp));
            if (calcul_score(h,j,temp)>scoretemp)
            {
                scoretemp=calcul_score(h,j,temp);
                jtemp=temp->day;
                htemp=temp->hour;
                stringtemp=temp->word;
                temp2=temp;
                prec2=prec;
                i++;
            }
            //printf("\nprec d: %d h: %d\n", prec->day, prec->hour);
            //printf("\ntemp d: %d h: %d\n", temp->day, temp->hour);

            prec=prec->next;
            temp=temp->next;
        }
        char string_temporaire[1000];
        sprintf(string_temporaire,"%s %s %d - %s",stringtemp,number_to_days(jtemp),jtemp+1,number_to_hours(htemp));
        add_liststring(list_of_strings,string_temporaire);
        // Libération si premier maillon
        if (i == 0)
        {
            //printf("\nmaillon du debut\n");
            _list_echeance_by_score(c->next,h,j,nbr_iteration-1,list_of_strings);
        }

        // Libération si dernier maillon de la liste
        if (temp2->next==NULL)
        {
            //printf("\nmaillon de fin\n");
            prec->next=NULL;
            _list_echeance_by_score(c,h,j,nbr_iteration-1,list_of_strings);
        }

        //printf("\nmaillon du milieu\n");
        prec2->next=temp2->next; // Libération du maillon étudié
        //printf("maillon que l'on veut liberer: d %d h %d, maintenant que c est fait, le next du prec = d %d h %d",temp2->day, temp2->hour,prec2->next->day, prec2->next->hour);
        free(temp2);
        // printf("\nmaillon du milieu\n");
        _list_echeance_by_score(c,h,j,nbr_iteration-1,list_of_strings); // On rappelle la fonction et on recommence ! Condition d'arrêt avec les itérations

        //printf("\nmaillon du milieu\n");
    }
}

void list_echeance_by_score(calendlist b, int h, int j,int nbr_iteration,liststring list_of_strings) // fonction chapeau
{
calendlist c=copy_lsc_calend(b); // On cherche à travailler sur une LSC que l'on peut charcuter le coeur libre
_list_echeance_by_score(c,h,j,nbr_iteration,list_of_strings);
}

void _list_echeance_by_score_console(calendlist c, int h, int j,int nbr_iteration) // Fonction d'affichage des 10 premières échéances, à récupérer pour le calcul du score
{
//if (nbr_iteration==0) return;
printf("\niteration = %d\n",nbr_iteration);
if(nbr_iteration>0) // conditions d'arrêt
    {
        calendlist temp=c; // Var temporaire car on ne veut pas toucher à la struct de base
        //calendlist prec=c; // Deuxième var temporaire pour garder marqueur sur le maillon précédent

        //printf("\ntemp->next d: %d h: %d\n", temp->next->day, temp->next->hour);

        int jtemp=0, htemp=0, scoretemp=0, i=0;
        char* stringtemp;
        scoretemp=calcul_score(h,j,temp); // On stocke la valeur de la première variable potable
        //printf("\ntemp->next d: %d h: %d\n", temp->next->day, temp->next->hour);
        jtemp=temp->day;
        htemp=temp->hour;
        stringtemp=temp->word;
        calendlist prec = temp; // Besoin d'un marqueur temporaire de prec pour libération
        calendlist temp2,prec2; // Se souvenir de l'emplacement du maillon le plus grand
        temp=temp->next;

        while (temp) // Deuxième boucle, on étudie le reste de la liste
        {
            // printf("\nOn compare le score du maillon en temp: %d et le score du maillon etudie: %d\n",scoretemp,calcul_score(h,j,temp));
            if (calcul_score(h,j,temp)>scoretemp)
            {
                scoretemp=calcul_score(h,j,temp);
                jtemp=temp->day;
                htemp=temp->hour;
                stringtemp=temp->word;
                temp2=temp;
                prec2=prec;
                i++;
            }
            //printf("\nprec d: %d h: %d\n", prec->day, prec->hour);
            //printf("\ntemp d: %d h: %d\n", temp->day, temp->hour);

            prec=prec->next;
            temp=temp->next;
        }

        printf("\n- %s - Jour: %d - Heure: %d - Score: %d",stringtemp,jtemp,htemp,scoretemp);

        // Libération si premier maillon
        if (i == 0)
        {
            //printf("\nmaillon du debut\n");
            _list_echeance_by_score_console(c->next,h,j,nbr_iteration-1);
        }

        // Libération si dernier maillon de la liste
        if (temp2->next==NULL)
        {
            //printf("\nmaillon de fin\n");
            prec->next=NULL;
            _list_echeance_by_score_console(c,h,j,nbr_iteration-1);
        }

        //printf("\nmaillon du milieu\n");
        prec2->next=temp2->next; // Libération du maillon étudié
        //printf("maillon que l'on veut liberer: d %d h %d, maintenant que c est fait, le next du prec = d %d h %d",temp2->day, temp2->hour,prec2->next->day, prec2->next->hour);
        free(temp2);
        // printf("\nmaillon du milieu\n");
        _list_echeance_by_score_console(c,h,j,nbr_iteration-1); // On rappelle la fonction et on recommence ! Condition d'arrêt avec les itérations

        //printf("\nmaillon du milieu\n");
    }
}

void list_echeance_by_score_console(calendlist b, int h, int j,int nbr_iteration) // fonction chapeau
{
calendlist c=copy_lsc_calend(b); // On cherche à travailler sur une LSC que l'on peut charcuter le coeur libre
_list_echeance_by_score_console(c,h,j,nbr_iteration);
}

int check_if_tag_exist(taglist a, char* tag1)
{
    //printf("test");
    if (a==NULL)
        return 0;

    //printf("\ntag actuel %s, tag a comparer %s\n",a->word,tag1);

    //printf("test %s",tag1);
    if (strcmp(a->word,tag1)==0)
    {
        //printf("\ntag trouve, on augmente le score\n");
        return 1;
    }

    return check_if_tag_exist(a->next,tag1);
}

void _filtre_liste_echeance (calendlist c,char* tag1,char* tag2) // Sert à filtrer une liste d'échéance en fonction de deux tags
{
    if (c==NULL)
        return;

    int x=check_if_tag_exist(c->nexttag,tag1);

    if (x == (1))
    {
        c->emergency=c->emergency*3;
    }

    x=0;

    x=check_if_tag_exist(c->nexttag,tag2);

    if (x == (1))
    {
        c->emergency=c->emergency*3;
    }

    _filtre_liste_echeance(c->next,tag1,tag2);
}

calendlist filtre_liste_echeance (calendlist a,char* tag1, char* tag2) // fonction chapeau
{
    calendlist c=copy_lsc_calend(a);
    _filtre_liste_echeance(c,tag1,tag2);
    return c;
}

void recherche_fichier_selon_tags (tree a,tree b,char* tag1, char* tag2, char* tag3) // Associe les fichiers selon la liste d'échéances
{
if (a==NULL)
    return;

recherche_fichier_selon_tags(a->child,b,tag1,tag2,tag3);
recherche_fichier_selon_tags(a->next,b,tag1,tag2,tag3);

if (a->nexttag == NULL);

else
{
    int i = check_if_tag_exist(a->nexttag,tag1);

    if (i)
    {
        if (check_if_tag_exist(a->nexttag,tag2) && check_if_tag_exist(a->nexttag,tag3)) // Documents du même type et de la même matiere
        {
            add_child(b,a->word,0);
            b->nexttag=a->nexttag;
        }

        else if (check_if_tag_exist(a->nexttag,tag2)) // Documents de la meme matiere
        {
            add_child(b,a->word,0);
            b->nexttag=a->nexttag;
        }
    }
}
return;
}

void recherche_fichier_selon_tags_v2 (tree a,listnode b,char* tag1, char* tag2, char* tag3) // Nouvelle version, ancienne non fonctionnelle et adaptée à la SDL
{
if (a==NULL)
    return;

//printf("\non descend: %s\n",a->word);
recherche_fichier_selon_tags_v2(a->child,b,tag1,tag2,tag3);
recherche_fichier_selon_tags_v2(a->next,b,tag1,tag2,tag3);

if (a->nexttag == NULL);

else
{
    int i = check_if_tag_exist(a->nexttag,tag1);

    if (i)
    {
        if (check_if_tag_exist(a->nexttag,tag2) && check_if_tag_exist(a->nexttag,tag3)) // Documents du même type et de la même matiere
        {

            add_listnodes(b,a);
            //printf("\n Fichier propose: %s\n",b->arbre->word);
            //printf("\n Tags du fichier %s \n",print_tag_echeance(b->arbre));
        }

        else if (check_if_tag_exist(a->nexttag,tag2)) // Documents de la meme matiere
        {
            add_listnodes(b,a);
            //printf("\n Fichier propose: %s\n",b->arbre->word);
            //printf("\n Tags du fichier %s \n",(print_tag_echeance(b->arbre)));
        }
    }
}
return;
}

void show_listnode(listnode l) // Affiche une liste de nodes
{
    if (l==NULL)
    {
        return;
    }
    printf("%s ->", l->arbre->word);
    show_listnode(l->next);
}

