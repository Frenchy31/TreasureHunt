//
//  piece.cpp
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 10/11/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#include "piece.h"


int valeurPiece(int piece)
{
    switch (piece)
    {
        case 0 : piece = 0 ; break ;
        case 1 : piece = 100 ; break;
        case 2 : piece = 50 ; break;
        case 3 : piece = 30 ; break;
        case 4 : piece = 20 ; break;
        case 5 : piece = 10 ; break;
        default: piece = 0 ; break;
    }
    return piece ;
}

void initialiserPiece(CasePiece &piece)
{

    piece.image = SDL_LoadBMP("pieces.bmp") ;
    piece.image2 = SDL_LoadBMP("images/pieces.bmp") ;

    // rectangle contenant la case vide
    piece.pieceVide.x = 350 ;
    piece.pieceVide.y = 0 ;
    piece.pieceVide.w = CASE_HAUTEUR ;
    piece.pieceVide.h = CASE_HAUTEUR ;

    // rectangle contenant la case de la pièce 10
    piece.piece10.x = 0 ;
    piece.piece10.y = 0 ;
    piece.piece10.w = CASE_HAUTEUR ;
    piece.piece10.h = CASE_HAUTEUR ;

    // rectangle contenant la case de la pièce 20
    piece.piece20.x = 70 ;
    piece.piece20.y = 0 ;
    piece.piece20.w = CASE_HAUTEUR ;
    piece.piece20.h = CASE_HAUTEUR ;

    // rectangle contenant la case de la pièce 30
    piece.piece30.x = 140 ;
    piece.piece30.y = 0 ;
    piece.piece30.w = CASE_HAUTEUR ;
    piece.piece30.h = CASE_HAUTEUR ;

    // rectangle contenant la case de la pièce 50
    piece.piece50.x = 210 ;
    piece.piece50.y = 0 ;
    piece.piece50.w = CASE_HAUTEUR ;
    piece.piece50.h = CASE_HAUTEUR ;

    // rectangle contenant la case de la pièce 100
    piece.piece100.x = 280 ;
    piece.piece100.y = 0 ;
    piece.piece100.w = CASE_HAUTEUR ;
    piece.piece100.h = CASE_HAUTEUR ;
}
