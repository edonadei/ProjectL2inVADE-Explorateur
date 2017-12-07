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

tree creat_tree_save(tree a, char **info, int info_x, int info_y, int pos_x)
{
    int i;
    int pos_y=0;
    int size_element;

    a = malloc(sizeof(tree));
    a->next=NULL;
    a->child=NULL;
    while(info[pos_x][pos_y] != '*')
    {
        pos_y = pos_y + 1;
    }
    pos_y++;
    size_element = 0;

    for(i=pos_y; info[pos_x][i] != '*'; i++)
    {
        size_element++;
    }

    a->word = malloc_tad1D(size_element+1);
    for(i=0; info[pos_x][i+pos_y] != '*'; i++)
    {
        a->word[i] = info[pos_x][i+pos_y];
    }
    a->word[i] = '\0';

    pos_y = pos_y + i + 1;

    a->type = atoi(&info[pos_x][pos_y]);

    if (a->type == 0)
    {
        pos_y = pos_y + 2;

        char *tag=NULL;
        int tag_init = 0; //Pour savoir si les tags on d�j� �tait initialis�
        while(info[pos_x][pos_y] != '\n')
        {
            size_element = 0;
            i=0;

            while(info[pos_x][i+pos_y] != '-' && info[pos_x][i+pos_y] != '*')
            {
                size_element++;
                i++;
            }

            tag = malloc_tad1D(size_element+1);

            i=0;
            while(info[pos_x][i+pos_y] != '-' && info[pos_x][i+pos_y] != '*')
            {
                tag[i] = info[pos_x][i+pos_y];
                i++;
            }
            tag[i] = '\0';

            if (tag_init == 0)
            {
                a->nexttag=init_new_tag(tag);
                tag_init = 1;
            }
            else
            {
                add_tag(a->nexttag, tag);
            }

            pos_y = pos_y + i + 1;

            free(tag);
        }
    }
    return a;
}

tree init_tree_save()
{
    FILE* fichier = NULL;
    fichier = fopen("arbre.txt","r");
    int **tab_id = NULL;
    char **tab_tree;
    tab_id = tabId();
    tab_tree = tabTree();


    if (fichier != NULL && tab_id != NULL && tab_tree != NULL)
    {
        int size_id_x, size_id_y, size_tree_x, size_tree_y;
        sizeId(&size_id_x, &size_id_y);
        sizeFile(&size_tree_x, &size_tree_y);

        tree a = NULL;

        if (tab_id[0][0] == 0)
        {
            a=creat_tree_save(a,tab_tree,size_tree_x,size_tree_y,0);
            print_tree(a,0);
        }

    }
    else
    {
        printf("L'un des tableaux n'a pas �tait g�n�r�");
    }

    return NULL;
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

    return (n->next = init_new_tree(node_name,typechoice,n)); // On envoie en param�tre l'adresse du p�re
}

tree add_child(tree n,char* node_name,int typechoice)
{
    n->type=0; /// Ici on donne l'information qu'il s'agit d'un dossier

    if (n==NULL)
        return NULL;

    if (n->child)
        return add_next(n->child,node_name,typechoice);

    else
        return (n->child = init_new_tree(node_name,typechoice,n)); // On envoie en param�tre l'adresse du p�re
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

int calcul_score(int h, int j, calendlist temp) // Calcul du "score" d'une �ch�ance urgente
{
    //printf("\n D�tail du calcul du score: \n");
    if (j > temp->day) return 0; // S�curit�
    if (j == temp-> day && h > temp->hour) return 0; // S�curit� contre des maillons plus vieux que celui �tudi�

    int score,ecart_jours,ecart_heures,importance_critique;
    ecart_jours=temp->day-j;
    ecart_heures=temp->hour-h;
    importance_critique=(50*temp->emergency);
    // importance* 50, Nombre de jours divise le score, nombre d'heures retire un pourcentage
    score=(((importance_critique)/ecart_jours)-(ecart_heures/importance_critique));
    //printf("\n score: %d importance_critique %d, ecart jours %d, ecart heures %d",score,importance_critique,ecart_jours,ecart_heures);
    return score;
}

void list_echeance(calendlist c, int h, int j,int nbr_iteration) // Fonction d'affichage des 10 premi�res �ch�ances, � r�cup�rer pour le calcul du score
{
if(nbr_iteration>0) // conditions d'arr�t
    {
        calendlist temp=c; // Var temporaire car on ne veut pas toucher � la struct de base

        int jtemp=0, htemp=0;
        char* stringtemp;

        while ((jtemp==0 || htemp==0)&&(temp)) // Ici on s'assure que jtemp et htemp prennent bien les valeurs de la premi�re date plus grande que nos j et h en argument
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

        // Ici on r�cup�re la plus petite date qui reste sup�rieur � h et j au dessus

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

        printf("\nNom: %s - Jour: %d - Heure: %d\n",stringtemp,jtemp,htemp);
        list_echeance(c,htemp,jtemp,nbr_iteration-1); // On rappelle la fonction et on recommence ! Condition d'arr�t avec les it�rations
    }
}

void _list_echeance_by_score(calendlist c, int h, int j,int nbr_iteration) // Fonction d'affichage des 10 premi�res �ch�ances, � r�cup�rer pour le calcul du score
{
//if (nbr_iteration==0) return;
//printf("\niteration = %d\n",nbr_iteration);
if(nbr_iteration>=1) // conditions d'arr�t
    {
        calendlist temp=c; // Var temporaire car on ne veut pas toucher � la struct de base
        //calendlist prec=c; // Deuxi�me var temporaire pour garder marqueur sur le maillon pr�c�dent

        int jtemp=0, htemp=0, scoretemp=0, i=0;
        char* stringtemp;
        scoretemp=calcul_score(h,j,temp); // On stocke la valeur de la premi�re variable potable
        jtemp=temp->day;
        htemp=temp->hour;
        stringtemp=temp->word;
        calendlist prec = temp; // Besoin d'un marqueur temporaire de prec pour lib�ration
        calendlist temp2,prec2; // Se souvenir de l'emplacement du maillon le plus grand
        temp=temp->next;

        while (temp) // Deuxi�me boucle, on �tudie le reste de la liste
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
            //printf("\ntemp->next d: %d h: %d\n", temp->next->day, temp->next->hour);
            prec=prec->next;
            temp=temp->next;
        }

        printf("\nNom: %s - Jour: %d - Heure: %d - Score: %d\n",stringtemp,jtemp,htemp,scoretemp);

        // Lib�ration si premier maillon
        if (i == 0)
        {
            //printf("\nmaillon du debut\n");
            _list_echeance_by_score(c->next,h,j,nbr_iteration-1);
        }

        // Lib�ration si dernier maillon de la liste
        if (temp2->next==NULL)
        {
            //printf("\nmaillon de fin\n");
            prec->next=NULL;
            _list_echeance_by_score(c,h,j,nbr_iteration-1);
        }

        //printf("\nmaillon du milieu\n");
        prec2->next=temp2->next; // Lib�ration du maillon �tudi�
        //printf("maillon que l'on veut liberer: d %d h %d, maintenant que c est fait, le next du prec = d %d h %d",temp2->day, temp2->hour,prec2->next->day, prec2->next->hour);
        free(temp2);
        // printf("\nmaillon du milieu\n");
        _list_echeance_by_score(c,h,j,nbr_iteration-1); // On rappelle la fonction et on recommence ! Condition d'arr�t avec les it�rations
    }
}

void list_echeance_by_score(calendlist b, int h, int j,int nbr_iteration) // fonction chapeau
{
calendlist c=copy_lsc_calend(b); // On cherche � travailler sur une LSC que l'on peut charcuter le coeur libre
_list_echeance_by_score(c,h,j,nbr_iteration);
}



