/*
 * Programme.cpp
 *
 *  Created on: 28 mars 2015
 *      Author: Huber
 */

#include "Programme.h"

Programme::~Programme() {
	// TODO Auto-generated destructor stub


}
//*TODO
void Programme::print(){
	blocD->printBlocD();
	blocI->printBlocI();
}

void Programme::exec(){
	blocD->exec();
	blocI->exec();
}
//*/
