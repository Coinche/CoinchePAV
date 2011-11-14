#include "joueur.h"

Annonce Joueur::annoncer()
{
	Annonce tmp = reflechirEtAnnoncer();
	encheres.push_back(tmp);
	return tmp;
}

Carte Joueur::jouer()
{
	return reflechirEtJouer();
}

Encheres Joueur::encheres() const
{
	return encheres;
}

Main Joueur::mmain() const
{
	return mmain;
}

void Joueur::recevoirMain(const Main& nouvelleMain)
{
	mmain = nouvelleMain;
}