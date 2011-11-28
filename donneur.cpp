#include "donneur.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "regles.h"

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
	distribuer();
	int joueurCourant=premier;
	while(encheresEnCours())
	{
		encheres.push_back(joueurs[joueurCourant]->annoncer());
		//donneurGraphique->rafraichir(encheres.back(), joueurCourant);
		if(joueurCourant == 4) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
		cout << joueurCourant << endl;
	}
	//! Attention debug!!! FIXME
	encheres.push_back(Annonce(CAPOT, TREFLE));
	//!
	atout = encheres.back().get_couleur();
	
	for(int pli=0; pli<8; pli++)
	{
		jouerUnPli();
	}
	compter();
}

void Donneur::melanger()
{
	plisRamasses.clear();
	Pli jeuComplet;
	//on genere un jeu de 32 cartes
	for(int i=0; i<4; i++)
		for(int j=0; j<8; j++)
			jeuComplet.push_back(Carte(int2Valeur(j),int2Couleur(i)));//!DEGUEU
	
	random_shuffle(jeuComplet.begin(), jeuComplet.end());
	copy(jeuComplet.begin(), jeuComplet.end(), plisRamasses.begin());
}

void Donneur::distribuer()
{
	Main distrib[4];
	if(plisRamasses.size() != 8) //derniere partie non jouee, on melange
		melanger();
	rotate(plisRamasses.begin(), plisRamasses.begin()+1+rand()%31, plisRamasses.end()); //on coupe par permutation circulaire
	for(int i=0; i<8;i++)
	{
		for(int j=0; j<4; j++)
			distrib[j].push_back(plisRamasses[4*i+j]);
	}
	for(int i=0; i<4; i++)
	{
		sort(distrib[i].begin(), distrib[i].end(), Carte::triParCouleur);
		joueurs[(i+premier)%4]->recevoirMain(distrib[i]);
	}
}

bool Donneur::encheresEnCours() const
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

void Donneur::jouerUnPli()
{
	int joueurCourant = premier;
	Pli pliEnCours;
	
	for(int i=0; i<4; i++)
	{
		Main valide = Regles::valides(
			joueurs[joueurCourant]->get_main(),
			encheres.back().get_couleur(),
			pliEnCours
		);
		pliEnCours.push_back(joueurs[joueurCourant]->jouer(valide));
		
		
		
		cout << joueurCourant << " : " << pliEnCours.back().get_valeur() << " " <<pliEnCours.back().get_couleur() << endl;
		
		plisRamasses.push_back(pliEnCours.back());
		//donneurGraphique->rafraichir(carteCourante, joueurCourant);
		if(joueurCourant == 4) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
	}
	
	Pli::iterator maitre=pliEnCours.begin();
	
	for(Pli::iterator it=pliEnCours.begin(); it < pliEnCours.end(); it++)
		if(Regles::comparer(*maitre,*it,atout)==0)
			maitre=it;
			
	if(maitre == pliEnCours.begin() || maitre == pliEnCours.begin() + 2)
		scores_tmp[premier%2] += Regles::valeur(pliEnCours, atout);
	else
		scores_tmp[1 - premier%2] += Regles::valeur(pliEnCours, atout);
		
	//donneurGraphique->ramasserPli();
}

void Donneur::compter()
{
	int attaque = (premier + encheres.size() - 1) % 2;
	int pointsAnnonces = (encheres.end()-4)->get_hauteur();
	if(scores_tmp[attaque]>= pointsAnnonces)
		scores[attaque] += pointsAnnonces;
	else
		scores[1-attaque] += pointsAnnonces;
	
	scores_tmp[0]=scores_tmp[1]=0;
}
