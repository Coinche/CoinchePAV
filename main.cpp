#include <iostream>
#include <exception>

#include"types.h"
#include"annonce.h"
#include "debugage.h"
#include "donneur.h"


using namespace std;

int main()
{

    cout << "Initialisation :" << endl;
    bool status = Debugage::debugage();
    cout << "Status : " << status << endl;

	try{
	Doner kebab(new Joueur, new Joueur, new Joueur, new Joueur);
	cout << "init marche" << endl;
	kebab.jouerUnTour();
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		return 1;
	}
    return 0;
}
