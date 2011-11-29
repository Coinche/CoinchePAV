#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "annonce.h"

class Joueur {
public:
	Annonce annoncer();
	Carte jouer(const Main& valides);
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main get_main() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	void recevoirMain(const Main& validesh );  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps

private:
	 //methode abstraite. pour un homme, c'est une methode vide.
	 //pour une IA, c'est la que se situent les algos.
	virtual Annonce reflechirEtAnnoncer();
	//methode abstraite. pour un homme, c'est une methode vide.
	 //pour une IA, c'est la que se situent les algos.
	virtual int reflechirEtJouer(const Main&);
	Main main;
};

#endif //JOUEUR_H
