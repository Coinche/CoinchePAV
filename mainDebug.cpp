#include <iostream>
#include <exception>

#include"types.h"
#include"annonce.h"
#include "debugage.h"
#include "donneur.h"
#include "joueurIA.h"


using namespace std;

int main()
{

    cout << "Initialisation :" << endl;
    bool status = Debugage::debugage();
    cout << "Status : " << status << endl;

	try{
	Doner kebab(new IA_dummy() , new IA_dummy() , new IA_dummy() , new IA_intermediate() );

	//cout << "init marche" << endl;
	//kebab.jouerUnTour();
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
		return 1;
	}

    return 0;
}
