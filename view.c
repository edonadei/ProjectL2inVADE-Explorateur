#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "save.h"
#include "structure.h"
#include "tools.h"
#include "struct_funct.h"
#include "initialisation.h"
#include "view.h"

#define SIZE 47


void AfficherLesPosts(SDL_Surface *ecran, SDL_Rect *positionFond,tree a, calendlist c, int h, int j)
{
    TTF_Font *police = TTF_OpenFont("Arialbold.ttf", 14);
    SDL_Color Noir = {0, 0, 0};

    liststring list_of_strings = init_new_lscstring("root");

    list_echeance_by_score(c,h,j,5,list_of_strings);

    //printf("%s", list_of_strings->next->next->stringtosend);

    listnode b=init_new_lscnode(a);
    recherche_fichier_selon_tags_v2(a,b,"physique","champs electromagnetiques","ce");



    SDL_Surface *Calend01 = TTF_RenderText_Blended(police, list_of_strings->next->stringtosend, Noir);
 SDL_Surface *Calend02 = TTF_RenderText_Blended(police, list_of_strings->next->next->stringtosend, Noir);

    SDL_Surface *Calend03 = TTF_RenderText_Blended(police, list_of_strings->next->next->next->stringtosend, Noir);
    SDL_Surface *Calend04 = TTF_RenderText_Blended(police, list_of_strings->next->next->next->next->stringtosend, Noir);
    SDL_Surface *Calend05 = TTF_RenderText_Blended(police, list_of_strings->next->next->next->next->next->stringtosend, Noir);


    SDL_Surface *Post01 = TTF_RenderText_Blended(police, b->next->arbre->word, Noir);
    SDL_Surface *Post02 = TTF_RenderText_Blended(police, b->next->next->arbre->word, Noir);
    SDL_Surface *Post03 = TTF_RenderText_Blended(police, b->next->next->next->arbre->word, Noir);
    SDL_Surface *Post04 = TTF_RenderText_Blended(police, b->next->next->next->next->arbre->word, Noir);
    SDL_Surface *Post05 = TTF_RenderText_Blended(police, b->next->next->next->next->next->arbre->word, Noir);
    SDL_Surface *Post06 = TTF_RenderText_Blended(police, b->next->next->next->next->next->next->arbre->word, Noir);
    SDL_Surface *Post07 = TTF_RenderText_Blended(police, b->next->next->next->next->next->next->arbre->word, Noir);

    SDL_Surface *Tag01 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->arbre), Noir);
    SDL_Surface *Tag02 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->arbre), Noir);
    SDL_Surface *Tag03 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->next->arbre), Noir);
    SDL_Surface *Tag04 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->next->next->arbre), Noir);
    SDL_Surface *Tag05 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->next->next->next->arbre), Noir);
    SDL_Surface *Tag06 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->next->next->next->next->arbre), Noir);
    SDL_Surface *Tag07 = TTF_RenderText_Blended(police, print_tag_echeance(b->next->next->next->next->next->next->next->arbre), Noir);



    positionFond->x = 346;
    positionFond->y = 93;
    SDL_BlitSurface(Post01, NULL, ecran, positionFond); // Blit du texte
    positionFond->x = 346;
    positionFond->y = 108;
    SDL_BlitSurface(Tag01, NULL, ecran, positionFond); // Blit du texte

    positionFond->x = 346;
    positionFond->y = 165;
    SDL_BlitSurface(Post02, NULL, ecran, positionFond); // Blit du Post02
    positionFond->x = 346;
    positionFond->y = 180;
    SDL_BlitSurface(Tag02, NULL, ecran, positionFond); // Blit du Post02

    positionFond->x = 346;
    positionFond->y = 237;
    SDL_BlitSurface(Post03, NULL, ecran, positionFond); // Blit du Post03
    positionFond->x = 346;
    positionFond->y = 252;
    SDL_BlitSurface(Tag03, NULL, ecran, positionFond); // Blit du Post02

    positionFond->x = 346;
    positionFond->y = 309;
    SDL_BlitSurface(Post04, NULL, ecran, positionFond); // Blit du Post04
    positionFond->x = 346;
    positionFond->y = 324;
    SDL_BlitSurface(Tag04, NULL, ecran, positionFond); // Blit du texte


    positionFond->x = 346;
    positionFond->y = 381;
    SDL_BlitSurface(Post05, NULL, ecran, positionFond); // Blit du Post05
    positionFond->x = 346;
    positionFond->y = 396;
    SDL_BlitSurface(Tag05, NULL, ecran, positionFond); // Blit du texte


    positionFond->x = 346;
    positionFond->y = 453;
    SDL_BlitSurface(Post06, NULL, ecran, positionFond); // Blit du Post06
    positionFond->x = 346;
    positionFond->y = 468;
    SDL_BlitSurface(Tag06, NULL, ecran, positionFond); // Blit du texte


    positionFond->x = 346;
    positionFond->y = 525;
    SDL_BlitSurface(Post07, NULL, ecran, positionFond); // Blit du Post07
    positionFond->x = 346;
    positionFond->y = 540;
    SDL_BlitSurface(Tag01, NULL, ecran, positionFond); // Blit du texte


    positionFond->x = 10;
    positionFond->y = 250;
    SDL_BlitSurface(Calend01, NULL, ecran, positionFond); // Blit du texte
    positionFond->x = 10;
    positionFond->y = 280;
    SDL_BlitSurface(Calend02, NULL, ecran, positionFond); // Blit du texte
    positionFond->x = 10;
    positionFond->y = 310;
    SDL_BlitSurface(Calend03, NULL, ecran, positionFond); // Blit du texte
    positionFond->x = 10;
    positionFond->y = 340;
    SDL_BlitSurface(Calend04, NULL, ecran, positionFond); // Blit du texte
    positionFond->x = 10;
    positionFond->y = 370;
    SDL_BlitSurface(Calend05, NULL, ecran, positionFond); // Blit du texte

    positionFond->x = 0;
    positionFond->y = 0;
    SDL_Flip(ecran);
    TTF_CloseFont(police);

    SDL_FreeSurface(Post01);
    SDL_FreeSurface(Post02);
    SDL_FreeSurface(Post03);
    SDL_FreeSurface(Post04);
    SDL_FreeSurface(Post05);
    SDL_FreeSurface(Post06);
    SDL_FreeSurface(Post07);
    SDL_FreeSurface(Tag01);
    SDL_FreeSurface(Tag02);
    SDL_FreeSurface(Tag03);
    SDL_FreeSurface(Tag04);
    SDL_FreeSurface(Tag05);
    SDL_FreeSurface(Tag06);
    SDL_FreeSurface(Tag07);
}

int view(tree a, calendlist c)
{

    int h=1,j=1;

    SDL_Surface *ecran = NULL;

    SDL_Surface *fond = NULL;
    SDL_Rect positionFond;
    SDL_Surface *fondExplorerMatiere = IMG_Load("Background025.png"), *fondExplorerDevoir = IMG_Load("Background025.png");
    SDL_Rect positionFondExplorerMatiere, positionFondExplorerDevoir, boutonExplorerMatiere, boutonExplorerDevoir;
    SDL_Surface *fondAccueilMatiere = IMG_Load("Background015.png"), *fondAccueilDevoir = IMG_Load("Background015.png");
    SDL_Rect positionFondAccueilMatiere, positionFondAccueilDevoir, boutonAccueilMatiere, boutonAccueilDevoir;

    SDL_Event event;
    int continuer = 1;
    int onglet = 0, matiere = 0, devoir = 0;

    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_WM_SetIcon(IMG_Load("Icone.png"), NULL);
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("VADE by Vincent, Arnaud, Damien & Emerick", NULL);

    onglet = 1;
    fond = IMG_Load("Background01.png");
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
    AfficherLesPosts(ecran, &positionFond,a,c,h,j); // 1ère affichage avec score uniquement
    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.x >= 428 && event.button.x <= 528 && event.button.y >= 11 && event.button.y <= 53)
            {
                onglet = 1;
                fond = IMG_Load("Background01.png");
                positionFond.x = 0;
                positionFond.y = 0;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                AfficherLesPosts(ecran, &positionFond,a,c,h,j); // Affichage score uniquement (si on quitte "Explorere" sans avoir validé
                SDL_Flip(ecran);
            }
            if(event.button.x >= 552 && event.button.x <= 652 && event.button.y >= 11 && event.button.y <= 53)
            {
                onglet = 2;
                matiere = 0;
                devoir = 0;
                fond = IMG_Load("Background02.png");
                positionFond.x = 0;
                positionFond.y = 0;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            if(onglet == 2 && event.button.x >= 105 && event.button.x <= 175 && event.button.y >= 122 && event.button.y <= 148)
            {
                matiere = 1;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 105;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 122;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 70;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Anglais\n");
            }
            if(onglet == 2 && event.button.x >= 182 && event.button.x <= 375 && event.button.y >= 122 && event.button.y <= 148)
            {
                matiere = 2;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 182;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 122;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 193;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Comptes de l'entreprise\n");
            }
            if(onglet == 2 && event.button.x >= 382 && event.button.x <= 696 && event.button.y >= 122 && event.button.y <= 148)
            {
                matiere = 3;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 382;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 122;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 314;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Argumentation et ecriture journalistique\n");
            }
            if(onglet == 2 && event.button.x >= 95 && event.button.x <= 381 && event.button.y >= 208 && event.button.y <= 234)
            {
                matiere = 4;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 95;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 208;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 286;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Algorithmie\n");
            }
            if(onglet == 2 && event.button.x >= 388 && event.button.x <= 706 && event.button.y >= 208 && event.button.y <= 234)
            {
                matiere = 5;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 388;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 208;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 318;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Programmation\n");
            }
            if(onglet == 2 && event.button.x >= 254 && event.button.x <= 438 && event.button.y >= 294 && event.button.y <= 320)
            {
                matiere = 6;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 254;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 294;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 184;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Mathematiques du reel\n");
            }
            if(onglet == 2 && event.button.x >= 445 && event.button.x <= 547 && event.button.y >= 294 && event.button.y <= 320)
            {
                matiere = 7;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 445;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 294;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 102;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Statistiques\n");
            }
            if(onglet == 2 && event.button.x >= 89 && event.button.x <= 320 && event.button.y >= 380 && event.button.y <= 406)
            {
                matiere = 8;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 89;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 380;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 231;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Champs electromagnetiques\n");
            }
            if(onglet == 2 && event.button.x >= 327 && event.button.x <= 492 && event.button.y >= 380 && event.button.y <= 406)
            {
                matiere = 9;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 327;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 380;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 165;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Physique quantique\n");
            }
            if(onglet == 2 && event.button.x >= 499 && event.button.x <= 712 && event.button.y >= 380 && event.button.y <= 406)
            {
                matiere = 10;
                boutonExplorerMatiere.x = positionFondExplorerMatiere.x = 499;
                boutonExplorerMatiere.y = positionFondExplorerMatiere.y = 380;
                boutonExplorerMatiere.h = 26;
                boutonExplorerMatiere.w = 213;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                if(devoir)
                {
                    SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                }
                SDL_Flip(ecran);

                //printf("-> Systemes de transmission\n");
            }
            if(onglet == 2 && event.button.x >= 209 && event.button.x <= 300 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 1;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 209;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 91;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> Cours\n");
            }
            if(onglet == 2 && event.button.x >= 314 && event.button.x <= 365 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 2;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 314;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 51;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> TD\n");
            }
            if(onglet == 2 && event.button.x >= 379 && event.button.x <= 429 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 3;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 379;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 50;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> TP\n");
            }
            if(onglet == 2 && event.button.x >= 443 && event.button.x <= 494 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 4;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 443;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 51;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> CE\n");
            }
            if(onglet == 2 && event.button.x >= 508 && event.button.x <= 559 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 5;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 508;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 51;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> DE\n");
            }
            if(onglet == 2 && event.button.x >= 573 && event.button.x <= 628 && event.button.y >= 454 && event.button.y <= 498)
            {
                devoir = 6;
                boutonExplorerDevoir.x = positionFondExplorerDevoir.x = 573;
                boutonExplorerDevoir.y = positionFondExplorerDevoir.y = 454;
                boutonExplorerDevoir.h = 44;
                boutonExplorerDevoir.w = 55;
                SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                SDL_BlitSurface(fondExplorerDevoir, &boutonExplorerDevoir, ecran, &positionFondExplorerDevoir);
                if(matiere)
                {
                    SDL_BlitSurface(fondExplorerMatiere, &boutonExplorerMatiere, ecran, &positionFondExplorerMatiere);
                }
                SDL_Flip(ecran);

                //printf("-> TAI\n");
            }
            //Bouton Validé
            if(onglet == 2 && event.button.x >= 350 && event.button.x <= 450 && event.button.y >= 536 && event.button.y <= 578)
            {
                char filtre_matiere[SIZE];
                char filtre_devoir[SIZE];
                onglet = 1;
                fond = IMG_Load("Background01.png");



                switch(matiere)
                {
                case 1:
                    boutonAccueilMatiere.x = 12;
                    boutonAccueilMatiere.y = 12;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 70;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Anglais\n");
                    sprintf(filtre_matiere,"anglais");
                    break;
                case 2:
                    boutonAccueilMatiere.x = 94;
                    boutonAccueilMatiere.y = 12;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 193;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Comptes de l'entreprise\n");
                    sprintf(filtre_matiere,"comptes de l'entreprise");
                    break;
                case 3:
                    boutonAccueilMatiere.x = 299;
                    boutonAccueilMatiere.y = 12;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 208;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Argumentation et ecriture journalistique\n");
                    sprintf(filtre_matiere,"communication");
                    break;
                case 4:
                    boutonAccueilMatiere.x = 661;
                    boutonAccueilMatiere.y = 12;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 100;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Algorithmie\n");
                    sprintf(filtre_matiere,"algorithmie");
                    break;
                case 5:
                    boutonAccueilMatiere.x = 519;
                    boutonAccueilMatiere.y = 12;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 130;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    sprintf(filtre_matiere,"programmation");
                    break;
                case 6:
                    boutonAccueilMatiere.x = 12;
                    boutonAccueilMatiere.y = 50;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 184;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Mathematiques du reel\n");
                    sprintf(filtre_matiere,"mathematiques du reel");
                    break;
                case 7:
                    boutonAccueilMatiere.x = 208;
                    boutonAccueilMatiere.y = 50;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 102;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Statistiques\n");
                    sprintf(filtre_matiere,"statistiques");
                    break;
                case 8:
                    boutonAccueilMatiere.x = 322;
                    boutonAccueilMatiere.y = 50;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 231;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Champs electromagnetiques\n");
                    sprintf(filtre_matiere,"champs electromagnetiques");
                    break;
                case 9:
                    boutonAccueilMatiere.x = 565;
                    boutonAccueilMatiere.y = 50;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 165;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Physique quantique\n");
                    sprintf(filtre_matiere,"physique quantique");
                    break;
                case 10:
                    boutonAccueilMatiere.x = 12;
                    boutonAccueilMatiere.y = 88;
                    positionFondAccueilMatiere.x = 36;
                    positionFondAccueilMatiere.y = 132;
                    boutonAccueilMatiere.h = 26;
                    boutonAccueilMatiere.w = 225;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    if(devoir)
                    {
                        SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Systemes de transmission\n");
                    sprintf(filtre_matiere,"systemes de transmission");
                    break;
                default:

                    break;
                }

                switch(devoir)
                {
                case 1:
                    boutonAccueilDevoir.x = 237;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 71;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);

                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==> Cours\n");
                    sprintf(filtre_devoir,"cours");
                    break;
                case 2 :
                    boutonAccueilDevoir.x = 320;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 35;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==> TD\n");
                    sprintf(filtre_devoir,"td");
                    break;
                case 3 :
                    boutonAccueilDevoir.x = 367;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 34;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==> TP\n");
                    sprintf(filtre_devoir,"tp");
                    break;
                case 4 :
                    boutonAccueilDevoir.x = 413;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 35;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==> CE\n");
                    sprintf(filtre_devoir,"ce");
                    break;
                case 5 :
                    boutonAccueilDevoir.x = 460;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 35;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==> DE\n");
                    sprintf(filtre_devoir,"de");
                    break;
                case 6 :
                    boutonAccueilDevoir.x = 507;
                    boutonAccueilDevoir.y = 88;
                    positionFondAccueilDevoir.x = 36;
                    positionFondAccueilDevoir.y = 170;
                    boutonAccueilDevoir.h = 26;
                    boutonAccueilDevoir.w = 37;
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_BlitSurface(fondAccueilDevoir, &boutonAccueilDevoir, ecran, &positionFondAccueilDevoir);
                    if(matiere)
                    {
                        SDL_BlitSurface(fondAccueilMatiere, &boutonAccueilMatiere, ecran, &positionFondAccueilMatiere);
                    }
                    SDL_Flip(ecran);

                    //printf("==>TAI\n");
                    sprintf(filtre_devoir,"tai");
                    break;
                default:

                    break;
                }
                if(matiere==0 && devoir==0)
                {
                    SDL_BlitSurface(fond, NULL, ecran, &positionFond);
                    AfficherLesPosts(ecran, &positionFond,a,c,h,j);
                    SDL_Flip(ecran);
                }

                //filtre_liste_echeance(calendlist a,filtre_matiere);
                //filtre_liste_echeance(calendlist a,filtre_devoir);


            }
        }
    }

    SDL_FreeSurface(fond);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
