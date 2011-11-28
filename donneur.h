#ifndef DONNEUR_H
#define DONNEUR_H
#include "regles.h"
#include "joueur.h"
#include "donneurGraphique.h"

class Donneur {
public:

	Donneur(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3);
	//module de cheat a definir
	//...
	// retourner tout ce qui est sorti, voire le jeu de tout le monde
	
	void jouerUnTour();
	
private:
	void melanger();
	void distribuer();
	void jouerUnPli();
	void compter();
	bool encheresEnCours() const;
	//...
	
	//attributs
	Joueur* joueurs[4] ; //le donneur doit pouvoir appeler les joueurs
	unsigned int scores[2];//scores[0] est le score des joueurs pairs
	unsigned int scores_tmp[2];
	//DonneurGraphique* donneurGraphique; //le donneur doit commander le rafraichissement de l'UI
	int premier; // joueurs[premier] pointe vers le joueur qui joue en premier ce tour
	Couleur atout;
	Encheres encheres;
	Pli plisRamasses;
	
	
};

typedef Donneur Doner; //pour la blague

#endif //DONNEUR_H