#include"annonce.h"


//Constructeur
Annonce::Annonce(Hauteur h, Couleur c): hauteur(h), couleur(c)
{
}

//Méthodes
bool Annonce::operator>(const Annonce& annonce)
{
	return ( hauteur > annonce.get_hauteur() );
}

Hauteur Annonce::get_hauteur() const
{
	return hauteur;
}

Couleur Annonce::get_couleur() const
{
	return couleur;
}