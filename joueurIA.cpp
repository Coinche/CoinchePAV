#include "joueurIA.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>


void IA::set_donneur(Donneur *_donneur)
{
    donneur = _donneur;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// IA dummy
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Annonce IA_dummy::reflechirEtAnnoncer(const  std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles )
{
	return Annonce(PASSE,COEUR);
}

Carte IA_dummy::reflechirEtJouer(const Main& valides)
{
        int valeurAuHasard = rand() % valides.size();
        return valides[valeurAuHasard];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// IA intermediate
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Hauteur IA_intermediate::estimerValeurDeLaMain(const Couleur& atout)
{
    int compteur =0;

    bool belote = false;
    bool rebelote = false;

    for(unsigned int idx_carte=0; idx_carte < main.size(); idx_carte++)
    {
        if(main[idx_carte].get_couleur() == atout )
        {
            if (main[idx_carte].get_valeur() == VALET) compteur+=60 ;
            if (main[idx_carte].get_valeur() == NEUF) compteur+=10 ;
            if (main[idx_carte].get_valeur() == AS) compteur+=10 ;

            if (main[idx_carte].get_valeur() == ROI) belote = true ;
            if (main[idx_carte].get_valeur() == ROI) rebelote = true ;
        }
        else
        {
            if (main[idx_carte].get_valeur() == AS) compteur+=10 ;
        }

        if(belote && rebelote) compteur+=20;

    }
    return (compteur>80) ? (Hauteur) compteur : PASSE;
}



Hauteur IA_intermediate::estimerValeurMainAvecPartner(const Couleur& couleurdemandeeparpartner)
{
    int compteur = 0;


    bool belote = false;
    bool rebelote = false;

    for(unsigned int idx_carte=0; idx_carte < main.size(); idx_carte++)
    {
        if(main[idx_carte].get_couleur() == couleurdemandeeparpartner )
        {
            if (main[idx_carte].get_valeur() == VALET) compteur+=20 ;
            if (main[idx_carte].get_valeur() == NEUF) compteur+=10 ;
            if (main[idx_carte].get_valeur() == AS) compteur+=10 ;

            if (main[idx_carte].get_valeur() == ROI) belote = true ;
            if (main[idx_carte].get_valeur() == ROI) rebelote = true ;
        }
        else
        {
            if (main[idx_carte].get_valeur() == AS) compteur+=10 ;
        }
    }

    if(belote && rebelote) compteur+=20;
    return (Hauteur) compteur;
}

Annonce IA_intermediate::MaximiserlAnnonceInitiale()
{
	Hauteur hauteurPourAnnonce = PASSE;
    Couleur couleurPourAnnonce = COEUR;
	for(int idx_couleur = 0; idx_couleur < 3; idx_couleur++ )
	{
		Couleur atout = int2Couleur(idx_couleur);
		if(estimerValeurDeLaMain(atout) > hauteurPourAnnonce)
		{
			hauteurPourAnnonce = estimerValeurDeLaMain(atout);
			couleurPourAnnonce = atout;
		}

	}
	return Annonce(hauteurPourAnnonce,couleurPourAnnonce);
}

Hauteur IA_intermediate::RenvoyerDerniereAnnonceDansLaCouleur(const Encheres& encheresIA, const Couleur& couleurdemandee)
{
	Hauteur hauteurDeLaDerniereAnnonce;
	for(unsigned int index_enchere=0; index_enchere < encheresIA.size(); index_enchere++ )
	{
		if(encheresIA[index_enchere].get_couleur() == couleurdemandee ) hauteurDeLaDerniereAnnonce = encheresIA[index_enchere].get_hauteur();
	}
	return hauteurDeLaDerniereAnnonce;
}

Hauteur IA_intermediate::RenvoyerPremiereAnnonceDansLaCouleur(const Encheres& encheresIA, const Couleur& couleurdemandee)
{
	for( unsigned int index_enchere=0; index_enchere < encheresIA.size(); index_enchere++ )
	{
		if(encheresIA[index_enchere].get_couleur() == couleurdemandee ) return encheresIA[index_enchere].get_hauteur();
	}
	return QUATRE_VINGT;
}

//Dans l'IA intermédiaire, elle va réagir de trois manières pour gérer les annonces :
// 	- si le partenaire n'a pas mis d'enchères, elle va regarder si elle peut annoncer (seuil à 80 dans une couleur) dans une couleur
//  - si le partenaire renchérit sur l'annonce initiale de l'IA, l'IA passe
//	-si le partenaire annonce dans une nouvelle couleur, l'IA recalcule ce qu'elle peut raisonablement renchérir.
Annonce IA_intermediate::reflechirEtAnnoncer(const  std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles)
{
    const Encheres &encheres = donneur->get_encheres();
    //Cas où l'IA est la première a annoncer
    if(encheres.empty())
    {
		Annonce annonceInitiale = MaximiserlAnnonceInitiale();
        return ( annonceInitiale>Annonce(QUATRE_VINGT,COEUR) ) ? annonceInitiale : Annonce(PASSE,COEUR); //on ne surenchérit que si notre enchère est supérieure à 80
    }


    int tourdencheres = encheres.size()/4;
	unsigned int pos_IA = encheres.size()%4;
	unsigned int pos_partner = (pos_IA + 2)%4;
	Encheres encheresIA;
	Encheres encherespartner;
	for( unsigned int index_annonce = 0; index_annonce<encheres.size(); index_annonce++ )
	{
        if (index_annonce%4 == pos_IA) encheresIA.push_back(encheres[index_annonce]);
        if (index_annonce%4 == pos_partner) encherespartner.push_back(encheres[index_annonce]);
	}
	//Cas un peu spécial du premier tour 
	if(tourdencheres == 0)
	{
		//Si on annonce avant le partenaire -> On maximise notre annonce selon la couleur, sous réserve d'avoir une enchères supérieure la dernière annonce de l'adversaire
		//Si le partenaire a passé au premier tour -> idem
		if( encherespartner.empty() || encherespartner.back().get_hauteur() == PASSE )
		{
			Annonce annonceInitiale = MaximiserlAnnonceInitiale();
        	return (annonceInitiale>encheres.back()) ? annonceInitiale : Annonce(PASSE,COEUR); //on ne surenchérit que si notre enchère est supérieure à 80 et 
		}
		else // le partenaire a annoncé avant nous -> on le remonte de sa couleur
		{
			Couleur couleurdemandeeparpartner = encherespartner.back().get_couleur();
			
			Hauteur estimation = estimerValeurMainAvecPartner(couleurdemandeeparpartner);
			int hauteurajoutee = encherespartner.back().get_hauteur() + estimation;
			
			return  Annonce( (Hauteur) hauteurajoutee, couleurdemandeeparpartner);
		}
	
	}
	else // on a déjà fait un tour d'annonce : on renchérit seulement si le partenaire a changé de couleur après notre enchere précédente
	{
		Couleur couleurdeladerniereAnnonceIA = encheresIA.back().get_couleur();
		Couleur couleurdemandeeparpartner = encherespartner.back().get_couleur();
		if(couleurdemandeeparpartner == couleurdeladerniereAnnonceIA) return Annonce(PASSE, COEUR ); // on reste dans la même couleur -> on est déjà au maximum que l'on peut annoncer
		else
		{
			//Le partenaire a changé de couleur : on lui fait confiance et on remonte de dix seulement si l'adversaire n'a pas remonté entre temps
			Hauteur estimation = estimerValeurMainAvecPartner(couleurdemandeeparpartner);
			int hauteurajoutee = encherespartner.back().get_hauteur() + 10;
			Annonce NouvelleAnnonce( (Hauteur) hauteurajoutee, couleurdemandeeparpartner);
			return (NouvelleAnnonce > encheres.back() ) ? NouvelleAnnonce : Annonce(PASSE,COEUR);
		}
	
	}
}

bool IA_intermediate::EstMaitre(const Carte& carteATester, const Couleur& atout, const Pli& PliEnCours)
{
    bool reponse = true;
    if(PliEnCours.empty()) return true;
    for(unsigned int index_carteDuPli = 0; index_carteDuPli < PliEnCours.size(); index_carteDuPli++)
    {
        if ( Regles::comparer(PliEnCours[index_carteDuPli] ,carteATester,atout))
        {
            reponse = false;
        }
    }
    return reponse;
}

int IA_intermediate::DeposerNefle(const Couleur& atout, const Main &valides)
{
    unsigned int index_nefle = 0;
    int valeur_nefle = 25;
    for(unsigned int i=0; i<valides.size();i++)
    {
        if( Regles::valeur(valides[i], atout) < valeur_nefle)
        {
            valeur_nefle = Regles::valeur(valides[i], atout);
            index_nefle = i;
        }
    }
    return index_nefle;
}


Carte IA_intermediate::reflechirEtJouer(const Main &valides)
{

    atout = donneur->get_atout();
    PliEnCours = donneur->get_pliEnCours();
    for(unsigned int i = 0; i<valides.size(); i++)
    {
        if(EstMaitre(valides[i],atout,PliEnCours)) return valides[i];
    }
    //cas où l'IA n'a pas de cartes maîtresse dans sa main
    return valides[DeposerNefle(atout, valides)];
}
