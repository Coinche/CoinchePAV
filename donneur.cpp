#include "donneur.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "regles.h"

using namespace std;



void Donneur::init()
{
	premier=0;
	srand(time(NULL));
	scores[0]=0;
	scores[1]=0;
	scores_tmp[0]=0;
	scores_tmp[1]=0;
}

Donneur::Donneur(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3)
{
	init();
	set_joueurs(joueur0, joueur1, joueur2, joueur3);
}

void Donneur::set_joueurs(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3)
{
	joueurs[0] = joueur0;
	joueurs[1] = joueur1;
	joueurs[2] = joueur2;
	joueurs[3] = joueur3;
}

Main Donneur::get_main(int joueur)
{
	return joueurs[(premier+joueur)%4]->get_main();
}

void Donneur::jouerUnTour()
{
	distribuer();
	int joueurCourant=premier;
	
	//! Attention debug!!! FIXME
	encheres.push_back(Annonce(CAPOT, TREFLE));
	encheres.push_back(Annonce(PASSE, PIQUE));
	encheres.push_back(Annonce(PASSE, PIQUE));
	encheres.push_back(Annonce(PASSE, PIQUE));
	//!
	
	
	while(Regles::AnnoncesPossibles(encheres).first.size()!=0)
	{
		encheres.push_back(joueurs[joueurCourant]->annoncer(encheres));
		//donneurGraphique->rafraichir(encheres.back(), joueurCourant);
		if(joueurCourant == 3) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
	}
	atout = (encheres.end()-5)->get_couleur();
	compterLaBelote(joueurCourant-1);
	joueurCourant=premier;
	
	for(int pli=0; pli<8; pli++)
	{
		joueurCourant = jouerUnPli(joueurCourant);
	}
	scores_tmp[joueurCourant%2]+=10; //dix de der
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
	plisRamasses = jeuComplet;
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
		distrib[i].trierParCouleur();
		joueurs[(i+premier)%4]->recevoirMain(distrib[i]);
	}
}

int Donneur::jouerUnPli(int entame)
{
	int joueurCourant = entame;
	Pli pliEnCours;
	
	for(int i=0; i<4; i++)
	{
		pliEnCours.push_back(joueurs[joueurCourant]->jouer(atout, pliEnCours));
		
		plisRamasses.push_back(pliEnCours.back());
		//donneurGraphique->rafraichir(carteCourante, joueurCourant);
		if(joueurCourant == 3) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
	}
	
	int maitre_index = get_maitre(pliEnCours);
	
	if(maitre_index%2 == 0)
		scores_tmp[premier%2] += Regles::valeur(pliEnCours, atout);
	else
		scores_tmp[1 - premier%2] += Regles::valeur(pliEnCours, atout);
	
	return maitre_index;
	//donneurGraphique->ramasserPli();
}

int Donneur::get_maitre(const Pli& pliEnCours)
{
	Pli::const_iterator maitre=pliEnCours.begin();
	for(Pli::const_iterator it=pliEnCours.begin(); it < pliEnCours.end(); it++)
		if(Regles::comparer(*maitre,*it,atout)==0)
			maitre=it;
			
	return (maitre - pliEnCours.begin());
}

void Donneur::compter()
{
	int attaque = (premier + encheres.size() - 1) % 2;
	int defense = 1 - attaque;
	Hauteur pointsAnnonces = (encheres.end()-5)->get_hauteur();
	if(pointsAnnonces == CAPOT && scores_tmp[defense] == 0)
		scores[attaque] += pointsAnnonces;
	else if(pointsAnnonces == CAPOT && scores_tmp[defense] != 0)
		scores[defense] += pointsAnnonces;
	else if(pointsAnnonces != CAPOT && scores_tmp[attaque]>= pointsAnnonces)
		scores[attaque] += pointsAnnonces;
	else
		scores[defense] += pointsAnnonces;
	
	scores_tmp[0]=0;
	scores_tmp[1]=0;
}

void Donneur::compterLaBelote(int joueurCourant)
{
	for(int i = 0; i<4; i+=2)
		if(joueurs[(joueurCourant+i)%4]->get_main().contient(Carte(DAME,atout))
		&& joueurs[(joueurCourant+i)%4]->get_main().contient(Carte(ROI,atout))
		)
			scores_tmp[joueurCourant%2]+=20;
}