#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "annonce.h"

class Joueur {
public:
	Annonce annoncer();
	Carte jouer();
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	const Main main();  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	
private:
	 //methode abstraite. pour un homme, il s'agit juste d'appeler JoueurGraphique::jouer().
	 //pour une IA, c'est la que se situe les algos.
	virtual Carte reflechir() = 0;
	Main main;
	JoueurGraphique* joueurGraphique;
};

#endif //JOUEUR_H