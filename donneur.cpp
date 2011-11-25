#include "donneur.h"
#include <iostream>

using namespace std;

Donneur::Donneur(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3)
{
	joueurs[0]=joueur0;
	joueurs[1]=joueur1;
	joueurs[2]=joueur2;
	joueurs[3]=joueur3;
	premier=0;
}

void Donneur::jouerUnTour()
{
	melanger();
	distribuer();
	int joueurCourant=premier;
	while(encheresEnCours())
	{
		encheres.push_back(joueurs[joueurCourant]->annoncer());
		//donneurGraphique->rafraichir(encheres.back(), joueurCourant);
		if(joueurCourant == 4) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
		cout << joueurCourant << endl;
	}
	/*joueurCourant=premier;
	Carte carteCourante;
	for(int pli=0; pli<8; pli++)
	{
		for(int i=0; i<4; i++)
		{
			carteCourante = joueurs[joueurCourant]->jouer();
			donneurGraphique->rafraichir(carteCourante, joueurCourant);
			joueurCourant = (joueurCourant + 1 ) % 4; // incrementation modulo 4
		}
		
	}*/
}

void Donneur::melanger(){}
void Donneur::distribuer(){}

bool Donneur::encheresEnCours()
{
	bool encheresFinies=true;
	int size = encheres.size();
	if(size<4)
		return true;
	else
	{
		cout << "coucou" << endl;
		for(int i=size-4; i<=size; i++)
		{
			if(encheres[i].get_hauteur() != PASSE)
				encheresFinies = false;
		}
		return encheresFinies;
	}
}
