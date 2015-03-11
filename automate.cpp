
using namespace std;

#include <string> 
#include <fstream> 
#include <iostream> 

#include "automate.h"

void Automate::lecture()
{
	ifstream fichier("fichier.lt");
	
	if(fichier)
	{
		string ligne;
		
		while (getline(fichier, ligne))
		{
			cout << ligne << endl;
		}
	}
}

Automate::Automate ( )
{
	
}

Automate::~Automate ( )
{
	
}

