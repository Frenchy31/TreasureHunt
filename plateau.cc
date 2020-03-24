//
//  plateau.cpp
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 10/11/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "SDL_ttf.h"
#include "plateau.h"


bool caseMilieu(int x, int y)
{
    /*---------------- Nom de la fonction -----------------------
    NOM_FONCTION     caseMilieu
    ------------------ Auteur , Dates ---------------------------
    Nom/Date: Thibierge Raphael    --      15/11/2014
    ------------------ Description ------------------------------
    Cette fonction permet de savoir si la case passée en
    paramètre est celle du milieu ou non
    ----------------- Entrées -----------------------------------
    La fonciton prend en entrée le numéro de la ligne et le
    numéro de la colonne de la case à analyser
    --------------------- Sorties -------------------------------
    La fonction renvoit à travers un booléen si c'est la case du
    milieu ou non
    ------------------------------------------------------------*/
    return (x==LC_MILIEU && y==LC_MILIEU) ;
}


void initTableau(TGrille tableau)
{
    /* *************** Nom de la fonction ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
    ∗ NOM_FONCTION          initTableau                         *
    ****************** Auteur , Dates ***************************
    ∗Nom/Date : Thibierige Raphael ; version 2 : 29/11          *
    ∗∗∗∗∗∗∗*∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
    ∗ Fonction qui initiailise toute les cases du tableau en    *
      plaçant les pièces aléatoirement.
    ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Entrées ***********************************
    ∗ La fontion prend en entrée le tableau de pièces           *
    ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Sorties *******************************
    ∗ La fonction ne renvoit rien (VOID) Le tableau passé en    *
      en entrée est remlplie avec toutes les pièces à la fin de
     la fonction
    ************************************************************/

    srand(time(NULL)) ; // on remet le temps à 0

// les variables lignes et colonnes définissent à la cases
// dans laquel lma pièce va être placée
    int ligne, colonne, ancienneLigne, ancienneColonne ;

// Initialisation du tableau avec des zéros qui indiquent que
// la case ne contient pas de pièces
    for (int x=0 ; x < NB_CASES ; x++)
    { //pour chaque ligne
        for (int y=0; y < NB_CASES; y++ )

        {   // pour chaque colonne
            tableau[x][y]=0 ;   // ansi toutes les cases ne contiennent
        }   // acune pièce
    }

    // Placement des pièces de 50
    for (int piece50=0 ; piece50 < NB_50 ; piece50++)
    {
        ligne = rand() % NB_CASES ;
        colonne = rand() % NB_CASES ;
        while (caseVide(ligne, colonne, tableau)==false || caseMilieu(ligne, colonne)==true || tableau[ligne-1][colonne]==2 || tableau[ligne+1][colonne]==2 || tableau[ligne][colonne+1]==2 || tableau[ligne][colonne-1]==2) {
            ligne = rand() % NB_CASES ;
            colonne = rand() % NB_CASES ;
        }
        tableau[ligne][colonne]=2 ;
    }

    // Placement des pièces de 30, 2O et 10
    for (int piece=3 ; piece < 6 ; piece++){
        for (int nombrePiece20=0 ; nombrePiece20 < 14 ; nombrePiece20++) {

            ligne = rand() % NB_CASES ;
            colonne = rand() % NB_CASES ;

            if (piece == 5){
                while (caseVide(ligne, colonne, tableau)==false || caseMilieu(ligne, colonne)==true){

                    ligne = rand() % NB_CASES ;
                    colonne = rand() % NB_CASES ;
                }
            }

            else {
                while (caseVide(ligne, colonne, tableau)==false || caseMilieu(ligne, colonne)==true || tableau[ligne-1][colonne]==piece || tableau[ligne+1][colonne]== piece || tableau[ligne][colonne+1]==piece || tableau[ligne][colonne-1]==piece) {
                    ligne = rand() % NB_CASES ;
                    colonne = rand() % NB_CASES ;
                }
            }

            tableau[ligne][colonne]=piece ;
        }
    }


// Placement de la pièce de 100
    ligne = 0 ;
    while (ligne<NB_CASES)
    {   //utilisation du while car utilisation d'un break
        // tand que le numéro de la ligne est inférieur au nombre de case
        colonne = 0 ;
        while (colonne<NB_CASES)
        {   // tant que le numéro de la ligne est inférieur au nombre de case
            if (caseVide(ligne, colonne, tableau)==true && caseMilieu(ligne, colonne)==false )
            {   // si la case est vide et que ce n'est pas la case du milieur
                bool correction = false ; // pas de correction
                // au cas ou la pièce de 100 tombe sur la colonne ou la ligne de départ

                if (ligne==LC_MILIEU)
                {   // si la pièce de 100 se trouve sur la ligne du milieu
                    while (ligne==LC_MILIEU)
                        //tant qu'on retombe sur la ligne du milieu
                        ligne = rand() % NB_CASES ; // on rechoisi une ligne aléatoirement
                    tableau[LC_MILIEU][colonne]=tableau[ligne][colonne];
                    // on déplace la pièce qui va remplacer celle de 100
                }

                else if (colonne==LC_MILIEU)
                {   // si la pièce de 100 se trouve sur la colonne du milieu
                    while (colonne==LC_MILIEU)
                        //tant qu'on retombe sur la colonne du milieu
                        colonne = rand() % NB_CASES ; // on rechoisi une colonne aléatoirement
                    tableau[ligne][LC_MILIEU]=tableau[ligne][colonne];
                    // on déplace la pièce qui va remplacer celle de 100
                }

                tableau[ligne][colonne]=1 ;  // on place la ligne de 100 dans la case définitive
                break ; // on sort de la boucle
            }
            colonne++ ; // on incrémente la colonne si on est toujours dans la deuxième boucle  while
        }
        ligne++ ; // on incrémente la ligne si on est toujours dans la première bouble while
    }
}

bool caseVide(int ligne, int colonne, TGrille tableau)
{
    /*---------------- Nom de la fonction -----------------------
     NOM_FONCTION     caseVide
     ------------------ Auteur , Dates ---------------------------
     Nom/Date: Thibierge Raphael    --      15/11/2014
     ------------------ Description ------------------------------
     Cette fonction indique si la case passée en paramètre est
     vide ou non
     ----------------- Entrées -----------------------------------
     La fonction prend en paramèrtre le numéro de la ligne et le
     numéro de la colonne, de la pièce à analyser ainsi que le
     tableau de pièce à deux entrée
     --------------------- Sorties -------------------------------
     La fonction renvoie un booléen qui indique si la case est
     vide ou non
     ------------------------------------------------------------*/

    bool reponse = false ; // de base la case n'est pas vide
    if (tableau[ligne][colonne]==0) // si la case du tableau contient 0
        reponse = true ; // alors la case est vide
    return reponse ; // on renvoit la réponse
}

bool verifierCase(int positionJoueurY, int positionJoueurX, int ligne, int colonne, TGrille tableau)// fonction qui vérifie la case afin de savoir si elle est accessible
{

    bool deplacement = false ;
    if (!caseVide(ligne, colonne, tableau))
        if ((positionJoueurX==colonne) || (positionJoueurY==ligne))
                deplacement = true ;
    return deplacement ;
}

