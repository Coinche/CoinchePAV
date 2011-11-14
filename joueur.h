#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "annonce.h"

class Joueur {
public:
	Annonce annoncer();
	Carte jouer();
	
	Encheres encheres() const;
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main mmain() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	void recevoirMain(const Main&);  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	
private:
	 //methode abstraite. pour un homme, il s'agit juste d'appeler JoueurGraphique::jouer().
	 //pour une IA, c'est la que se situent les algos.
	virtual Annonce reflechirEtAnnoncer() = 0;
	//methode abstraite. pour un homme, il s'agit juste d'appeler JoueurGraphique::jouer().
	 //pour une IA, c'est la que se situent les algos.
	virtual Carte reflechirEtJouer() = 0;
	Encheres encheres;
	Main mmain;
	JoueurGraphique* joueurGraphique;
};

#endif //JOUEUR_H