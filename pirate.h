//
//  pirate.h
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 10/11/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#ifndef __TreasureHunt_Command__pirate__
#define __TreasureHunt_Command__pirate__

#include <stdio.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include "piece.h"

#include "SDL_image.h"
using namespace std ;

const int largeurPirate = 70;
const int hauteurPirate = 70;

struct Pirate
{
    SDL_Rect imageJoueurScore ; // rectangle contenant l'image du pirate pour les scores
    SDL_Rect imageJoueurPlateau ; // rectangle contenant l'image du pirate sur le plateau
    SDL_Surface *imageVictoire ;
    int score ;
    int indice ;
    int dernierePiece;
    int bonus;

    // Mouvements
    SDL_Surface *imagePirate;

    SDL_Rect lecturebas01;
    SDL_Rect lecturebas02;
    SDL_Rect lecturebas03;

    SDL_Rect lecturegauche01;
    SDL_Rect lecturegauche02;
    SDL_Rect lecturegauche03;

    SDL_Rect lecturehaut01;
    SDL_Rect lecturehaut02;
    SDL_Rect lecturehaut03;

    SDL_Rect lecturedroite01;
    SDL_Rect lecturedroite02;
    SDL_Rect lecturedroite03;


};

struct Bonus
{
    SDL_Surface *surface;
    SDL_Surface *bonus0;
    SDL_Surface *bonus1;
    SDL_Surface *bonus2;
    SDL_Surface *bonus3;
    SDL_Surface *bonus4;

};

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

SDL_Surface *
loadImage(string filename);

SDL_Surface *
loadImageWithColorKey(string filename, int r, int g, int b);

void initialiserPirates(Pirate &J1, Pirate &J2) ;

void chargerImageBonus(Bonus &bonus) ;

void scorePirate(Pirate &joueur, int piece) ;

bool testPartieGagnee(Pirate joueur) ;

void bonusPirate(Pirate &joueur, int piece) ;

void mouvementBas(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen);

void mouvementGauche(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen);

void mouvementHaut(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen);

void mouvementDroite(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen);

#endif /* defined(__TreasureHunt_Command__pirate__) */
