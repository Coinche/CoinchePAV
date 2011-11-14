#ifndef REGLES_H
#define REGLES_H

#include "types.h"
#include "carte.h"
#include <map>

class Regles { //classe sans attributs, juste pour regrouper les regles quelque part
public:
	//Attributs
	 std::map<Valeur, int> OrdreAtout;
	 std::map<Valeur, int> OrdreNonAtout;

	Regles();

	 int comparer(const Carte& carte1, const Carte& carte2, const Couleur& atout);
	//static Main CartesJoueesalAtout(const Pli& pliEnCours);
	//static Carte AlaMain(const Couleur& atout, const Pli& pliEnCours, const Couleur& couleurdemandee);
	 Main valides(const Main& main, const Couleur& atout, const Pli& pliEnCours); //type de retour à voir plus tard
	//static bool isPartenaireMaster(const Joueur& main, const Couleur& atout, const Pli& pliEnCours);
	 int valeur(const Carte& carte, const Couleur& atout);
	 int valeur(const Pli& pli,  const Couleur& atout);
	//il manque sans doute plein de regles, mais c'est pas grave parce qu'on peut en ajouter sans trop de souci de casser le code.
	// on peut par exemple penser pouvoir gerer les variantes avec la chute a 160 points, le resultat minimum a 82pts, etc.
};

#endif //REGLES_H
