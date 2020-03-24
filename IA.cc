//
//  IA.cpp
//  TreasureHunt-Command
//
//  Created by Raphael Thibierge on 02/12/2014.
//  Copyright (c) 2014 RT. All rights reserved.
//

#include "IA.h"
using namespace std ;
void initialiserIA(TIA tableauComparasion)
{
    for (int ligne=0; ligne<(NB_CASES-1)*2 ; ligne++)
        for (int colonne=0 ; colonne<4 ; colonne++)
            tableauComparasion[ligne][colonne]=0 ;
}

void afficherIA (TIA tableau)
{
    cout << "+-------------+-------+---------+---------" << endl ;
    cout << "|MeilleurPiece| Ligne | colonne | 2piece  " << endl ;
    cout << "+-------------+-------+---------+---------" << endl ;
    int ligne=0 ;
    while (ligne<(NB_CASES-1)*2 && tableau[ligne][0]!=0)
    {
        for (int colonne=0 ; colonne<4 ; colonne++)
        {
            cout <<"    " << tableau[ligne][colonne] << "    |" ;
        }
        cout << endl << "+---------------------------------------+" << endl ;
        ligne++ ;
    }
}

int analysePieceJ2(TGrille tableau, int positionY, int positionX)
{   // on cherche à renvoyer la plus grosse piece comprise dans la ligne et la colonne correspondant à la futur position si il y a déplacement

    //on prend une piece témoin égale à Zéro pour savoir qu'elle est la plus grosse piece
    int pieceTemoin = 5 ;

    // pour chaque ligne du tableau
    for (int ligne = 0 ; ligne < NB_CASES ; ligne ++)
    {
        // si la valeur de la piece est supérieur à la piece témoin
        if (tableau[ligne][positionX]<pieceTemoin && tableau[ligne][positionX]>0)
            // on actualise la valuer de la piece témoin
            pieceTemoin = tableau[ligne][positionX] ;
    }

    // pareil pour les colonnes
    for (int colonne = 0 ; colonne < NB_CASES ; colonne ++)
    {
        if (tableau[positionY][colonne]<pieceTemoin && tableau[positionY][colonne]>0)
            pieceTemoin = tableau[positionY][colonne] ;
    }
    // on retourne la valeur de la piece témoi qui indique quel est la plus grosse pièce disponible
    return pieceTemoin ;
}

int calculerBonus(Pirate joueur, int piece)
{ // fonction qui calcule les bonnus
    // je sais pas si on la garde,

    if (piece==valeurPiece(joueur.dernierePiece))
    {

        switch (joueur.bonus)
        {
            case 1 : piece+=20 ; break ;
            case 2 : piece+=40 ; break ;
            case 3 : piece+=80 ; break ;
            case 4 : piece+=80 ; break ;
                default : break ;
        }
    }
    return piece ;
}

void remplirTableau(TIA tableauComparaison, TGrille tableau ,int ligne, int colonne, Pirate joueur, int &limitePiece, int &selecteur)
{


    // sinon si (la piece que l'IA peut prendre est supérieur ou égale la meilleur piece dans le tableau) et (que cette piece est inférieur à celle de meilleur piece)
    if (calculerBonus(joueur, valeurPiece(tableau[ligne][colonne])) > (calculerBonus(joueur, valeurPiece(tableauComparaison[0][colonne_MeilleurPiece])))
        && tableau[ligne][colonne]<tableauComparaison[0][colonne_MeilleurPiece])
        {
            limitePiece=tableau[ligne][colonne] ;
            initialiserIA(tableauComparaison) ;
            cout << "coucou" << endl ;
        }
    // si (il y a une piece que l'IA peut prendre) et ( si la piece qui est sélectionner est supérieur à celle déjà présente dans le tableau avec prise en compte des bonnus.
    if (tableau[ligne][colonne]>=limitePiece &&
    calculerBonus(joueur, valeurPiece(tableau[ligne][colonne])) > (calculerBonus(joueur, valeurPiece(tableauComparaison[0][colonne_MeilleurPiece]))))
    {
        initialiserIA(tableauComparaison) ; // réinitialisation  du tableau de l'IA
        tableauComparaison[0][colonne_MeilleurPiece] = tableau[ligne][colonne] ; // On insere la nouvelle valeur
        tableauComparaison[0][colonne_LignePiece] = ligne ;
        tableauComparaison[0][colonne_ColonnePiece] = colonne ;
        tableauComparaison[0][colonnne_PieceJ2] = analysePieceJ2(tableau, ligne, colonne) ;
        selecteur = 1 ;
        afficherIA(tableauComparaison);
    }

    else if (tableau[ligne][colonne]==tableauComparaison[0][colonne_MeilleurPiece])
    { // sinon si la piece sur le plateau est égale à celle du tableau de comparaison

        tableauComparaison[selecteur][colonne_MeilleurPiece] = tableau[ligne][colonne] ;
        tableauComparaison[selecteur][colonne_LignePiece] = ligne ;
        tableauComparaison[selecteur][colonne_ColonnePiece] = colonne ;
        tableauComparaison[selecteur][colonnne_PieceJ2] = analysePieceJ2(tableau, ligne, colonne) ;
        selecteur++ ;
        afficherIA(tableauComparaison);
    }
}


int analyseMeilleurPiece(TIA tableauComparaison, TGrille tableau, int positionX, int positionY, Pirate joueur)
{
// Initialisation du selecteur de ligne dans le tableauComparaison
    int selecteur = 0 ;
    int limitePiece=0 ; // variable qui indique quel piece peut prendre l'IA
//--------------------------------------------------
// Analyse des différentes pièces d'une même colonne
//--------------------------------------------------

    // pour chaque ligne du tableau de piece
    for (int ligne=0 ; ligne<NB_CASES ; ligne++ )
    {
        remplirTableau(tableauComparaison, tableau, ligne, positionX , joueur, limitePiece, selecteur) ;
    }
//-------------------------------------------------
// Analyse des différentes pièces d'une même ligne
//-------------------------------------------------
    for (int colonne=0 ; colonne<NB_CASES ; colonne++ )
    {
        remplirTableau(tableauComparaison, tableau, positionY, colonne, joueur, limitePiece, selecteur) ;
    }
    return selecteur ;
}


void IA(Pirate &Joueur, TGrille tableau, int &positionX, int &positionY)
{
    // on définie un tableau de type TIA pour comparer les différentes pièces
    TIA tableauComparaison ;

    // on vide la case dans laquelle se trouve l'IA
    tableau[positionY][positionX] = 0 ;

    // on initialise le tableau de l'IA
    initialiserIA(tableauComparaison);

    // on récupère la valeur de sélecteur après avoir remplie le tableau, c'est à dire le nombre de ligne parmis lesquelles l'IA va choisir
    int selecteur = analyseMeilleurPiece(tableauComparaison, tableau, positionX, positionY, Joueur) ;

    // l'IA n'a pas encore choisie la ligne du tableauComparaison où se trouve la future piece
    int ligneChoisie=0 ;


    //pour chaque ligne du tableau comparaison
    for (int ligne = 0 ; ligne < selecteur ; ligne++)
    {   // si la ligne selectionner rapporte moins de point au deuxième joueur que celle de la ligne choisie
        if (tableauComparaison[ligne][colonnne_PieceJ2]>tableauComparaison[ligneChoisie][colonnne_PieceJ2])
            // on réactualise la ligne choisie pour le désavantager
            ligneChoisie = ligne ;
    }


    cout << "ligne : " << tableauComparaison[ligneChoisie][colonne_LignePiece] << " ; colonne : " <<  tableauComparaison[ligneChoisie][colonne_ColonnePiece] << " ; valeur piece : " << valeurPiece(tableauComparaison[ligneChoisie][colonne_MeilleurPiece]) << endl ;
    cout << endl << "----------------------------------------" << endl << endl ;
    positionX = tableauComparaison[ligneChoisie][colonne_ColonnePiece] ;
    positionY = tableauComparaison[ligneChoisie][colonne_LignePiece] ;

}
