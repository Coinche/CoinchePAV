#include "carte.h"

Carte::Carte(Valeur val, Couleur coul) :	valeur(val), couleur(coul)
{}



 Carte::Carte(const Carte& carte) : valeur(carte.valeur), couleur(carte.couleur)
 {}

Valeur Carte::get_valeur() const
{
    return valeur;

}
Couleur Carte::get_couleur() const
{

    return couleur;
}

bool operator==(const Carte& carte1, const Carte& carte2)
{
	return (carte1.get_valeur() == carte2.get_valeur() && carte1.get_couleur() == carte2.get_couleur());
}

bool operator==(const Main &main1, const Main &main2)
{
	bool reponse = true;
	if(main1.size() != main2.size())
	{
	    return false;
	}
	else
	{
	    unsigned int index1 = 0;
        while( reponse && ( index1<main1.size() ) )
        {
            bool reponsecarte = false;
            for (unsigned int index2 = 0; index2<main2.size(); index2++)
            {
                reponsecarte|=(main1[index1]==main2[index2]);
            }
            reponse&=reponsecarte;
            index1++;

        }
        return reponse;
	}

}