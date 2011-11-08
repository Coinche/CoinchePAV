#ifndef DONNEUR_GRAPHIQUE_H
#define DONNEUR_GRAPHIQUE_H

#include "annonce.h"
#include "carte.h"

//classe virtuelle pour pouvoir bien specifier une interface entre graphique et métier indépendante de la librarie graphique
//et compiler la partie metier seule (sous forme de librarie statique)
class DonneurGraphique {
public:
	void Rafraichir(const Annonce&);
	void Rafraichir(const Pli&);
};

#endif //DONNEUR_GRAPHIQUE_H