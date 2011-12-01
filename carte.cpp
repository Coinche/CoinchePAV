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

bool Carte::triParCouleur(const Carte &carte1, const Carte &carte2)
{
	if(carte1.get_couleur() == carte2.get_couleur())
		return (carte1.get_valeur()<=carte2.get_valeur());
	else
		return (carte1.get_couleur()<=carte2.get_couleur());
}