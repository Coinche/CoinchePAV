#include "joueur.h"
#include "regles.h"

using namespace std;

Annonce Joueur::annoncer(const Encheres &encheres)
{
<<<<<<< HEAD
    std::pair<std::vector<Couleur>, std::vector<Hauteur> > possibles = Regles::AnnoncesPossibles(encheres);
    return reflechirEtAnnoncer(possibles);
=======
	std::pair<std::vector<Couleur>, std::vector<Hauteur> > possibles = Regles::AnnoncesPossibles(encheres);
	return reflechirEtAnnoncer(possibles);
>>>>>>> 724574f908be7f7cad89d404f7c1f8c54b5cda57
}

Carte Joueur::jouer(Couleur atout,const Pli &pliEnCours)
{
	Main valides = Regles::valides(
		main,
		atout,
		pliEnCours
	);
<<<<<<< HEAD
        Carte tmp = reflechirEtJouer(valides);
=======
	int index = reflechirEtJouer(valides);
	Carte tmp = main[index];
>>>>>>> 724574f908be7f7cad89d404f7c1f8c54b5cda57
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
<<<<<<< HEAD
=======

Annonce Joueur::reflechirEtAnnoncer(const std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles)
{
	return Annonce(PASSE, COEUR);
}

int Joueur::reflechirEtJouer(const Main& valides)
{
	std::vector<bool> estValide;
	for(int i=0; i<main.size(); i++)
		estValide.push_back(valides.contient(main[i]));
	//return joueurHG->afficherMainEtJouer(main, estValide);
	return 0;
}
>>>>>>> 724574f908be7f7cad89d404f7c1f8c54b5cda57
