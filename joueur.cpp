#include "joueur.h"

Annonce Joueur::annoncer()
{
	return reflechirEtAnnoncer();
}

Carte Joueur::jouer()
{
	int index = reflechirEtJouer();
	Carte tmp = main[index];
	main.erase(index);
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