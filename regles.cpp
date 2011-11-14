#include"regles.h"


//Constructeur
Regles::Regles()
{
	//Les nombres négatifs permettent de garder une relation d'ordre au sein des cartes
	//Ne pas oublier de faire un max(valeur,0) lors du comptage des points.
	OrdreAtout[SEPT]=-2;
	OrdreAtout[HUIT]=-1;
	OrdreAtout[NEUF]=14;
	OrdreAtout[DIX]=10;
	OrdreAtout[VALET]=20;
	OrdreAtout[DAME]=3;
	OrdreAtout[ROI]=4;
	OrdreAtout[AS]=11;

	OrdreNonAtout[SEPT]=-2;
	OrdreNonAtout[HUIT]=-1;
	OrdreNonAtout[NEUF]=0;
	OrdreNonAtout[DIX]=10;
	OrdreNonAtout[VALET]=2;
	OrdreNonAtout[DAME]=3;
	OrdreNonAtout[ROI]=4;
	OrdreNonAtout[AS]=11;
}

//Méthodes
int Regles::valeur(const Carte& carte, const Couleur& atout)
{
	return carte.couleur==atout ? OrdreAtout[carte.valeur] : OrdreNonAtout[carte.valeur];
}

int Regles::valeur(const Pli& pli,  const Couleur& atout)
{
	int val=0;
	for(int index=0; index<4; index++)
	{
		val+=valeur( pli[index], atout );
	}
	return val;
}

 int Regles::comparer(const Carte& carte1, const Carte& carte2, const Couleur& atout)
//Compare deux cartes.
//Renvoie :
			// 1 si carte1>carte2
			// 0 si carte1<carte2
			// 2 si les cartes ne sont pas comparables (deux nèfles pissés par ex.)
//Il peut être utile de renvoyer un message d'erreur si carte1==carte2 pour débug.
{
	if(carte1.couleur==carte2.couleur)
	{
		return valeur(carte1, atout) > valeur(carte1, atout) ? 1 : 0 ;
	}
	else
		if(carte1.couleur==atout)
		{
			return true;
		}
		else if(carte2.couleur==atout)
		{
			return false;
		}
		else
		{
			return 2; // trouver un moyen de dire que les 2 cartes ne sont pas comparables.
		}
}

 Main Regles::valides(const Main& main, const Couleur& atout, const Pli& pliEnCours)
{
	Couleur couleurdupli = pliEnCours[0].couleur ;
	int taillepli=pliEnCours.size();
    int taillemain=main.size();

	Main mainvalide;



	for(int i=0; i<main.size();i++)
	{
		Carte carte=main[i];

			//1er test : la carte est un atout
			bool t1 = (carte.couleur == atout) ? 1 : 0 ;

			//2ème test : la carte est dans la couleur demandée
			bool t2 = (carte.couleur == couleurdupli) ? 1 : 0 ;

			//3ème test : le partenaire est maître
			bool t3 = 0;
			if( taillepli > 1 ) // teste si le partenaire a déja joué
			{
				t3=1;
				Carte Partenaire = pliEnCours[ taillepli - 2 ];
				for(int i=0; i<taillepli; i++)
				{
					if( (i!=taillepli-2) && (comparer(Partenaire, pliEnCours[i], atout)==0) )
					// verfie que le partenaire est maître
					//NB : si i==taillepli-2, le programme sort de la boucle sans evaluer le second élément de la condition,
					// à notre plus grand bonheur puisque comparer( carte, carte, atout ) renvoie 0 lorsque les cartes en entrée sont égales.
					{
						t3=0;
					}
				}
			}

			//4ème test : il reste des atouts dans la main
			bool t4= (t1) ? 1 : 0;
			int incr4=0;
			while( incr4<taillepli && ~t4 )
			{
				if(pliEnCours[i].couleur == atout )
				{
					t4=1;
				}
				incr4++;
			}
			//5ème test : il reste des cartes de même couleur dans la main
			bool t5=0;
			for(int i=0; i<taillepli; i++)
			{
				if(pliEnCours[i].couleur == carte.couleur)
				{
					t5=1;
				}
			}
			//6ème test : la carte est plus forte que toutes celles du pli en cours
			bool t6=1;
			int incr6=0;
			while(incr6<taillepli && t6 )
			{
				if( (incr6!=taillepli-2) &&  (comparer(carte, pliEnCours[i], atout) != 1) )
				{
					t6=0;
				}
				incr6++;
			}
			//7ème test : il existe un atout plus fort que ceux dans le pli dans la main.
			bool t7=1;
			int incr7=0;
			while(incr7<taillemain && t7 )
			{
				if( (incr6!=taillemain-2) && main[incr7].couleur==atout && (comparer(carte, main[i], atout) != 1) )
				{
					t7=0;
				}
				incr7++;
			}

	}

}

/*static Carte AlaMain(const Couleur& atout, const Pli& pliEnCours, const Couleur& couleurdemandee);
{

}*/
