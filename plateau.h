//
//  plateau.h
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 10/11/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#ifndef __TreasureHunt_Command__plateau__
#include "SDL_ttf.h"
#define __TreasureHunt_Command__plateau__

#include <stdio.h>
#include<iostream>
#include<cstdlib>



#include<time.h>
#include<sstream>



const int NB_100 = 1 ;
const int NB_50 = 5 ;
const int NB_30 = 14 ;
const int NB_20 = 14 ;
const int NB_10 =  14 ;
const int LC_MILIEU = 3 ; // numéro de la ligne et de la colonne du milieu
const int NB_CASES = 7 ;


typedef int TGrille[NB_CASES][NB_CASES] ;

bool caseMilieu(int x, int y) ;

void initTableau(TGrille tableau) ;

bool caseVide(int x, int y, TGrille tableau) ;

bool verifierCase(int positionJoueurY, int positionJoueurX, int ligne, int colonne, TGrille tableau) ;



#endif /* defined(__TreasureHunt_Command__plateau__) */
