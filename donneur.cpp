#include "donneur.h"

void Donneur::jouerUnTour()
{
	melanger();
	distribuer();
	int joueurCourant=premier;
	while(encheresEnCours())
	{
		joueurs[joueurCourant]->annoncer();
		joueurCourant = (joueurCourant + 1 ) & 3; // incrementation modulo 4
	}
	joueurCourant=premier;
	for(int pli=0; pli<8; pli++)
	{
		joueurs[joueurCourant]->jouer();
}