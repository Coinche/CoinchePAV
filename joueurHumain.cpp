#include "joueurHumain.h"

Annonce JoueurHumain::reflechirEtAnnoncer(const std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles)
{
       return joueurHG->afficherAnnonceEtParler(possibles.second, possibles.first);
	//return Annonce(PASSE, COEUR);
}

Carte JoueurHumain::reflechirEtJouer(const Main& valides)
{
	Main _main(this->get_main());
	std::vector<bool> estValide;
	for(unsigned int i=0; i<_main.size(); i++)
		estValide.push_back(valides.contient(_main[i]));
        int index = joueurHG->afficherMainEtJouer(_main, estValide);
        return main[index];
	//return 0;
}

void JoueurHumain::set_joueurHG(JoueurHumainGraphique* _joueurHG)
{
    joueurHG = _joueurHG;
}

void JoueurHumain::recevoirMain(const Main &main)
{
    Joueur::recevoirMain(main);
    std::vector<bool> tout(8,true);
    joueurHG->afficherMain(main,tout);
}
