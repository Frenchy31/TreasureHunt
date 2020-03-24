//
//  piece.h
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 10/11/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#ifndef __TreasureHunt_Command__piece__
#define __TreasureHunt_Command__piece__

#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include "SDL_image.h"

const int CASE_HAUTEUR = 70 ;
struct CasePiece // structre d'une case pour chaque case du plateau
{
    //int valeurPiece ; // valeur de la pièce : 10, 20, 30, 50 ou 100 ;
    //int colonne ; // numéro de la colonne sur laquelle elle se trouve
    //int ligne ; // numéro de la ligne sur laquelle elle se trouve
    SDL_Surface *image ;
    SDL_Surface *image2 ;
    SDL_Rect rectangle ;
    SDL_Rect pieceVide ;
    SDL_Rect piece10 ;
    SDL_Rect piece20 ;
    SDL_Rect piece30 ;
    SDL_Rect piece50 ;
    SDL_Rect piece100 ;
};

int valeurPiece(int piece) ;

void initialiserPiece(CasePiece &piece) ;


#endif /* defined(__TreasureHunt_Command__piece__) */
