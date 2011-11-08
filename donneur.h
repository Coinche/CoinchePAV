#ifndef DONNEUR_H
#define DONNEUR_H

#include "joueur.h"
#include "donneurGraphique.h"

class Donneur {
public:
	//module de cheat a definir
	//...
	// retourner tout ce qui est sorti, voire le jeu de tout le monde
	
	void jouerUnTour();
	
private:
	void melanger();
	void distribuer();
	//...
	
	//attributs
	Joueur*[4] joueurs; //le donneur doit pouvoir appeler les joueurs
	DonneurGraphique* donneurGraphique; //le donneur doit commander le rafraichissement de l'UI
};

typedef Doner Donneur; //pour la blague

#endif //DONNEUR_H