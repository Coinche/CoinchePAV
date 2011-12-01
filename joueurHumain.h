#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "mmain.h"
#include "annonce.h"
#include "joueur.h"
#include "joueurhumaingraphique.h"

class JoueurHumain : public Joueur
{
	public:
                Annonce reflechirEtAnnoncer(const  std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles);
                Carte reflechirEtJouer(const Main& valides);
                void set_joueurHG(JoueurHumainGraphique* _joueurHG);
                void recevoirMain(const Main &main);
	private:
		JoueurHumainGraphique *joueurHG;
};

#endif //JOUEUR_HUMAIN_H
