#ifndef ANNONCE_H
#define ANNONCE_H

#include "types.h"

class Annonce {
public:
	// les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes
	Hauteur const hauteur;
	Couleur const couleur;
	Annonce(Hauteur h, Couleur c);
	bool operator>( const Annonce& annonce); //on compare simplement les hauteurs des 2 annonces.
};

#endif //ANNONCE_H
