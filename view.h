#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "structure.h"

void AfficherLesPosts(SDL_Surface *ecran, SDL_Rect *positionFond,tree a, calendlist c, int h, int j);
int view(tree a, calendlist c);

#endif // VIEW_H_INCLUDED
