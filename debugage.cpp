#include <iostream>
#include <fstream>
#include <exception>
#include <string>


#include "debugage.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Debugage
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool Debugage::debugage(){

	std::ofstream outfile ("log.txt");
	outfile << "Début du débogage" << std::endl;
    outfile.close();

	bool status = true;
        status &= T_ANNONCE::test_T_ANNONCE();
        status &= T_CARTE::test_T_CARTE();
        status &= T_REGLES::test_T_REGLES();

    std::ofstream outfile2 ("log.txt",std::ios_base::app);
	outfile2 << "Fin du débogage" << std::endl;
	outfile2.close();


	return status;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//T_Annonce
/////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructeur
bool T_ANNONCE::test000_creation(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab+tab << "Test du constructeur." << std::endl;

	try{
		Annonce pj(QUATRE_VINGT,CARREAU);
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test000_creation : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}
//Assignation
bool T_ANNONCE::test100_objet(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	Annonce pj(QUATRE_VINGT,CARREAU);

	outfile << tab+tab << "Test de la validité de l'objet." << std::endl;


	try{
		if( pj.couleur != CARREAU || pj.hauteur != QUATRE_VINGT )
		{
			std::cout << "ERREUR : problème d'assignation " << std::endl;
			outfile << "test100_objet : " << "ERREUR : problème d'assignation " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test100_objet : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}
//Comparaison
bool T_ANNONCE::test500_comparaison(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	Annonce pj(QUATRE_VINGT,CARREAU);
	Annonce bg(CENT_SOIXANTE_DIX,TREFLE);

	outfile << tab+tab << "Test de la méthode de comparaison." << std::endl;


	try{
		if( (pj > bg) )
		{
			std::cout << "ERREUR : problème avec l'opérateur > " << std::endl;
			outfile << "test500_comparaison : " << "ERREUR : problème avec l'opérateur > " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test500_comparaison : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}
//Classe
bool T_ANNONCE::test_T_ANNONCE(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Annonce" << std::endl;
	outfile.close();
	std::cout << tab << "Test de la classe Annonce" << std::endl;

	//Tests
	bool status = true;
		status &= T_ANNONCE::test000_creation();
		status &= T_ANNONCE::test100_objet();
		status &= T_ANNONCE::test500_comparaison();

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

//Constructeur
bool T_CARTE::test000_creation(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab+tab << "Test du constructeur." << std::endl;

	try{
		Carte tt(ROI,CARREAU);
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test000_creation : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}
//Get_Valeur
bool T_CARTE::test050_getvaleur(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	Carte tt(ROI,CARREAU);

	outfile << tab+tab << "Test de la methode get_valeur()." << std::endl;


	try{
		if(tt.get_valeur() != ROI )
		{
			std::cout << "ERREUR : problème avec la méthode get_valeur() " << std::endl;
			outfile << "test050_getvaleur : " << "ERREUR : problème avec la méthode get_valeur() " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test050_getvaleur : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Get_Couleur
bool T_CARTE::test060_getcouleur(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	Carte tt(ROI,CARREAU);

	outfile << tab+tab << "Test de la methode get_valeur()." << std::endl;


	try{
		if(tt.get_couleur() != CARREAU )
		{
			std::cout << "ERREUR : problème avec la méthode get_couleur() " << std::endl;
			outfile << "test060_getcouleur : " << "ERREUR : problème avec la méthode get_couleur() " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test060_getcouleur : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Assignation
bool T_CARTE::test100_objet(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);
	Carte tt(ROI,CARREAU);

	outfile << tab+tab << "Test de la validité de l'objet." << std::endl;


	try{
		if(tt.get_couleur() != CARREAU || tt.get_valeur() != ROI )
		{
			std::cout << "ERREUR : problème d'assignation " << std::endl;
			outfile << "test100_objet : " << "ERREUR : problème d'assignation " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test100_objet : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Classe
bool T_CARTE::test_T_CARTE(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Carte" << std::endl;
	outfile.close();
	std::cout << tab << "Test de la classe Carte" << std::endl;

	//Tests
	bool status = true;
		status &= T_CARTE::test000_creation();
		status &= T_CARTE::test050_getvaleur();
		status &= T_CARTE::test060_getcouleur();
		status &= T_CARTE::test100_objet();


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
//T_REGLES
/////////////////////////////////////////////////////////////////////////////////////////////////////



//Valeur Carte
bool T_REGLES::test050_valeurcarte(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);


	const Carte valetdecarreau(VALET, CARREAU);
	const Carte nefledecoeur(NEUF, COEUR);

	outfile << tab+tab << "Test de la methode valeur( carte, atout )." << std::endl;

	try{
		if(Regles::valeur(valetdecarreau, CARREAU) != 20 || Regles::valeur(valetdecarreau, TREFLE) != 2  || Regles::valeur(nefledecoeur, COEUR) != 14 || Regles::valeur(nefledecoeur, PIQUE) != 0  )
		{
			std::cout << "ERREUR : problème avec la méthode valeur( carte, atout ) " << std::endl;
			outfile << "test050_valeurcarte : " << "ERREUR : problème avec la méthode valeur( carte, atout ) " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test050_valeurcarte : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Valeur Pli
bool T_REGLES::test060_valeurpli(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);


	Pli plipli;
        Carte valetdecarreau(VALET, CARREAU);
            plipli.push_back(valetdecarreau);
        Carte nefledecoeur(NEUF, COEUR);
            plipli.push_back(nefledecoeur);
        Carte roidecarreau(ROI,CARREAU);
            plipli.push_back(roidecarreau);
        Carte septdecarreau(SEPT,CARREAU);
            plipli.push_back(septdecarreau);


	outfile << tab+tab << "Test de la methode valeur( pli, atout )." << std::endl;


	try{
		if(Regles::valeur(plipli, CARREAU) != 24 || Regles::valeur(plipli, TREFLE) != 6 )
		{
			std::cout << "ERREUR : problème avec la méthode valeur( pli, atout ) " << std::endl;
			outfile << "test060_valeurpli : " << "ERREUR : problème avec la méthode valeur( carte, atout ) " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test060_valeurpli : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Comparer deux cartes
bool T_REGLES::test100_comparer(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);

    Carte valetdecarreau(VALET, CARREAU);
    Carte nefledecoeur(NEUF, COEUR);
    Carte roidecarreau(ROI,CARREAU);
    Carte septdecarreau(SEPT,CARREAU);

	outfile << tab+tab << "Test de la methode egalite( carte, carte)." << std::endl;


	try{
		if(Regles::comparer(valetdecarreau, roidecarreau, CARREAU) != 1 || Regles::comparer(valetdecarreau, roidecarreau, TREFLE) != 0 || Regles::comparer(valetdecarreau, nefledecoeur , TREFLE) != 2 )
		{
            std::cout << "ERREUR : problème avec la méthode comparer( carte, carte , atout ) " << std::endl;
			outfile << "test100_comparer : " << "ERREUR : problème avec la méthode comparer( carte, carte , atout ) " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test100_comparer : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}


//Comparer deux cartes
bool T_REGLES::test150_egalitecarte(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);

    Carte valetdecarreau(VALET, CARREAU);
    Carte roidecarreau(ROI,CARREAU);

	outfile << tab+tab << "Test de la methode egalite( carte, carte )." << std::endl;


	try{
		if(Regles::egalite(valetdecarreau, roidecarreau) != false || Regles::egalite(valetdecarreau, Carte( VALET , CARREAU))  != true )
		{
            std::cout << "ERREUR : problème avec la méthode egalite( carte, carte ) " << std::endl;
			outfile << "test150_egalitecarte : " << "ERREUR : problème avec la méthode egalite( carte, carte ) " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test150_egalitecarte : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//Comparer deux mains
bool T_REGLES::test160_egalitemain(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);

    Main mainjoueur;
    Main mainjoueurdansunautreordre;
    Main mainpluspetite;
    Main maindifferente;

    Carte septdecarreau(SEPT,CARREAU);
            mainjoueur.push_back(septdecarreau);
	Carte neufdecarreau(NEUF,CARREAU);
            mainjoueur.push_back(neufdecarreau);
	Carte roidetrefle(ROI,TREFLE);
			mainjoueur.push_back(roidetrefle);

    mainjoueurdansunautreordre.push_back(neufdecarreau);
    mainjoueurdansunautreordre.push_back(roidetrefle);
    mainjoueurdansunautreordre.push_back(septdecarreau);

    mainpluspetite.push_back(septdecarreau);
    mainpluspetite.push_back(neufdecarreau);

    maindifferente.push_back(Carte(DAME,COEUR));
    maindifferente.push_back(Carte(HUIT,PIQUE));

	outfile << tab+tab << "Test de la methode egalite( main , main )." << std::endl;


	try{

	    bool reponse1 = Regles::egalite(mainjoueur,maindifferente); // doit renvoyer false
	    bool reponse2 = Regles::egalite(mainjoueur,mainjoueurdansunautreordre); // doit renvoyer true
	    bool reponse3 = Regles::egalite(mainjoueur,mainpluspetite); // doit renvoyer false
	    bool bonne_reponse = ~reponse1 && reponse2 && ~reponse3;

		if( bonne_reponse != true )
		{
            std::cout << "ERREUR : problème avec la méthode egalite( main , main ) " << std::endl;
			outfile << "test160_egalitemain : " << "ERREUR : problème avec la méthode egalite( main , main ) " << std::endl;
			result_bool = false;
		}

	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test160_egalitemain : " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}

//REgles de validité
bool T_REGLES::test200_valides(){

    std::string tab ( "    ");
	bool result_bool = true ;
	std::ofstream outfile ("log.txt",std::ios_base::app);


	Pli plipli;
        Carte valetdecarreau(AS, CARREAU);
            plipli.push_back(valetdecarreau);
        Carte nefledecoeur(NEUF, COEUR);
            plipli.push_back(nefledecoeur);
        Carte roidecarreau(ROI,CARREAU);
            plipli.push_back(roidecarreau);

	Main mainjoueur;
    Carte septdecarreau(SEPT,CARREAU);
            mainjoueur.push_back(septdecarreau);
	Carte neufdecarreau(NEUF,CARREAU);
            mainjoueur.push_back(neufdecarreau);
	Carte roidetrefle(ROI,TREFLE);
			mainjoueur.push_back(roidetrefle);

	Main MainvalideCARREAU;
		MainvalideCARREAU.push_back(neufdecarreau);

	Main MainvalidePIQUE;
		MainvalidePIQUE.push_back(septdecarreau);
		MainvalidePIQUE.push_back(neufdecarreau);

	Main MainvalideTREFLE;
		MainvalideTREFLE.push_back(septdecarreau);
		MainvalideTREFLE.push_back(neufdecarreau);
		MainvalideTREFLE.push_back(roidetrefle);


	outfile << tab+tab << "Test de la methode valides( Main, atout, pli )." << std::endl;


	try{
		Main mainsortieCARREAU = Regles::valides(mainjoueur, CARREAU, plipli);
		Main mainsortiePIQUE = Regles::valides(mainjoueur, PIQUE, plipli);
		Main mainsortieTREFLE = Regles::valides(mainjoueur, TREFLE, plipli);
		bool testcarreau = Regles::egalite(mainsortieCARREAU, MainvalideCARREAU);
		bool testpique = Regles::egalite(mainsortiePIQUE, MainvalidePIQUE);
		bool testtrefle = Regles::egalite(mainsortieTREFLE, MainvalideTREFLE);
		if( testcarreau && testpique && testtrefle  )
		{
			std::cout << "ERREUR : problème avec la méthode valides( Main, atout, pli ). " << std::endl;
			outfile << "test200_valides : " << "ERREUR : problème avec la méthode valides( Main, atout, pli ). " << std::endl;
			result_bool = false;
		}
	}
	catch(std::exception const& e){
		std::cerr << "ERREUR : " << e.what() << std::endl;
		outfile << "test200_valides: " << "ERREUR : " << e.what() << std::endl;
		result_bool = false;
	}
	outfile.close();
	return result_bool;

}



//Classe
bool T_REGLES::test_T_REGLES(){

	// Visualisations
	std::string tab ( "    ");
	std::ofstream outfile ("log.txt",std::ios_base::app);
	outfile << tab <<"Test de la classe Regles" << std::endl;
	outfile.close();
	std::cout << tab << "Test de la classe Regles" << std::endl;

	//Tests
	bool status = true;

		status &= T_REGLES::test050_valeurcarte();
		status &= T_REGLES::test060_valeurpli();
		status &= T_REGLES::test100_comparer();
		status &= T_REGLES::test150_egalitecarte();
		status &= T_REGLES::test160_egalitemain();
		//status &= T_REGLES::test200_valides();


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
