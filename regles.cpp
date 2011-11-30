#include "regles.h"
#include <algorithm>


//M�thodes
int Regles::valeur(const Carte& carte, const Couleur& atout)
{
        std::map<Valeur, int> OrdreAtout;
        std::map<Valeur, int> OrdreNonAtout;
        //Les nombres n�gatifs permettent de garder une relation d'ordre au sein des cartes
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

	return carte.get_couleur()==atout ? OrdreAtout[carte.get_valeur()] : OrdreNonAtout[carte.get_valeur()];
}

int Regles::valeur(const Pli& pli,  const Couleur& atout)
{
	int val=0;
	for(int index=0; index<4; index++)
	{
		val+=std::max(0,valeur( pli[index], atout ));
	}
	return val;
}

 int Regles::comparer(const Carte& carte1, const Carte& carte2, const Couleur& atout)
//Compare deux cartes.
//Renvoie :
			// 1 si carte1>carte2
			// 0 si carte1<carte2
			// 2 si les cartes ne sont pas comparables (deux n�fles piss�s par ex.)
//Il peut �tre utile de renvoyer un message d'erreur si carte1==carte2 pour d�bug.
{
	if(carte1.get_couleur()==carte2.get_couleur())
	{
		return valeur(carte1, atout) > valeur(carte2, atout) ? 1 : 0 ;
	}
	else
		if(carte1.get_couleur() == atout)
		{
			return true;
		}
		else if(carte2.get_couleur() == atout)
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
	//test 0: la carte est la premiere du pli
	if(pliEnCours.empty()) return main;

	Couleur couleurdupli = pliEnCours[0].get_couleur() ;
	int taillepli=pliEnCours.size();
    int taillemain=main.size();

	Main mainvalide;



	for(unsigned int i=0; i<main.size();i++)
	{
		Carte carte=main[i];

			//1er test : la carte est un atout
			bool t1 = (carte.get_couleur() == atout) ? 1 : 0 ;

			//2�me test : la carte est dans la couleur demandee
			bool t2 = (carte.get_couleur() == couleurdupli) ? 1 : 0 ;

			//3�me test : le partenaire est maitre
			bool t3 = 0;
			if( taillepli > 1 ) // teste si le partenaire a deja joue
			{
				t3=1;
				Carte Partenaire = pliEnCours[ taillepli - 2 ];
				for(int j=0; j<taillepli; j++)
				{
					if( (j!=taillepli-2) && (comparer(Partenaire, pliEnCours[j], atout) != 1) )
					// verfie que le partenaire est maitre
					//NB : si i==taillepli-2, le programme sort de la boucle sans evaluer le second element de la condition,
					// a notre plus grand bonheur puisque comparer( carte, carte, atout ) renvoie 0 lorsque les cartes en entree sont egales.
					{
						t3=0;
					}
				}
			}

			//4�me test : il reste des atouts dans la main
			bool t4= (t1) ? 1 : 0;
			int incr4=0;
			while( incr4<taillemain && ~t4 )
			{
				if(main[incr4].get_couleur() == atout )
				{
					t4=1;
				}
				incr4++;
			}
			//5�me test : il reste des cartes de la couleur demandee dans la main
			bool t5=0;
			for(int k=0; k<taillemain; k++)
			{
				if(main[k].get_couleur() == couleurdupli )
				{
					t5=1;
				}
			}
			//6�me test : la carte est plus forte que toutes celles du pli en cours
			bool t6=1;
			int incr6=0;
			while(incr6<taillepli && t6 )
			{
				if( (incr6!=taillepli-2) &&  (comparer(carte, pliEnCours[incr6], atout) != 1) )
				{
					t6=0;
				}
				incr6++;
			}
			//7�me test : il existe un atout plus fort que ceux dans le pli dans la main.
			bool t7=1;
			int incr7=0;

			Main mainatout = main.extraire(atout);
			if(mainatout.empty()) t7 = 0;
			else{

			    Carte atoutLePlusFortdeLaMain(SEPT,atout); // initialisée a la plus petite valeur possible
			    for(unsigned int j=0; j<mainatout.size();j++ )
			    {
			        if(comparer(mainatout[j],atoutLePlusFortdeLaMain,atout) == 1 )
			        {
			            atoutLePlusFortdeLaMain = mainatout[j];
			        }
			    }
                //on refait le test 6, mais cette fois-ci avec l'atout le plus fort de la main
                while(incr7<taillepli && t7 )
                {
				if( (incr7!=taillepli-2) &&  (comparer(atoutLePlusFortdeLaMain, pliEnCours[incr7], atout) != 1) )
				{
					t7=0;
				}
				incr7++;
                }
			 }

		//Selon les resultats des tests, renvoyez oui ou non. Pour cela on parcours la procédure suivante :
		//La carte n'est pas un atout, le joueur peut la jouer si :
        //         - elle est de la couleur demandee
        //         - la partenaire est maître donc le joueur n'est pas obligé de couper
        //         - elle n'est pas de couleur demandee mais le joueur n'a plus d'atout et n'a plus de carte de la couleur demandee
        //La carte est un atout :
        //         - la couleur demandee n'est pas de l'atout, le joueur peut la jouer si :
        //              -- le joueur n'a plus de cartes de la couleur demandée et il ne peut (ou n'a pas besoin ) de monter à l'atout
        //         - la couleur demandee est de l'atout, le joueur peut la jouer si :
        //              -- la carte est plus forte que tous les atouts deposes
        //              -- le joueur ne peux pas monter au-dessus du plus grand atout du pli
		switch(t1)
		{
			case 0 : // la carte n'est pas un atout
			{
				if(t2) mainvalide.push_back(carte); // la carte est de la couleur demand�e donc jouable
				else
				{
					if(t3) mainvalide.push_back(carte); //le partenaire est maitre donc la carte est jouable / faudrait pas tester t5 en meme temps?
					else
					{
						if(t4 == false && t5 == false) mainvalide.push_back(carte);
                        // il reste des atouts dans la main : la carte n'est pas jouable
                        // le joueur n'a plus d'atouts : il peut se d�fausser avec n'importe qu'elle carte.
					}
				}

				break;
			}
			case 1 : // la carte est un atout
			{
				switch(t2)
				{
					case 0 : // la carte est un atout et la couleur demand�e n'est pas de l'atout
					{
						if(t5 == false) // il n'a plus de carte de la couleur demand�e : il est oblig� de couper
						{
							if(t6) mainvalide.push_back(carte); //la carte est plus forte que toutes les autres cartes du pli.
							else // on va tester si le joueur doit "monter � l'atout".
							{
								if(t7 == false)
								{
									mainvalide.push_back(carte); //le joueur ne peut pas monter : il a le droit de poser la carte.
								}
							}
						}
						break;
					}
					case 1 : // la carte est un atout et la couleur est de l'atout
					{
 						 // dans ce cas, le test 5 ( "reste-t-il une carte de la couleur demandee ?")  vaut obligatoirement 1.
						if(t6) mainvalide.push_back(carte); //la carte est plus forte que toutes les autres cartes.
							else // on va tester si le joueur doit "monter a l'atout".
							{
								if(t7 == false)
								{
								    mainvalide.push_back(carte); //le joueur ne peut pas monter.
								}
							}
						break;
					}
				}
				break;
			}
		}
	}

	return mainvalide;

}

std::pair<std::vector<Couleur>, std::vector<Hauteur> > Regles::AnnoncesPossibles(const Encheres& encheresEnCours)
{
    std::pair<std::vector<Couleur>, std::vector<Hauteur> > output;
    Couleur couleursDeBase[4];
        couleursDeBase[0]=COEUR;
        couleursDeBase[1]=CARREAU;
        couleursDeBase[2]=PIQUE;
        couleursDeBase[3]=TREFLE;

    Hauteur hauteursDeBase[12];
	hauteursDeBase[0] = QUATRE_VINGT ;
	hauteursDeBase[1] = QUATRE_VINGT_DIX ;
	hauteursDeBase[2] = CENT ;
	hauteursDeBase[3] = CENT_DIX ;
	hauteursDeBase[4] = CENT_VINGT ;
	hauteursDeBase[5] = CENT_TRENTE ;
	hauteursDeBase[6] = CENT_QUARANTE ;
	hauteursDeBase[7] = CENT_CINQUANTE ;
	hauteursDeBase[8] = CENT_SOIXANTE ;
	hauteursDeBase[9] = CENT_SOIXANTE_DIX ;
	hauteursDeBase[10] = CAPOT ;
	hauteursDeBase[11] = PASSE ;

    std::vector<Couleur> couleurs;
    std::vector<Hauteur> hauteurs;

    if(encheresEnCours.size()>3)
    {
        bool test_passe = ( encheresEnCours[encheresEnCours.size()].get_hauteur() == PASSE  );
        bool test_passe2 = ( encheresEnCours[encheresEnCours.size()-1].get_hauteur() == PASSE  );
        bool test_passe3 = ( encheresEnCours[encheresEnCours.size()-2].get_hauteur() == PASSE  );
        bool test_passe4 = ( encheresEnCours[encheresEnCours.size()-3].get_hauteur() == PASSE  );

        if (test_passe && test_passe2 && test_passe3 && test_passe4)
        {
            return output; //vecteurs vides
        }
        if (test_passe && test_passe2 && test_passe3 && !test_passe4 )
        {
            Couleur couleurInterdite = encheresEnCours[encheresEnCours.size()-3].get_couleur();
            for(unsigned int i=0; i<4; i++)
            {
                if(couleursDeBase[i] != couleurInterdite) couleurs.push_back(couleursDeBase[i]);
            }
            for(unsigned int j=0; j<12; j++)
            {
                if(hauteursDeBase[j] > encheresEnCours[encheresEnCours.size()-3].get_hauteur() ) hauteurs.push_back(hauteursDeBase[j]);
            }
            return output;
        }
        for(unsigned int i=0; i<4; i++)
        {
            couleurs.push_back(couleursDeBase[i]);
        }
        for(unsigned int j=0; j<12; j++)
        {
            if(hauteursDeBase[j] > encheresEnCours[encheresEnCours.size()-1].get_hauteur() ) hauteurs.push_back(hauteursDeBase[j]);
        }
        return output;
    }
    else{

        for(unsigned int i=0; i<4; i++)
        {
            couleurs.push_back(couleursDeBase[i]);
        }
        for(unsigned int j=0; j<12; j++)
        {
            if(hauteursDeBase[j] > encheresEnCours[encheresEnCours.size()-1].get_hauteur() ) hauteurs.push_back(hauteursDeBase[j]);
        }
        return output;

    }

}
