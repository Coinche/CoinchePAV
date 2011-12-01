#include "joueur.h"
#include "regles.h"

using namespace std;

Annonce Joueur::annoncer(const Encheres &encheres)
{
    std::pair<std::vector<Couleur>, std::vector<Hauteur> > possibles = Regles::AnnoncesPossibles(encheres);
    return reflechirEtAnnoncer(possibles);
}

Carte Joueur::jouer(Couleur atout,const Pli &pliEnCours)
{
	Main valides = Regles::valides(
		main,
		atout,
		pliEnCours
	);
        Carte tmp = reflechirEtJouer(valides);
	main.enlever(tmp);
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
