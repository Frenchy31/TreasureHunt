


#include "fenetre.h"




using namespace std ;

void initialiserMenu(Menu &menu)
{
    menu.imageMenu = SDL_LoadBMP("images/menu.bmp") ;
    menu.bouton = SDL_LoadBMP("images/boutons.bmp") ;
    menu.imageSauvegarde=SDL_LoadBMP("images/partieSauvegardee.bmp") ;
    Uint32 colorkey = SDL_MapRGB( menu.bouton->format, 0, 255, 255 ); // on définit la couleur qu'il faudra rendre transparente dans les images qu'on va charger
    SDL_SetColorKey(menu.bouton, SDL_SRCCOLORKEY, colorkey) ;

    menu.boutonX = 103 ;
    menu.boutonLargeur = 277 ;
    menu.boutonHauteur = 74 ;

    menu.boutonJouerX = largeurEcran-menu.boutonLargeur-50 ;
    menu.boutonJouerSeulY = 150 ;
    menu.boutonJouerDeuxY = 275 ;
    menu.boutonChargerPartieY = 400 ;
    menu.boutonQuitterX = 20 ;
    menu.boutonQuitterY = hauteurEcran-100 ;
    menu.boutonSauvegarderX = 20 ;
    menu.boutonSauvegarderY = hauteurEcran-120 ;


    menu.boutonJouerSeul.x = menu.boutonX ;
    menu.boutonJouerSeul.y = 0;
    menu.boutonJouerSeul.w = menu.boutonLargeur ;
    menu.boutonJouerSeul.h = menu.boutonHauteur ;

    menu.boutonJouerDeux.x = menu.boutonX ;
    menu.boutonJouerDeux.y = 83 ;
    menu.boutonJouerDeux.w = menu.boutonLargeur ;
    menu.boutonJouerDeux.h = menu.boutonHauteur ;

    menu.boutonChargerPartie.x = menu.boutonX ;
    menu.boutonChargerPartie.y = 250 ;
    menu.boutonChargerPartie.w = menu.boutonLargeur ;
    menu.boutonChargerPartie.h = menu.boutonHauteur ;

    menu.boutonSauvegarder.x = menu.boutonX ;
    menu.boutonSauvegarder.y = 335 ;
    menu.boutonSauvegarder.w = menu.boutonLargeur ;
    menu.boutonSauvegarder.h = menu.boutonHauteur ;


    menu.boutonQuitter.x = menu.boutonX ;
    menu.boutonQuitter.y = 165 ;
    menu.boutonQuitter.w = menu.boutonLargeur ;
    menu.boutonQuitter.h = menu.boutonHauteur ;
}

void afficherMenu(Menu menu, SDL_Surface* screen)
{
    apply_surface(0, 0, menu.imageMenu, screen, NULL) ; // affichage de l'image de fond du menu
    apply_surface(menu.boutonJouerX, menu.boutonJouerSeulY, menu.bouton, screen, &menu.boutonJouerSeul) ; // affiche le boutton jouer seul
    apply_surface(menu.boutonJouerX, menu.boutonJouerDeuxY, menu.bouton, screen, &menu.boutonJouerDeux) ; // affichage du boutton jouer à deux
    apply_surface(menu.boutonQuitterX, menu.boutonQuitterY, menu.bouton, screen, &menu.boutonQuitter) ; // affiche le boutton quitter
    apply_surface(menu.boutonJouerX, menu.boutonChargerPartieY,menu.bouton, screen, &menu.boutonChargerPartie) ; // afficher le bouton CHarger Partie
}



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) //fonction qui permet d'afficher des surfaces
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, clip, destination, &offset );
}


void showMessageScreen(string message,int x,int y, TTF_Font *font,int fontSize,SDL_Color textColor,SDL_Surface* screen) //Fonction qui permet d'afficher des messages
{
    string mot="";
    string space=" ";
    int i=0,j;
    SDL_Surface *mes=NULL ;

    j = message.find(space) ;
    while( j != string::npos )
    {
        mot=message.substr(i,j-i);
        if(mot != "")
        {
        mes = TTF_RenderText_Solid(font,mot.c_str(),textColor);
        apply_surface(x,y,mes,screen,NULL);
        x+=mes->w;
        SDL_FreeSurface(mes);
        }
    x+=fontSize;
    i=j+1;
    j = message.find(space,i);
    }

    mot=message.substr(i);
    mes=TTF_RenderText_Solid(font,mot.c_str(),textColor);
    apply_surface(x,y,mes,screen,NULL);
    SDL_FreeSurface(mes);
}



void afficherPlateau( CasePiece &piece, SDL_Surface* screen,TGrille tableau)
{ // fonction permettant d'afficher le tableau ainsi que les différentes images se trouvant autour

    for (int ligne=0 ; ligne<NB_CASES; ligne++)
    {
        for (int colonne=0 ; colonne<NB_CASES ; colonne++)
        {

        switch (tableau[ligne][colonne])
        {
        case 0 : piece.rectangle = piece.pieceVide ; break ;
        case 1 : piece.rectangle = piece.piece100 ; break ;
        case 2 : piece.rectangle = piece.piece50 ; break ;
        case 3 : piece.rectangle = piece.piece30 ; break ;
        case 4 : piece.rectangle = piece.piece20 ; break ;
        case 5 : piece.rectangle = piece.piece10 ; break ;
        default : piece.rectangle = piece.pieceVide ; break ;
        //case -1 : piece.rectangle = J1.imageJoueurPlateau ; break ;
        //case -2 : piece.rectangle = J2.imageJoueurPlateau ; break ;
        }
        apply_surface(colonne*CASE_HAUTEUR, ligne*CASE_HAUTEUR, piece.image2, screen, &piece.rectangle) ;
        }
    }
}

void afficherScorePiece(Pirate joueur, SDL_Surface *screen,CasePiece piece) //fonction qui affiche l'images de la dernière pièce prise par le joueur
{
    switch(joueur.dernierePiece)
    {
        case 1 : piece.rectangle=piece.piece100 ; break ;
        case 2 : piece.rectangle=piece.piece50 ; break ;
        case 3 : piece.rectangle=piece.piece30 ; break;
        case 4 : piece.rectangle=piece.piece20 ; break;
        case 5 : piece.rectangle=piece.piece10 ; break;
        case 0 : piece.rectangle=piece.pieceVide ; break;
    }

    if(joueur.indice==-2)
                    apply_surface(850,105,piece.image2,screen, &piece.rectangle);
                 else
                    apply_surface(625,105,piece.image2,screen, &piece.rectangle);


}




void deplacerPirate(int &positionJoueurY, int &positionJoueurX, int &nouvelleLigne, int &nouvelleColonne,
TGrille tableau, Pirate &joueur, SDL_Surface *screen, CasePiece piece)
{ // fonction pour déplacer le pirate

    tableau[positionJoueurY][positionJoueurX] = 0 ;
    int deplacementY = positionJoueurY*CASE_HAUTEUR ;
    int deplacementX = positionJoueurX*CASE_HAUTEUR ;
    positionJoueurY = nouvelleLigne ;
    positionJoueurX = nouvelleColonne ;
    int cpt = 0 ;

    while (deplacementX!=positionJoueurX*CASE_HAUTEUR || deplacementY!=positionJoueurY*CASE_HAUTEUR)
    {
        afficherPlateau(piece, screen, tableau) ;

        if (deplacementX<positionJoueurX*CASE_HAUTEUR)
        {
            deplacementX+=2;
            mouvementDroite(joueur, cpt, deplacementY, deplacementX, screen);

        }
        else if (deplacementX>positionJoueurX*CASE_HAUTEUR)
        {
            deplacementX-=2 ;
            mouvementGauche(joueur, cpt, deplacementY, deplacementX, screen);
        }
        if (deplacementY<positionJoueurY*CASE_HAUTEUR)
        {
            deplacementY+=2 ;
            mouvementBas(joueur, cpt, deplacementY, deplacementX, screen);
        }
        else if (deplacementY>positionJoueurY*CASE_HAUTEUR)
        {
            deplacementY-=2 ;
            mouvementHaut(joueur, cpt, deplacementY, deplacementX, screen);
        }

        cpt=(cpt+1)%3;


        SDL_Delay(2) ;
        SDL_Flip(screen) ;
    }

    int piecePrise = tableau[positionJoueurY][positionJoueurX] ;
    scorePirate(joueur, valeurPiece(piecePrise)) ;
    bonusPirate(joueur, piecePrise) ;

    joueur.dernierePiece=piecePrise ;

}

void afficherBonus(Pirate joueur, SDL_Surface *screen, Bonus bonus) //fonction qui affiche les images des bonus en fonction du niveaux de bonus
{
    switch (joueur.bonus)
    {
        case 0 : bonus.surface=bonus.bonus0 ; break ;
        case 1 : bonus.surface=bonus.bonus1 ; break ;
        case 2 : bonus.surface=bonus.bonus2 ; break ;
        case 3 : bonus.surface=bonus.bonus3 ; break ;
        case 4 : bonus.surface=bonus.bonus4 ; break ;
    }
    if(joueur.indice==-1)
        apply_surface(565, 110, bonus.surface, screen, NULL) ;
    else
        apply_surface(790, 110, bonus.surface, screen, NULL) ;
}

void afficherDecor(Pirate J1, Pirate J2, SDL_Surface* screen, SDL_Surface* imagePirate, SDL_Surface* blanc,SDL_Surface* flag, Menu menu)
{
    apply_surface(0, 0, blanc, screen, NULL) ;
    // On affiche les 4 drapeaux :
    apply_surface(450, hauteurEcran-120, flag, screen, NULL) ;
    apply_surface(600, hauteurEcran-120, flag, screen, NULL) ;
    apply_surface(750, hauteurEcran-120, flag, screen, NULL) ;
    apply_surface(900, hauteurEcran-120, flag, screen, NULL) ;
    // On affiche les 2 pirates sur le côté au dessus du score:
    apply_surface(610, 0, imagePirate, screen, &J1.imageJoueurScore) ;
    apply_surface(850, 0, imagePirate, screen, &J2.imageJoueurScore) ;

    apply_surface(menu.boutonSauvegarderX, menu.boutonSauvegarderY, menu.bouton, screen, &menu.boutonSauvegarder);

}

void afficherPirate(Pirate joueur, int positionX, int positionY ,SDL_Surface* screen)
{
    apply_surface(positionY*CASE_HAUTEUR, positionX*CASE_HAUTEUR, joueur.imagePirate, screen, &joueur.imageJoueurPlateau);
}

void partieGagnee(Pirate joueurGagnant, bool &play, SDL_Surface* screen)
{
    play=false;
    apply_surface(0, 0, joueurGagnant.imageVictoire , screen, NULL) ;
    SDL_Flip(screen);
    SDL_Delay(2000);
}



void sauvegarderPlateau(TGrille tableau, Pirate J1, Pirate J2, int positionY, int positionX, int modeJeu, int joueur)
{
    fstream f ;
    f.open ("fichierSauv.sv",ios::out) ;
    if ( f.fail())
        cout << "ouverture en écriture impossible " << endl ;

    for (int ligne=0 ; ligne<NB_CASES ; ligne++)
    {
        for (int colonne=0 ; colonne<NB_CASES ; colonne++)
        {
            f << tableau[ligne][colonne] << " " ;
        }
        f << endl ;
    }
    // position du pirate
    f << positionY << " " << positionX << endl ;
    f << modeJeu << endl ;
    f << joueur << endl ;
    // J1
    f <<  J1.score << " " << J1.bonus << " " << J1.dernierePiece << endl ;
    // J2
    f <<  J2.score << " " << J2.bonus << " " << J2.dernierePiece << endl ;

    f.close() ;
}

void chargerPlateau(TGrille tableau, Pirate &J1, Pirate &J2, int &positionY, int &positionX, int &modeJeu, int &joueur)
{
    fstream f ;
    f.open("fichierSauv.sv", ios::in) ;
    if (f.fail())
        cout << "ouverture en lecture impossible " << endl ;

    for (int ligne=0 ; ligne<NB_CASES ; ligne++ )
    {
        for (int colonne=0 ; colonne<NB_CASES ; colonne++ )
        {
            f >> tableau[ligne][colonne] ;
        }
    }

    f >> positionY ;
    f >> positionX ;
    f >> modeJeu ;
    f >> joueur ;

    // J1
    f >> J1.score ;
    f >> J1.bonus ;
    f >> J1.dernierePiece ;
    //J2

    f >> J2.score ;
    f >> J2.bonus ;
    f >> J2.dernierePiece ;

    f.close() ;
}
