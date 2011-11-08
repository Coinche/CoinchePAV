#ifndef ANNONCE_H
#define ANNONCE_H

#include "types.h"

class Annonce {
public:
	// les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes
	Hauteur const hauteur;
	Couleur const couleur;
	Annonce(Hauteur, Couleur);
	Annonce operator>(const Annonce&, const Annonce&); //on compare simplement les hauteurs des 2 annonces.
};

#endif //ANNONCE_H