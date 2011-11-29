#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <assert.h>

#include "debugage.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////
//Debugage
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::debugage(){

	std::ofstream outfile ("log.txt");
	outfile << "Début du débogage" << std::endl;
    outfile.close();

	bool status = true;
        status &= test_T_ANNONCE();
        status &= test_T_CARTE();
        status &= test_T_MMAIN();
        status &= test_T_REGLES();

    std::ofstream outfile2 ("log.txt",std::ios_base::app);
	outfile2 << "Fin du débogage" << std::endl;
	outfile2.close();


	return status;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//T_Annonce
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::test_T_ANNONCE(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Annonce" << std::endl;
	std::cout << tab << "Test de la classe Annonce" << std::endl;

	bool status = true;

	try{
		//Constructeur
		Annonce pj(QUATRE_VINGT,CARREAU);
		Couleur car = pj.get_couleur();
		Hauteur hau = pj.get_hauteur();
		assert(pj.get_couleur() == CARREAU);
		assert(pj.get_hauteur() == QUATRE_VINGT);
		//Comparaison
		Annonce bg(CENT_SOIXANTE_DIX,TREFLE);
		assert(bg > pj);
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test_ANNONCE : " << "ERREUR : " << e.what() << std::endl;
		status = false;
	}
	outfile.close();
	if(status)
	{
	    std::cout << tab << "T_ANNONCE : Le test s'est déroulé sans problème" << std::endl;
	}
    else
    {
        std::cout << tab << "T_ANNONCE Le test à détecté des problèmes. Voir le fichier log.txt" << std::endl;
    }

	return status;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//T_CARTE
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::test_T_CARTE(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Carte" << std::endl;
	std::cout << tab << "Test de la classe Carte" << std::endl;

	//Tests
	bool status = true;

	try{
		//Createur
		Carte tt(ROI,CARREAU);
		Valeur val = tt.get_valeur();
		Couleur coul = tt.get_couleur();
		assert(tt.get_valeur() == ROI);
		assert(tt.get_couleur() == CARREAU);
		//CreateurParCopie
		Carte ttcopie(tt);
		//Triparcouleur
		Carte moinsforte(DAME,CARREAU);
		assert(Carte::triParCouleur(moinsforte,tt)); //triParCouleur(tt,moinsforte) doit renvoyer true
		//operateurEgalEgal
		assert(ttcopie==tt);

	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "testCARTE : " << "ERREUR : " << e.what() << std::endl;
		status = false;
	}
	outfile.close();

	if(status)
	{
	    std::cout << tab << "T_CARTE : Le test s'est déroulé sans problème" << std::endl;
	}
    else
    {
        std::cout << tab << "T_CARTE Le test à détecté des problèmes. Voir le fichier log.txt" << std::endl;
    }

	return status;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//T_MMAIN
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::test_T_MMAIN(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Main" << std::endl;
	std::cout << tab << "Test de la classe Main" << std::endl;

	//Tests
	bool status = true;

	try{
		//Createur
		Main mainj2;
		assert( mainj2.empty() );
		//push_back
		mainj2.push_back( Carte(ROI,CARREAU) );
		//size
		assert(mainj2.size() == 1);
		//CreateurParCopie
		Main maincopie(mainj2);
		assert(maincopie == mainj2);
		//contient
		assert( mainj2.contient(Carte(ROI,CARREAU)) );
		//extraire
		assert(mainj2.extraire(CARREAU) == mainj2);
		//Triparcouleur
		mainj2.push_back( Carte(DAME,CARREAU) );
		Main mainTriee;
		mainTriee.push_back( Carte(DAME,CARREAU) );
		mainTriee.push_back( Carte(ROI,CARREAU) );
		mainj2.trierParCouleur();
		assert( mainj2  == mainTriee);

	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "testMAIN : " << "ERREUR : " << e.what() << std::endl;
		status = false;
	}
	outfile.close();

	if(status)
	{
	    std::cout << tab << "T_MAIN : Le test s'est déroulé sans problème" << std::endl;
	}
    else
    {
        std::cout << tab << "T_MAIN Le test à détecté des problèmes. Voir le fichier log.txt" << std::endl;
    }

	return status;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//T_REGLES
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::test_T_REGLES(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Regles" << std::endl;

	std::cout << tab << "Test de la classe Regles" << std::endl;

	//Tests
	bool status = true;

	try{
		//méthode valeur(carte)
		Carte valetdecarreau(VALET, CARREAU);
		Carte nefledecoeur(NEUF, COEUR);
		assert(Regles::valeur(valetdecarreau, CARREAU) == 20 );
		assert(Regles::valeur(valetdecarreau, TREFLE) == 2 );
		assert(Regles::valeur(nefledecoeur, COEUR) == 14 );
		assert(Regles::valeur(nefledecoeur, PIQUE) == 0);



		//méthode valeur(pli)
		Pli plipli;
		        plipli.push_back(valetdecarreau);
		        plipli.push_back(nefledecoeur);
		    Carte roidecarreau(ROI,CARREAU);
		        plipli.push_back(roidecarreau);

		assert(Regles::valeur(plipli, CARREAU) == 24);
		assert(Regles::valeur(plipli, TREFLE) == 6 );

		//methode comparer
		assert(Regles::comparer(valetdecarreau, roidecarreau, CARREAU) == 1);
		assert(Regles::comparer(valetdecarreau, roidecarreau, TREFLE) == 0);
		assert(Regles::comparer(valetdecarreau, nefledecoeur , TREFLE) == 2);

		//Méthode valides
		Main mainjoueur;
		Carte septdecarreau(SEPT,CARREAU);
		        mainjoueur.push_back(septdecarreau);
		Carte neufdecarreau(NEUF,CARREAU);
		        mainjoueur.push_back(neufdecarreau);
		Carte roidetrefle(ROI,TREFLE);
				mainjoueur.push_back(roidetrefle);

		Main MainvalideCARREAU;
			MainvalideCARREAU.push_back(neufdecarreau);
			MainvalideCARREAU.push_back(septdecarreau);

		Main MainvalidePIQUE;
			MainvalidePIQUE.push_back(septdecarreau);
			MainvalidePIQUE.push_back(neufdecarreau);

		Main MainvalideTREFLE;
			MainvalideTREFLE.push_back(septdecarreau);
			MainvalideTREFLE.push_back(neufdecarreau);


		Main mainsortieCARREAU = Regles::valides(mainjoueur, CARREAU, plipli);
		Main mainsortiePIQUE = Regles::valides(mainjoueur, PIQUE, plipli);
		Main mainsortieTREFLE = Regles::valides(mainjoueur, TREFLE, plipli);
		bool testcarreau = (mainsortieCARREAU == MainvalideCARREAU);
		bool testpique = (mainsortiePIQUE == MainvalidePIQUE);
		bool testtrefle = (mainsortieTREFLE == MainvalideTREFLE);
		assert(testcarreau);
		assert(testpique);
        assert(testtrefle);


	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "testRegles: " << "ERREUR : " << e.what() << std::endl;
		status = false;
	}
	outfile.close();
	if(status)
	{
	    std::cout << tab << "T_REGLES : Le test s'est déroulé sans problème" << std::endl;
	}
    else
    {
        std::cout << tab << "T_REGLES Le test à détecté des problèmes. Voir le fichier log.txt" << std::endl;
    }

	return status;
}


