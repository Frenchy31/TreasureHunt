//
//  IA.h
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 02/12/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#ifndef __TreasureHunt_Command__IA__
#define __TreasureHunt_Command__IA__

#include <stdio.h>
#include "plateau.h"
#include"pirate.h"



typedef int TIA[(NB_CASES-1)*2][4] ;

const int colonne_MeilleurPiece = 0 ;
const int colonne_LignePiece = 1 ;
const int colonne_ColonnePiece = 2 ;
const int colonnne_PieceJ2=3 ;


void initialiserIA(TIA tableauComparasion);

void afficherIA(TIA tableau);

int analysePieceJ2(TGrille tableau, int positionY, int positionX);

int calculerBonus(Pirate joueur, int piece) ;

void remplirTableau(TIA tableauComparaison, TGrille tableau ,int ligne, int colonne, Pirate joueur, int &limitePiece, int &selecteur) ;

int analyseMeilleurPiece(TIA tableauComparaison ,Pirate Joueur, TGrille tableau, int positionX, int positionY);

void IA(Pirate &Joueur, TGrille tableau, int &positionX, int &positionY);

#endif /* defined(__TreasureHunt_Command__IA__) */
