#ifndef CARTE_H
#define CARTE_H

#include "types.h"

class Carte {
public:
	// les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes
	Valeur const valeur;
	Couleur const couleur;
	Carte(Valeur, Couleur); //constructeur
};

// Pli et Main sont differents semantiquement (dans le diagramme UML), meme si en fait derriere c'est la meme classe.
// les typedef sont la pour clarifier la suite.
//eventuellement, si on trouve ca mieux, on peut remplacer vector par list sans rien casser ailleurs (si c'est bien code)
typedef Pli vector<Carte>;
typedef Main vector<Carte>;

#endif //CARTE_H
