#ifndef FENETRE_H_INCLUDED
#define FENETRE_H_INCLUDED

#include<string>
#include<iostream>
#include<fstream>
#include"IA.h"

const int largeurEcran = 1039 ; // définition de la largeur de l'écran
const int hauteurEcran = 650 ; // définition de la hauteur de l'écran
const int FONT_SIZE= 100 ;



struct Menu
{
    SDL_Surface *imageMenu ;
    SDL_Surface *imageSauvegarde ;
    SDL_Surface *bouton ;

    int boutonX ;
    int boutonLargeur ;
    int boutonHauteur ;

    int boutonJouerX ;
    int boutonJouerSeulY ;
    int boutonJouerDeuxY ;
    int boutonQuitterX ;
    int boutonQuitterY ;
    int boutonSauvegarderX ;
    int boutonSauvegarderY ;

    int boutonChargerPartieY ;

    SDL_Rect boutonJouerSeul ; //rectangle contenant je bouton JoueurSeul
    SDL_Rect boutonJouerDeux ;
    SDL_Rect boutonChargerPartie ;
    SDL_Rect boutonSauvegarder ;
    SDL_Rect boutonQuitter ;

};

void initialiserMenu(Menu &menu) ;
void afficherMenu(Menu menu, SDL_Surface* screen) ;


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) ;

void showMessageScreen(std::string message, int x, int y, TTF_Font* font, int FontSize, SDL_Color textColor, SDL_Surface* screen ) ;



void afficherPlateau(CasePiece &piece, SDL_Surface* screen, TGrille tableau) ;

void afficherScorePiece(Pirate joueur, SDL_Surface *screen,CasePiece piece);

void deplacerPirate(int &positionJoueurY, int &positionJoueurX, int &nouvelleLigne, int &nouvelleColonne, TGrille tableau, Pirate &joueur, SDL_Surface* screen, CasePiece piece) ;



void afficherBonus(Pirate joueur, SDL_Surface *screen, Bonus Bonus);

void afficherDecor(Pirate J1, Pirate J2, SDL_Surface* screen,SDL_Surface* imagePirate, SDL_Surface* blanc,SDL_Surface* flag, Menu menu);

void afficherPirate(Pirate joueur, int positionX, int positionY, SDL_Surface* screen) ;

void partieGagnee(Pirate joueurGagnant, bool &play,SDL_Surface* screen);



void sauvegarderPlateau(TGrille tableau, Pirate J1, Pirate J2, int positionY, int positionX, int modeJeu, int joueur) ;

void chargerPlateau(TGrille tableau, Pirate &J1, Pirate &J2, int &positionX, int &positionY, int &modeJeu, int &joueur) ;




















#endif // FENETRE_H_INCLUDED
