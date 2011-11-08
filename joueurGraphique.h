#ifndef JOUEUR_GRAPHIQUE_H
#define JOUEUR_GRAPHIQUE_H

#include "annonce.h"
#include "carte.h"

//classe virtuelle pour pouvoir bien specifier une interface entre graphique et métier indépendante de la librarie graphique
//et compiler la partie metier seule (sous forme de librarie statique)
class JoueurGraphique {
public:
	virtual Annonce annoncer(const Annonce&) = 0;
	virtual Carte jouer(const Main&) = 0;
};

#endif //JOUEUR_GRAPHIQUE_H