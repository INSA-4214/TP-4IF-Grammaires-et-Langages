#include "Affectation.h"

Affectation::~Affectation()
{
    //dtor
}
void Affectation::print(){

	//Cast de e en nombre
	Nombre *n = (Nombre*)e;
	std::cout << m_idVar << " := " <<  n->getValeur() << " ;"<< std::endl;
}
