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
        plisRamasses.clear();
}

Donneur::Donneur()
{
    init();
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

void Donneur::set_donneurGraphique(DonneurGraphique *_donneurG)
{
    donneurGraphique=_donneurG;
}

Main Donneur::get_main(int joueur)
{
	return joueurs[(premier+joueur)%4]->get_main();
}

Couleur Donneur::get_atout()
{
    return atout;
}

Pli Donneur::get_pliEnCours()
{
    return pliEnCours;
}

Encheres Donneur::get_encheres()
{
    return encheres;
}

void Donneur::jouerUnePartie()
{
    init();
    while(scores[0]<=100 && scores[1]<=100)
    {
        donneurGraphique->init_game();
        donneurGraphique->afficherScores(scores[0],scores[1]);
        jouerUnTour();
        premier = (premier + 1) % 4;
        scores_tmp[0]=0;
        scores_tmp[1]=0;
        encheres.clear();
    }
    donneurGraphique->afficherScores(scores[0],scores[1]);
}

void Donneur::jouerUnTour()
{
	distribuer();
	int joueurCourant=premier;
        encheres.clear();

	while(Regles::AnnoncesPossibles(encheres).first.size()!=0)
	{
		encheres.push_back(joueurs[joueurCourant]->annoncer(encheres));
                donneurGraphique->afficherAnnonce(joueurCourant, encheres.back());
		if(joueurCourant == 3) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
	}
        if(encheres.size() == 4) return;

        attaque = (premier + encheres.size() - 1) % 2;
        defense = 1 - attaque;

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
        if(plisRamasses.size() != 32) //derniere partie non jouee, on melange
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
        plisRamasses.clear();
}

int Donneur::jouerUnPli(int entame)
{
	int joueurCourant = entame;
        pliEnCours.clear();

	for(int i=0; i<4; i++)
	{
		pliEnCours.push_back(joueurs[joueurCourant]->jouer(atout, pliEnCours));

		plisRamasses.push_back(pliEnCours.back());
                donneurGraphique->afficherCarte(joueurCourant,pliEnCours.back());
		if(joueurCourant == 3) joueurCourant = 0; else joueurCourant++; // incrementation modulo 4
	}

        donneurGraphique->ramasserPli();

        int maitre_index = (joueurCourant + get_maitre(pliEnCours))%4;

        if(maitre_index%2 == 0)
                scores_tmp[attaque] += Regles::valeur(pliEnCours, atout);
	else
                scores_tmp[defense] += Regles::valeur(pliEnCours, atout);

	return maitre_index;
}

int Donneur::get_maitre(const Pli& pliEnCours)
{
	Pli::const_iterator maitre=pliEnCours.begin();
	for(Pli::const_iterator it=pliEnCours.begin(); it < pliEnCours.end(); it++)
                if(Regles::comparer(*maitre,*it,atout) == 0 )
			maitre=it;

        int tmp = (int)(maitre - pliEnCours.begin());
        return tmp;
}

void Donneur::compter()
{
	Hauteur pointsAnnonces = (encheres.end()-5)->get_hauteur();
	if(pointsAnnonces == CAPOT && scores_tmp[defense] == 0)
		scores[attaque] += pointsAnnonces;
	else if(pointsAnnonces == CAPOT && scores_tmp[defense] != 0)
		scores[defense] += pointsAnnonces;
	else if(pointsAnnonces != CAPOT && scores_tmp[attaque]>= pointsAnnonces)
		scores[attaque] += pointsAnnonces;
	else
		scores[defense] += pointsAnnonces;
}

void Donneur::compterLaBelote(int joueurCourant)
{
	for(int i = 0; i<4; i+=2)
		if(joueurs[(joueurCourant+i)%4]->get_main().contient(Carte(DAME,atout))
		&& joueurs[(joueurCourant+i)%4]->get_main().contient(Carte(ROI,atout))
		)
			scores_tmp[joueurCourant%2]+=20;
}
