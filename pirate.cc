#include "pirate.h"
#include "SDL_ttf.h"
using namespace std ;

void
applySurface(int x, int y, SDL_Surface* source,
         SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}


SDL_Surface *
loadImage(string filename)
{
     return SDL_DisplayFormat(IMG_Load( filename.c_str()));
}

// -- loadImageWithColorKey ---------------------
// chargement d'une image
// * paramètres entrées :
// - "filename" : nom de l'image
// - "r,g,b"    : couleur de la ColorKey; cette
//   couleur devient transparente !
// * paramètre de sortie : SDL_Surface contenant
//   l'image.
// ----------------------------------------------

SDL_Surface *
loadImageWithColorKey(string filename, int r, int g, int b)
{
    SDL_Surface* optimizedImage;
    optimizedImage = SDL_DisplayFormat(IMG_Load( filename.c_str()));
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY,
            SDL_MapRGB(optimizedImage->format, r, g, b));
    return optimizedImage;
}

// -- applySurface ------------------------------
// c'est le copier-coller d'une surface sur une
// autre : on colle le rectangle "clip" de "source"
// sur "destination" à partir de "x,y"/home/aubin/Documents/Projets Codeblocks/TP12/
// ----------------------------------------------


void initialiserPirates(Pirate &J1, Pirate &J2)
{
        /* *************** Nom de la fonction ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
    ∗ NOM_FONCTION          initialiserPirates                         *
    ****************** Auteur , Dates ***************************
    ∗Nom/Date : Puyoou Aubin ; version 7 : 14/12          *
    ∗∗∗∗∗∗∗*∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
    ∗ Fonction qui initialise toutes les variables des joueurs
    ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Entrées ***********************************
    ∗ La fonction prend en paramètres les deux pirates joueurs
    ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Sorties *******************************
    ∗ La fonction ne renvoit rien (VOID) Elle initialise les scores,
     le bonus, l'indice, la derniere piece prise, les rectangles pour
     l'animation et les images au dessus du score, l'image sur
     le plateau, les images de victoire et chacun des rectangles pour
     les animations des joueurs,
    ************************************************************/
    //score des joueurs
    J1.score = 0 ;
    J2.score = 0 ;

    // bonus des joueurs
    J1.bonus=0;
    J2.bonus=0;
    // Numéro de joueur des pirates pour les reconnaitres
    J1.indice = -1 ;
    J2.indice = -2 ;

    // Dernière pièce prise par les pirates
    J1.dernierePiece=0;
    J2.dernierePiece=0;

    // rectangle du joueurs 1
    J1.imageJoueurScore.x = 0 ;
    J1.imageJoueurScore.y = 0 ;
    J1.imageJoueurScore.w = 100 ;
    J1.imageJoueurScore.h = 100 ;

    // rectangle du joueurs 2
    J2.imageJoueurScore.x =100 ;
    J2.imageJoueurScore.y = 0 ;
    J2.imageJoueurScore.w = 100 ;
    J2.imageJoueurScore.h = 100 ;


    // chargement des images de victoire
    J1.imageVictoire = SDL_LoadBMP("images/victoireJ1.bmp");
    J2.imageVictoire = SDL_LoadBMP("images/victoireJ2.bmp");



    //-----------------------------------
    //-----Sprite du mouvement
    //-----------------------------------
    //Joueur 1 - Chargement des sprites quand le pirate se deplace vers le bas
    J1.lecturebas01.x=9;
    J1.lecturebas01.y=22;
    J1.lecturebas01.w=largeurPirate;
    J1.lecturebas01.h=hauteurPirate;

    J1.lecturebas02.x=79;
    J1.lecturebas02.y=22;
    J1.lecturebas02.w=largeurPirate;
    J1.lecturebas02.h=hauteurPirate;

    J1.lecturebas03.x=149;
    J1.lecturebas03.y=22;
    J1.lecturebas03.w=largeurPirate;
    J1.lecturebas03.h=hauteurPirate;
    //Joueur 1 - Chargement des sprites quand le pirate se deplace vers la gauche
    J1.lecturegauche01.x=9;
    J1.lecturegauche01.y=92;
    J1.lecturegauche01.w=largeurPirate;
    J1.lecturegauche01.h=hauteurPirate;

    J1.lecturegauche02.x=79;
    J1.lecturegauche02.y=92;
    J1.lecturegauche02.w=largeurPirate;
    J1.lecturegauche02.h=hauteurPirate;

    J1.lecturegauche03.x=149;
    J1.lecturegauche03.y=92;
    J1.lecturegauche03.w=largeurPirate;
    J1.lecturegauche03.h=hauteurPirate;

    //Joueur 1 - Chargement des sprites quand le pirate se deplace vers le haut
    J1.lecturehaut01.x=9;
    J1.lecturehaut01.y=232;
    J1.lecturehaut01.w=largeurPirate;
    J1.lecturehaut01.h=hauteurPirate;

    J1.lecturehaut02.x=79;
    J1.lecturehaut02.y=232;
    J1.lecturehaut02.w=largeurPirate;
    J1.lecturehaut02.h=hauteurPirate;

    J1.lecturehaut03.x=149;
    J1.lecturehaut03.y=232;
    J1.lecturehaut03.w=largeurPirate;
    J1.lecturehaut03.h=hauteurPirate;

    //Joueur 1 - Chargement des sprites quand le pirate se deplace vers la droite
    J1.lecturedroite01.x=9;
    J1.lecturedroite01.y=162;
    J1.lecturedroite01.w=largeurPirate;
    J1.lecturedroite01.h=hauteurPirate;

    J1.lecturedroite02.x=79;
    J1.lecturedroite02.y=162;
    J1.lecturedroite02.w=largeurPirate;
    J1.lecturedroite02.h=hauteurPirate;

    J1.lecturedroite03.x=149;
    J1.lecturedroite03.y=162;
    J1.lecturedroite03.w=largeurPirate;
    J1.lecturedroite03.h=hauteurPirate;

    //Joueur 2 - Chargement des sprites quand le pirate se deplace vers le bas
    J2.lecturebas01.x=40;
    J2.lecturebas01.y=22;
    J2.lecturebas01.w=largeurPirate;
    J2.lecturebas01.h=hauteurPirate;

    J2.lecturebas02.x=112;
    J2.lecturebas02.y=23;
    J2.lecturebas02.w=largeurPirate;
    J2.lecturebas02.h=hauteurPirate;

    J2.lecturebas03.x=184;
    J2.lecturebas03.y=22;
    J2.lecturebas03.w=largeurPirate;
    J2.lecturebas03.h=hauteurPirate;
    //Joueur 2 - Chargement des sprites quand le pirate se deplace vers la gauche
    J2.lecturegauche01.x=40;
    J2.lecturegauche01.y=93;
    J2.lecturegauche01.w=largeurPirate;
    J2.lecturegauche01.h=hauteurPirate;

    J2.lecturegauche02.x=112;
    J2.lecturegauche02.y=93;
    J2.lecturegauche02.w=largeurPirate;
    J2.lecturegauche02.h=hauteurPirate;

    J2.lecturegauche03.x=184;
    J2.lecturegauche03.y=93;
    J2.lecturegauche03.w=largeurPirate;
    J2.lecturegauche03.h=hauteurPirate;
    //Joueur 2 - Chargement des sprites quand le pirate se deplace vers le haut
    J2.lecturehaut01.x=40;
    J2.lecturehaut01.y=235;
    J2.lecturehaut01.w=largeurPirate;
    J2.lecturehaut01.h=hauteurPirate;

    J2.lecturehaut02.x=112;
    J2.lecturehaut02.y=235;
    J2.lecturehaut02.w=largeurPirate;
    J2.lecturehaut02.h=hauteurPirate;

    J2.lecturehaut03.x=184;
    J2.lecturehaut03.y=235;
    J2.lecturehaut03.w=largeurPirate;
    J2.lecturehaut03.h=hauteurPirate;
    //Joueur 2 - Chargement des sprites quand le pirate se deplace vers la droite
    J2.lecturedroite01.x=40;
    J2.lecturedroite01.y=164;
    J2.lecturedroite01.w=largeurPirate;
    J2.lecturedroite01.h=hauteurPirate;

    J2.lecturedroite02.x=112;
    J2.lecturedroite02.y=164;
    J2.lecturedroite02.w=largeurPirate;
    J2.lecturedroite02.h=hauteurPirate;

    J2.lecturedroite03.x=184;
    J2.lecturedroite03.y=164;
    J2.lecturedroite03.w=largeurPirate;
    J2.lecturedroite03.h=hauteurPirate;

    //Chargement de l'image des pirates sur le plateau
    J1.imagePirate=loadImageWithColorKey("images/PirateVert.bmp", 255, 0, 0);
    J2.imagePirate=loadImageWithColorKey("images/PirateNoir.bmp", 49, 213, 56);


    //---------------------
        // rectangle contenant le pirate Vert attribué au joueur 1
    J1.imageJoueurPlateau.x = J1.lecturebas01.x ;
    J1.imageJoueurPlateau.y = J1.lecturebas01.y ;
    J1.imageJoueurPlateau.w = CASE_HAUTEUR ;
    J1.imageJoueurPlateau.h = CASE_HAUTEUR ;

    // rectangle contenant le pirate Rouge attribué au Joueur 2
    J2.imageJoueurPlateau.x = J2.lecturebas01.x ;
    J2.imageJoueurPlateau.y = J2.lecturebas01.y ;
    J2.imageJoueurPlateau.w = CASE_HAUTEUR ;
    J2.imageJoueurPlateau.h = CASE_HAUTEUR ;


}

void chargerImageBonus(Bonus &bonus)
{
    bonus.bonus0 = loadImageWithColorKey("bonus3.bmp", 255,255,255) ;
    bonus.bonus1 = loadImageWithColorKey("bonus4.bmp", 255,255,255) ;
    bonus.bonus2 = loadImageWithColorKey("bonus5.bmp", 255,255,255) ;
    bonus.bonus3 = loadImageWithColorKey("bonus6.bmp", 255,255,255) ;
    bonus.bonus4 = loadImageWithColorKey("bonus7.bmp", 255,255,255) ;
}

void scorePirate(Pirate &joueur, int piece)
{
    joueur.score+=piece ;
}

bool testPartieGagnee(Pirate joueur)
{
    bool victoire = false  ;
    if (joueur.score>=500)
    {
        victoire = true ;
    }

    return victoire ;
}


void bonusPirate(Pirate &joueur, int piece)
{

    if (joueur.dernierePiece==piece)
    {
        joueur.bonus++;
        if(joueur.bonus>4)
            joueur.bonus=0;
        switch(joueur.bonus)
        {
        case 0: ; break;
        case 1: joueur.score+=10; break;
        case 2: joueur.score+=20; break;
        case 3: joueur.score+=40; break;
        case 4: joueur.score+=80; break;
        }
    }
    else
        joueur.bonus=0;

}

void mouvementBas(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen)
{
    switch(cpt)
    {
        case 0:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturebas01);break;
        case 1:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturebas02);break;
        case 2:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturebas03);break;
    }

}

void mouvementGauche(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen)
{
    switch(cpt)
    {
        case 0:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturegauche01);break;
        case 1:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturegauche02);break;
        case 2:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturegauche03);break;
    }
}

void mouvementHaut(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen)
{
    switch(cpt)
    {
        case 0:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturehaut01);break;
        case 1:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturehaut02);break;
        case 2:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturehaut03);break;
    }

}

void mouvementDroite(Pirate joueur, int cpt, int positionY,int positionX, SDL_Surface* screen)
{
    switch(cpt)
    {
        case 0:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturedroite01);break;
        case 1:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturedroite02);break;
        case 2:applySurface(positionX,positionY,joueur.imagePirate,screen,&joueur.lecturedroite03);break;
    }
}


