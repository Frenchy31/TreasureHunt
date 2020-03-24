//  main.cpp
//  TreasureHunt
//
//  Created by Raphael Thibierge and Aubin Puyoou on 10/11/2014.

#include <iostream>
#include <sstream>
#include "fenetre.h"
#include "SDL_ttf.h"

using namespace std ;

// seulement j1 peut gagner je crois
// piece de J1 au dessus de bonus ne se charge pas au bon moment avec IA

int main(int argc, const char * argv[]) {

    bool quit=false ;
    bool play=false ;
    int modeJeu = 0 ;

    //----------------------
    //       Fenetre SDL
    //----------------------
    SDL_Init(SDL_INIT_EVERYTHING); // Initialisation de tous les modules SDL
    TTF_Init();
    SDL_Surface *screen ;
    SDL_Event event ; // variable contenant les événements

    TTF_Font *score;
    SDL_Color scoreNoir = {255, 255, 255} ;
    string police="Hawaii_Killer.ttf" ;
    score = TTF_OpenFont(police.c_str(), FONT_SIZE);

    // création de la fenetre screen
	screen = SDL_SetVideoMode(largeurEcran, hauteurEcran, 32, SDL_SWSURFACE) ; // initialisation de la surface screen

	SDL_Surface *blanc ; // surface contenant l'image de fond blanche
    SDL_Surface *flag ; // drapeau de pirate

    blanc = SDL_LoadBMP("images/fond.bmp") ; // chargement de l'image de fond
    flag = SDL_LoadBMP("flag.bmp") ;

    //----------------------
    //       Menu
    //----------------------
    Menu menu ;
    initialiserMenu(menu) ;

    //----------------------
    //       Plateau
    //----------------------
    TGrille tableauPiece ;

    //----------------------
    //       Joueurs
    //----------------------
    Pirate J1 ;
    Pirate J2 ;
    int positionJoueurX=3 ;
    int positionJoueurY=3 ;

    initialiserPirates(J1, J2) ;
    int joueur = J1.indice ; // variable joueur correspond au joueur qui doit jouer, J1 commence

    SDL_Surface *imagePirateScore ;
    imagePirateScore = SDL_LoadBMP("piratesSprite2.bmp") ;
    Uint32 colorkeyPirate = SDL_MapRGB( imagePirateScore->format, 255, 255, 255 ); // on définit la couleur qu'il faudra
    // rendre transparente dans les images qu'on va charger
    SDL_SetColorKey(imagePirateScore, SDL_SRCCOLORKEY, colorkeyPirate) ;

    //----------------------
    //       Bonus
    //----------------------
    Bonus bonus;
    chargerImageBonus(bonus) ;

    //Uint32 colorkeyBonus = SDL_MapRGB(Bonus0->format, 255, 255, 255 ) ;
    //SDL_SetColorKey(Bonus0, SDL_SRCCOLORKEY, colorkeyBonus) ;

    //---------
    // Initialisation des pièces
    //---------
    CasePiece piece ;
    initialiserPiece(piece) ;
    SDL_SetColorKey(piece.image, SDL_SRCCOLORKEY, colorkeyPirate) ; // a mettre dans initialiser piece

    //---------
    // Initialisation des scores
    //---------
    ostringstream scoreJ1;
    scoreJ1.flush();
    scoreJ1.str("");
    ostringstream scoreJ2;
    scoreJ2.flush();
    scoreJ2.str("");

    //----------------------
    //       Boucle Principale
    //----------------------

    while (!quit)
    {
        if (!play)
            afficherMenu(menu, screen) ;

        else
        {
            afficherDecor(J1, J2, screen,imagePirateScore, blanc, flag, menu);
            afficherPlateau(piece, screen, tableauPiece) ;
            afficherBonus(J1, screen, bonus);
            afficherBonus(J2, screen, bonus);
            afficherScorePiece(J1, screen,piece);
            afficherScorePiece(J2, screen,piece);


            if (joueur==-1)
                afficherPirate(J1, positionJoueurY, positionJoueurX, screen) ;
            else
                afficherPirate(J2, positionJoueurY, positionJoueurX, screen) ;

            // re=placer scoreJ1 par pirate.scoreMessage
            scoreJ1.str("");
            scoreJ1 << J1.score;
            scoreJ2.str("");
            scoreJ2 << J2.score;

            showMessageScreen(scoreJ1.str(),620, 390,score,FONT_SIZE,scoreNoir,screen);
            showMessageScreen(scoreJ2.str(),850, 390,score,FONT_SIZE,scoreNoir,screen);


            if (testPartieGagnee(J1))
            {
                partieGagnee(J1, play, screen) ;
                initialiserPirates(J1, J2) ;


            }
            else if (testPartieGagnee(J2))
            {
                partieGagnee(J2, play, screen) ;
                initialiserPirates(J1, J2) ;
            }
        }

        SDL_Flip(screen) ;


        while(SDL_PollEvent(&event)) // boucle qui gère les évènements
            if(event.type==SDL_QUIT)
                quit=true; // pour quiter le jeu

        if ( event.type == SDL_MOUSEBUTTONDOWN) // gestion du clic de la souris
        {
            int sourisX = event.button.x ; // on récupère l'abscisse de la souris
            int sourisY = event.button.y ; // on récupère l'ordonnée de la souris

            if (!play)
            {

                if ((sourisX>menu.boutonJouerX) && (sourisX<menu.boutonJouerX+menu.boutonLargeur))
                {
                    if ((sourisY>menu.boutonJouerSeulY) && (sourisY<menu.boutonJouerSeulY+menu.boutonHauteur))
                    {
                        initTableau(tableauPiece) ;
                        positionJoueurX, positionJoueurY = 3, 3 ;
                        play = true ;
                        modeJeu = 1 ;
                    }

                    else if ((sourisY>menu.boutonJouerDeuxY) && (sourisY<menu.boutonJouerDeuxY+menu.boutonHauteur) )
                    {
                        initTableau(tableauPiece) ;
                        positionJoueurX, positionJoueurY = 3, 3 ;
                        play = true ;
                        modeJeu=2 ;
                    }

                    else if ((sourisY>menu.boutonChargerPartieY) && (sourisY<menu.boutonChargerPartieY+menu.boutonHauteur) )
                    {
                        chargerPlateau(tableauPiece, J1, J2, positionJoueurY, positionJoueurX, modeJeu, joueur) ;
                        play = true ;
                        SDL_Delay(100) ;
                    }
                }

                else if ((sourisX>menu.boutonQuitterX) && (sourisX<menu.boutonQuitterX+menu.boutonLargeur)
                && (sourisY>menu.boutonQuitterY) && (sourisY<menu.boutonQuitterY+menu.boutonHauteur))
                        quit = true ; // on quitte le jeu
            }

            else
            {
                if ((sourisX>menu.boutonSauvegarderX) && (sourisX<menu.boutonSauvegarderX+menu.boutonLargeur)
                && (sourisY>menu.boutonSauvegarderY) && (sourisY<menu.boutonSauvegarderY+menu.boutonHauteur) )
                {
                    sauvegarderPlateau(tableauPiece, J1, J2, positionJoueurY, positionJoueurX, modeJeu, joueur) ;
                    apply_surface(0, 0, menu.imageSauvegarde, screen, NULL) ;
                    SDL_Flip(screen) ;
                    SDL_Delay(2000) ;
                }


                if ((sourisX<NB_CASES*CASE_HAUTEUR) && (sourisY<NB_CASES*CASE_HAUTEUR))
                {
                    int ligne = sourisY / CASE_HAUTEUR ;
                    int colonne = sourisX / CASE_HAUTEUR ;

                    if (verifierCase(positionJoueurY, positionJoueurX, ligne, colonne, tableauPiece) && tableauPiece[ligne][colonne] != -1 && tableauPiece[ligne][colonne] != -2)
                    {
                        if (joueur == -1)
                        {
                            deplacerPirate(positionJoueurY, positionJoueurX, ligne, colonne, tableauPiece, J1, screen, piece) ;
                            scoreJ1.str("");
                            scoreJ1 << J1.score;
                            joueur = -2 ; // changement du joueur qui doit jouer


                            SDL_Delay(100) ;

                            if (modeJeu==1)
                            {
                                afficherDecor(J1, J2, screen, imagePirateScore ,blanc , flag, menu ) ;
                                afficherBonus(J1, screen, bonus) ;
                                afficherBonus(J2, screen, bonus) ;
                                afficherScorePiece(J1, screen, piece) ;
                                afficherScorePiece(J2, screen, piece) ;


                                showMessageScreen(scoreJ1.str(),620, 390,score,FONT_SIZE,scoreNoir,screen);
                                showMessageScreen(scoreJ2.str(),850, 390,score,FONT_SIZE,scoreNoir,screen);


                                int ancienX= positionJoueurX;
                                int ancienY= positionJoueurY;
                                IA(J2, tableauPiece, positionJoueurX, positionJoueurY);
                                deplacerPirate(ancienY, ancienX, positionJoueurY, positionJoueurX, tableauPiece, J2, screen, piece );
                                joueur= -1 ;
                            }

                        }
                        else
                        {
                            deplacerPirate(positionJoueurY, positionJoueurX, ligne, colonne, tableauPiece, J2, screen, piece) ;
                            scoreJ2.str("");
                            scoreJ2 << J2.score;
                            joueur = -1 ; // changement du joueur qui doit jouer

                            SDL_Delay(100) ;

                        }
                    }
                }
            }
        }
        SDL_Delay(5) ;
        SDL_FreeSurface(screen) ;
    }


    SDL_Quit() ;
    return 0;
}

