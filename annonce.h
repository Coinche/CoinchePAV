#ifndef ANNONCE_H
#define ANNONCE_H

#include<vector>
#include "types.h"

class Annonce {
public:
	// les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes
	Hauteur const hauteur;
	Couleur const couleur;
	Annonce(Hauteur h, Couleur c);
	bool operator>( const Annonce& annonce); //on compare simplement les hauteurs des 2 annonces.
};

typedef std::vector<Annonce> Encheres;

#endif //ANNONCE_H
