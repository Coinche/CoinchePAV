#ifndef ANNONCE_H
#define ANNONCE_H

#include <vector>
#include "types.h"

class Annonce {
public:
	// les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes
	Hauteur const hauteur;
	Couleur const couleur;
	Annonce(Hauteur h, Couleur c);
	bool operator>( const Annonce& annonce); //on compare simplement les hauteurs des 2 annonces.
};

//chaque joueur stocke la liste de ses annonces pendant les encheres ("boites d'encheres" du bridge)
typedef vector<Annonce> Encheres;

#endif //ANNONCE_H
