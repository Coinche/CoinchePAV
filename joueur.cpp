#include "joueur.h"

Annonce Joueur::annoncer()
{
	return reflechirEtAnnoncer();
}

Carte Joueur::jouer()
{
	int index = reflechirEtJouer();
	Carte tmp = main[index];
	main.erase(main.begin() + index);
	return tmp;
}

Main Joueur::get_main() const
{
	return main;
}

void Joueur::recevoirMain(const Main& nouvelleMain)
{
	main = nouvelleMain;
}

Annonce Joueur::reflechirEtAnnoncer()
{
	return Annonce(PASSE, COEUR);
}

int Joueur::reflechirEtJouer(){return 1;}