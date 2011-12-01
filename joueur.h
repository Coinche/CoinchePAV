#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include "annonce.h"

class Joueur {
public:
	Annonce annoncer(const Encheres &encheres);
	Carte jouer(Couleur atout, const Pli &pliEnCours);
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main get_main() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
        virtual void recevoirMain(const Main&);  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	
private:
	 //methode abstraite. pour un homme, c'est une methode vide.
	 //pour une IA, c'est la que se situent les algos.
        virtual Annonce reflechirEtAnnoncer(const  std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles ) = 0;
	//methode abstraite. pour un homme, c'est une methode vide.
	 //pour une IA, c'est la que se situent les algos.
        virtual Carte reflechirEtJouer(const Main &valides) = 0; //renvoie la carte (dans valides)
protected:
        Main main;
};

#endif //JOUEUR_H
