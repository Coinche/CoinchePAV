#ifndef DONNEUR_H
#define DONNEUR_H
#include "regles.h"
#include "joueur.h"

#include "donneurgraphique.h"

class Donneur {
public:

	Donneur();
	Donneur(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3);
	
	void set_joueurs(Joueur *joueur0, Joueur *joueur1, Joueur *joueur2, Joueur *joueur3);
        void set_donneurGraphique(DonneurGraphique *_donneurG);

	//module de cheat a definir
	//...
	// retourner tout ce qui est sorti, voire le jeu de tout le monde
	Main get_main(int joueur);//joueur est compris entre 0 et 4, 0 designant joueurs[premier]
        Couleur get_atout();
        Pli get_pliEnCours();
        Encheres get_encheres();
	
	void jouerUnTour();
        void jouerUnePartie();
private:
	void init(); //initialisations communes aux deux constructeurs
	void melanger();
	void distribuer();
	int jouerUnPli(int entame);
	void compter();
	int get_maitre(const Pli& pliEnCours);
	void compterLaBelote(int joueurCourant);
	//...
	
	//attributs
	Joueur* joueurs[4] ; //le donneur doit pouvoir appeler les joueurs
	int scores[2];//scores[0] est le score des joueurs pairs
	int scores_tmp[2];
        DonneurGraphique* donneurGraphique; //le donneur doit commander le rafraichissement de l'UI
	int premier; // joueurs[premier] pointe vers le joueur qui joue en premier ce tour
	Couleur atout;
	Encheres encheres;
	Pli plisRamasses;
        Pli pliEnCours;
        int attaque;
        int defense;
	
};

typedef Donneur Doner; //pour la blague

#endif //DONNEUR_H
