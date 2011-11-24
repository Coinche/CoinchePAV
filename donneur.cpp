#include "donneur.h"

void Donneur::jouerUnTour()
{
	melanger();
	distribuer();
	int joueurCourant=premier;
	Annonce annonceCourante(PASSE,COEUR);
	Annonce annonceProposee;
	while(encheresEnCours())
	{
		annonceCourante = joueurs[joueurCourant]->annoncer();
		donneurGraphique->rafraichir(annonceCourante, joueurCourant);
		joueurCourant = (joueurCourant + 1 ) & 3; // incrementation modulo 4
	}
	joueurCourant=premier;
	Carte carteCourante;
	for(int pli=0; pli<8; pli++)
	{
		for(int i=0; i<4; i++)
		{
			carteCourante = joueurs[joueurCourant]->jouer();
			donneurGraphique->rafraichir(carteCourante, joueurCourant);
			joueurCourant = (joueurCourant + 1 ) & 3; // incrementation modulo 4
		}
		
	}
}